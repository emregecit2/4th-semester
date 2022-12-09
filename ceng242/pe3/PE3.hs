{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
module PE3 where
-- can use these if you want to...
import Data.List
import Data.Maybe

data Private = Private { idNumber :: Int, height :: Int, timeToSwap :: Int } deriving Show

data Cell = Empty | Full Private deriving Show

type Area = [[Cell]]

---------------------------------------------------------------------------------------------
------------------------- DO NOT CHANGE ABOVE OR FUNCTION SIGNATURES-------------------------
--------------- DUMMY IMPLEMENTATIONS ARE GIVEN TO PROVIDE A COMPILABLE TEMPLATE ------------
--------------------- REPLACE THEM WITH YOUR COMPILABLE IMPLEMENTATIONS ---------------------
---------------------------------------------------------------------------------------------


-- Note: undefined is a value that causes an error when evaluated. Replace it with
-- a viable definition! Name your arguments as you like by changing the holes: _


--------------------------
-- Part I: Warming up with Abstractions

-- bubbleHumans: Applying a parallel bubble step on integers.
bubbleHumans :: [Int] -> [Int]
bubbleHumans humans | length humans <= 1 = humans
                    | head humans < humans!!1 = humans!!1:head humans:bubbleHumans (drop 2 humans)
                    | otherwise = head humans : bubbleHumans (tail humans)

-- bubblePrivates: The same thing, but on privates with a key function and an asc/desc option.

bubblePrivates :: (Private -> Int) -> Bool -> [Private] -> [Private]
bubblePrivates key descending privates | length privates <= 1 = privates
                                       | descending && key(privates!!0) < key(privates!!1) = privates!!1:head privates:bubblePrivates key descending (drop 2 privates)
                                       | not descending && key(privates!!0) > key(privates!!1) = privates!!1:head privates:bubblePrivates key descending (drop 2 privates)
                                       | otherwise = head privates : bubblePrivates key descending (tail privates)

-- sortPrivatesByHeight: Full sort via multiple bubble steps, calculate the sorting time too!
sortTime :: [Private] -> Int
sortTime privates | length privates <= 1 = 0
                  | height(head privates) < height(privates!!1) = foldr max 0 [timeToSwap (head privates), timeToSwap (privates!!1), sortTime (drop 2 privates)]
                  | otherwise = sortTime (tail privates)



sortPrivatesByHeight :: [Private] -> ([Private], Int)
sortPrivatesByHeight privates | ret_time == 0 = (ret_privates, ret_time)
                              | otherwise = let (rec_privates, rec_time) = sortPrivatesByHeight ret_privates
                                            in (rec_privates, rec_time + ret_time)

                              where ret_privates = bubblePrivates height True privates
                                    ret_time = sortTime privates
--------------------------
-- Part II: Squeezing your Brain Muscles

-- ceremonialFormation: Sorting again, but with multiple files. Don't forget the time!

cellHeigth :: Cell -> Int
cellHeigth Empty = 0
cellHeigth (Full private) = height private


sortLine :: [Cell] -> [Cell]
sortLine line | length line <= 1 = line
              | cellHeigth (head line) < cellHeigth (line!!1) = line!!1 : head line : sortLine (drop 2 line)
              | otherwise = head line : sortLine (tail line)

cellTime :: Cell -> Int
cellTime Empty = 0
cellTime (Full private) = timeToSwap private


sortLineTime :: [Cell] -> Int
sortLineTime line | length line <= 1 = 0
                  | cellHeigth (head line) < cellHeigth (line!!1) = foldr max 0 [cellTime (head line), cellTime (line!!1), sortLineTime (drop 2 line)]
                  | otherwise = sortLineTime (tail line)


ceremonialFormation :: Area -> (Area, Int)
ceremonialFormation area = (ret_area, foldr max 0 ret_time)
                           where (ret_area, ret_time) = ceremonialFormationHelper area

ceremonialFormationHelper :: [[Cell]] -> ([[Cell]], [Int])
ceremonialFormationHelper area | all (== 0) ret_time = (ret_area, ret_time)
                               | otherwise = let (rec_area, rec_time) = ceremonialFormationHelper ret_area
                                             in (rec_area, zipWith (+) rec_time ret_time)
                               where ret_area = map sortLine area
                                     ret_time = map sortLineTime area

-- swapPrivates: Swap two arbitrary privates by ID if they are in the area. Big ouch!

cellId :: Cell -> Maybe Int
cellId Empty = Nothing
cellId (Full private) = Just (idNumber private)


findX :: [Cell] -> Int -> Maybe Int
findX [] _ = Nothing
findX (cell:cells) id = case cellId cell of
                        Nothing -> case findX cells id of
                                    Nothing -> Nothing
                                    Just x -> Just (x + 1)
                        Just j ->  if j == id then Just 0 else
                                   case findX cells id of
                                    Nothing -> Nothing
                                    Just i -> Just (i + 1)

findC :: Area -> Int -> Maybe (Int, Int)
findC [] _ = Nothing
findC (line:lines) id = case findX line id of
                        Nothing -> case findC lines id of Nothing -> Nothing
                                                          Just (i, j) -> Just (i + 1, j)
                        Just x -> Just (0, x)


swapPrivates :: Int -> Int -> Area -> Area
swapPrivates id1 id2 area = let c1 = findC area id1
                                c2 = findC area id2
                                in case (c1, c2) of
                                    (Nothing, _) -> area
                                    (_, Nothing) -> area
                                    (Just (i1, j1), Just (i2, j2)) -> let swap i1 j1 i2 j2 | i1 == i2 = take i1 area ++ [swapSameLine line1 j1 j2] ++ drop (i1 +1) area
                                                                                           | i1 < i2 = take i1 area ++ [take j1 line1 ++ [area!!i2!!j2] ++ drop (j1 + 1) line1] ++ drop (i1 + 1) (take i2 area) ++ [take j2 line2 ++ [area!!i1!!j1] ++ drop (j2 + 1) line2] ++ drop (i2 + 1) area
                                                                                           | i1 > i2 = take i2 area ++ [take j2 line2 ++ [area!!i1!!j1] ++ drop (j2 + 1) line2] ++ drop (i2 + 1) (take i1 area) ++ [take j1 line1 ++ [area!!i2!!j2] ++ drop (j1 + 1) line1] ++ drop (i1 + 1) area
                                                                                           where line1 = area!!i1
                                                                                                 line2 = area!!i2
                                                                                                 swapSameLine :: [Cell] -> Int -> Int -> [Cell]
                                                                                                 swapSameLine line j1 j2 | j1 < j2 = take j1 line ++ [line!!j2] ++ drop (j1 + 1) (take j2 line) ++ [line!!j1] ++ drop (j2 + 1) line
                                                                                                                         | otherwise = take j2 line ++ [line!!j1] ++ drop (j2 + 1) (take j1 line) ++ [line!!j2] ++ drop (j1 + 1) line
                                                                      in swap i1 j1 i2 j2

