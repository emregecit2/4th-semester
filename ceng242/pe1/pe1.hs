module PE1 where

import Text.Printf
import Data.List

-- Type synonyms --
type Point = (Double, Double)
type Signal = (Double, Double, Double, Double)

-- This function takes a Double and rounds it to 2 decimal places as requested in the PE --
getRounded :: Double -> Double
getRounded x = read s :: Double
               where s = printf "%.2f" x

-------------------------------------------------------------------------------------------
----------------------- DO NOT CHANGE ABOVE OR FUNCTION SIGNATURES-------------------------
------------- DUMMY IMPLEMENTATIONS ARE GIVEN TO PROVIDE A COMPILABLE TEMPLATE ------------
------------------- REPLACE THEM WITH YOUR COMPILABLE IMPLEMENTATIONS ---------------------
-------------------------------------------------------------------------------------------

getDistance :: Point -> Point -> Double
getDistance (x1, y1) (x2, y2) = getRounded(sqrt((x1 - x2)^2 + (y1 - y2)^2))

-------------------------------------------------------------------------------------------

findAllDistances :: Point -> [Point] -> [Double]
findAllDistances b l =  map (getDistance b) l

-------------------------------------------------------------------------------------------
fin :: [Double] -> Double -> Int
fin l i = if i == head l then 0 else 1 + fin (tail l) i
findExtremes :: Point -> [Point] -> (Point, Point)
findExtremes b l = (l!!(fin distances (minimum distances)), l!!(fin distances (maximum distances)))
    where distances = findAllDistances b l
-------------------------------------------------------------------------------------------

perpendicular (north, _, south, _) | north == south = ""
                                   | north > south = "North"
                                   | south > north = "South"
horizontal (_, east, _, west) | east == west = ""
                              | east > west = "East"
                              | west > east = "West"
getSingleAction :: Signal -> String
getSingleAction signal = if result == "" then "Stay" else result
    where result = perpendicular signal ++ horizontal signal


-------------------------------------------------------------------------------------------

getAllActions :: [Signal] -> [String]
getAllActions signals = map getSingleAction signals

-------------------------------------------------------------------------------------------

numberOfGivenAction :: Num a => [Signal] -> String -> a
numberOfGivenAction signals action = fromIntegral(length (filter (==action) (getAllActions signals)))