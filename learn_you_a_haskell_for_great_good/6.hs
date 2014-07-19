import Data.List
import Data.Char
import qualified Data.Map as Map;

numUniques :: (Eq a) => [a] -> Int
numUniques = length . nub

wordNums :: String -> [(String, Int)]
wordNums = map (\ws -> (head ws, length ws)) . group . sort . words

isIn :: (Eq a) => [a] -> [a] -> Bool
needle `isIn` haystack = any (needle `isPrefixOf`) (tails haystack)

encode :: Int -> String -> String
encode offset msg = map (\c -> chr $ ord c + offset) msg

decode :: Int -> String -> String
decode shift msg = encode (negate shift) msg

phoneBook:: Map.Map String String
phoneBook = Map.fromList $
            [("betty", "555-2938"),
             ("bonnie", "452-2928"),
             ("patsy",  "493-2928"),
             ("lucille", "205-2928"),
             ("wendy", "939-8282"),
             ("penny", "853-2492")]
string2digits :: String -> [Int]
string2digits = map digitToInt . filter isDigit

phoneBookToMap :: (Ord k) => [(k, String)] -> Map.Map k String
phoneBookToMap xs = Map.fromListWith add xs
    where add number1 number2 = number1 ++ ", " ++ number2
