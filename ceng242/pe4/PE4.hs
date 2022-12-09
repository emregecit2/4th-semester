module PE4 where

import Data.List
import Data.Maybe

data Room = SeedStorage Int
          | Nursery Int Int
          | QueensChambers
          | Tunnel
          | Empty
          deriving Show

data Nestree = Nestree Room [Nestree] deriving Show

---------------------------------------------------------------------------------------------
------------------------- DO NOT CHANGE ABOVE OR FUNCTION SIGNATURES-------------------------
--------------- DUMMY IMPLEMENTATIONS ARE GIVEN TO PROVIDE A COMPILABLE TEMPLATE ------------
--------------------- REPLACE THEM WITH YOUR COMPILABLE IMPLEMENTATIONS ---------------------
---------------------------------------------------------------------------------------------

-- Note: undefined is a value that causes an error when evaluated. Replace it with
-- a viable definition! Name your arguments as you like by changing the holes: _

---------------------------------------------------------------------------------------------

-- Q1: Calculate the nutrition value of a given nest.

nestNutritionValue :: Nestree -> Int
nestNutritionValue n = case n of Nestree Tunnel nt -> foldr ((+) . nestNutritionValue) 0 nt
                                 Nestree Empty nt -> foldr ((+) . nestNutritionValue) 0 nt
                                 Nestree (SeedStorage n) nt -> 3 * n + foldr ((+) . nestNutritionValue) 0 nt
                                 Nestree (Nursery n1 n2) nt -> 7 * n1 + 10 * n2 + foldr ((+) . nestNutritionValue) 0 nt
                                 Nestree QueensChambers nt -> foldr ((+) . nestNutritionValue) 0 nt

-- Q2: Calculate the nutrition value of each root-to-leaf path.

pathNutritionValues :: Nestree -> [Int]
pathNutritionValues n = case n of Nestree Tunnel nt -> pathNutritionValuesHelper nt
                                  Nestree Empty nt -> pathNutritionValuesHelper nt
                                  Nestree (SeedStorage n) nt -> add (pathNutritionValuesHelper nt) (3 * n)
                                  Nestree (Nursery n1 n2) nt -> add (pathNutritionValuesHelper nt) (7 * n1 + 10 * n2)
                                  Nestree QueensChambers nt -> pathNutritionValuesHelper nt
                        where pathNutritionValuesHelper :: Foldable t => t Nestree -> [Int]
                              pathNutritionValuesHelper nt = if null ret_list then [0] else ret_list where ret_list = concatMap pathNutritionValues nt
                              add :: [Int] -> Int -> [Int]
                              add [] _ = []
                              add (x:xs) n = x + n : add xs n




-- Q3: Find the depth of the shallowest tunnel, if you can find one.

shallowestTunnel :: Nestree -> Maybe Int
shallowestTunnel n = case n of Nestree Tunnel nt -> Just 1
                               Nestree Empty nt -> if null nt then Nothing else let f = maybeMinimum (map shallowestTunnel nt)
                                                in if isNothing f then Nothing  else Just(fromMaybe 0 f + 1)
                               Nestree (SeedStorage n) nt -> if null nt then Nothing else let f = maybeMinimum (map shallowestTunnel nt)
                                                in if isNothing f then Nothing  else Just(fromMaybe 0 f + 1)
                               Nestree (Nursery n1 n2) nt -> if null nt then Nothing else let f = maybeMinimum (map shallowestTunnel nt)
                                                in if isNothing f then Nothing  else Just(fromMaybe 0 f + 1)
                               Nestree QueensChambers nt -> if null nt then Nothing else let f = maybeMinimum (map shallowestTunnel nt)
                                               in if isNothing f then Nothing  else Just(fromMaybe 0 f + 1)
                        where maybeMin :: Maybe Int -> Maybe Int -> Maybe Int
                              maybeMin Nothing Nothing  = Nothing
                              maybeMin x Nothing = x
                              maybeMin Nothing x = x
                              maybeMin x y = min x y
                              maybeMinimum :: [Maybe Int] -> Maybe Int
                              maybeMinimum (x:xs) = foldr maybeMin x xs

-- Q4: Find the path to the Queen's Chambers, if such a room exists.



pathToQueen :: Nestree -> Maybe [Room]
pathToQueen n = case n of (Nestree Empty nt) -> if null ret then Nothing else Just(Empty:fromMaybe [] ret)
                            where ret = pathToQueenHelper (map pathToQueen nt)
                          (Nestree QueensChambers nt) -> Just []
                          (Nestree Tunnel nt) -> if null ret then Nothing else Just(Tunnel:fromMaybe [] ret)
                            where ret = pathToQueenHelper (map pathToQueen nt)
                          (Nestree (SeedStorage n) nt) -> if null ret then Nothing else Just(SeedStorage n:fromMaybe [] ret)
                            where ret = pathToQueenHelper (map pathToQueen nt)
                          (Nestree (Nursery n1 n2) nt) -> if null ret then Nothing else Just(Nursery n1 n2:fromMaybe [] ret)
                            where ret = pathToQueenHelper (map pathToQueen nt)
                where pathToQueenHelper :: [Maybe [Room]] -> Maybe [Room]
                      pathToQueenHelper (x:xs) = if isNothing x then pathToQueenHelper xs else x
                      pathToQueenHelper [] = Nothing


-- Q5: Find the quickest depth to the Queen's Chambers, including tunnel-portation :)
quickQueenDepth :: Nestree -> Maybe Int
quickQueenDepth n = case ret_path of Nothing -> Nothing
                                     Just path -> case deepestTunnel path of Nothing -> Just(1 + length path)
                                                                             Just p -> Just(1 + fromMaybe 0 depth + length path - fromMaybe 0 (deepestTunnel path))

                    where deepestTunnel :: [Room] -> Maybe Int
                          deepestTunnel [] = Nothing 
                          deepestTunnel (x:xs) = case deepestTunnel xs of Nothing -> case x of Tunnel -> Just 1
                                                                                               _ -> Nothing
                                                                          Just d -> Just(d + 1)
                          ret_path = pathToQueen n
                          depth = shallowestTunnel n

-- Example nest given in the PDF.
exampleNest :: Nestree
exampleNest =
  Nestree Tunnel [
    Nestree (SeedStorage 15) [
      Nestree (SeedStorage 81) []
    ],
    Nestree (Nursery 8 16) [
      Nestree Tunnel [
        Nestree QueensChambers [
          Nestree (Nursery 25 2) []
        ]
      ]
    ],
    Nestree Tunnel [
      Nestree Empty [],
      Nestree (SeedStorage 6) [
        Nestree Empty [],
        Nestree Empty []
      ]
    ]
  ]


-- Same example tree, with tunnels replaced by Empty
exampleNestNoTunnel :: Nestree
exampleNestNoTunnel =
  Nestree Empty [
    Nestree (SeedStorage 15) [
      Nestree (SeedStorage 81) []
    ],
    Nestree (Nursery 8 16) [
      Nestree Empty [
        Nestree QueensChambers [
          Nestree (Nursery 25 2) []
        ]
      ]
    ],
    Nestree Empty [
      Nestree Empty [],
      Nestree (SeedStorage 6) [
        Nestree Empty [],
        Nestree Empty []
      ]
    ]
  ]