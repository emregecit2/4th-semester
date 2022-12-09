module PE2 where


import Text.Printf

type Point = (Int, Int)
type Dimensions = (Int, Int)
type Vector = (Int, Int)

getRounded :: Double -> Double
getRounded x = read s :: Double
               where s = printf "%.2f" x

castIntToDouble x = (fromIntegral x) :: Double
-------------------------------------------------------------------------------------------
----------------------- DO NOT CHANGE ABOVE OR FUNCTION SIGNATURES-------------------------
------------- DUMMY IMPLEMENTATIONS ARE GIVEN TO PROVIDE A COMPILABLE TEMPLATE ------------
------------------- REPLACE THEM WITH YOUR COMPILABLE IMPLEMENTATIONS ---------------------
-------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------
add :: (Int, Int) -> (Int, Int) -> (Int, Int)
add (x, y) (u, v) = (x+u, y+v)
castBoolToInt x = if x then 1 else 0

isSubstringOf :: [Char] -> [Char] -> Bool
isSubstringOf "" _ = True
isSubstringOf _ "" = False
isSubstringOf small@(smallhead:smallrest) big@(bighead:bigrest) = if smallhead == bighead then isSubstringOf smallrest bigrest else isSubstringOf small bigrest

getVector :: String -> Vector
getVector d = (a, b) where
                        b = castBoolToInt (isSubstringOf "North" d) - castBoolToInt (isSubstringOf "South" d)
                        a = castBoolToInt (isSubstringOf "East" d) - castBoolToInt (isSubstringOf "West" d)
                    


-------------------------------------------------------------------------------------------------------------------------------
getAllVectors :: [String] -> [Vector]
getAllVectors = map getVector

-------------------------------------------------------------------------------------------------------------------------------

producePath :: Point -> [String] -> [Point]
producePath initial [] = [initial]
producePath initial actions = initial : producePath next (tail actions) where next = add initial $ getVector $ head actions

-------------------------------------------------------------------------------------------------------------------------------
takePathInArea :: [Point] -> Dimensions -> [Point]
takePathInArea [] _ = []
takePathInArea (a:arest) (bx, by) | fst a >= bx || snd a >= by || fst a < 0 || snd a < 0 = []
                                  | otherwise = a: takePathInArea arest (bx, by)

-------------------------------------------------------------------------------------------------------------------------------

remainingObjects :: [Point] -> Dimensions -> [Point] -> [Point]
remainingObjects path border objects = filter (\x -> notElem x $ takePathInArea path border) objects

-------------------------------------------------------------------------------------------------------------------------------


averageStepsInSuccess :: [[Point]] -> Dimensions -> [Point] -> Double
averageStepsInSuccess paths border objects = castIntToDouble steps / castIntToDouble(length successfulPaths) where
                                                    successfulPaths = filter (\x -> null(remainingObjects x border objects) && takePathInArea x border == x) paths
                                                    steps = sum $ map length successfulPaths