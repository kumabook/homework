multThree :: Int -> Int -> Int -> Int
multThree x y z = x * y * z

compareWithHundred :: Int -> Ordering
compareWithHundred x = compare 100 x

divideByTen :: (Floating a) => a -> a
divideByTen = (/10)

isUpperAlphanu :: Char -> Bool
isUpperAlphanu = (`elem` ['A'..'Z'])

applyTwice :: (a -> a) -> a -> a
applyTwice f x = f (f x)

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith f (x:xs) (y:ys) = f x y : zipWith' f xs ys

flip' :: (a -> b -> c) -> b-> a -> c
flip' f y x = f x y

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' p (x:xs)
    | p x = x : filter p xs
    | otherwise = filter p xs

largestDivisible :: Integer
largestDivisible = head (filter p [100000, 99999 ..])
    where p x = x `mod` 3829 == 0

chain :: Integer -> [Integer]
chain 1 = [1]
chain n
      | even n = n : chain (n `div` 2)
      | odd n = n : chain (n * 3 + 1)


numLongChains :: Int
numLongChains = length (filter (\xs -> length xs > 15)
                               (map chain [1..100]))

sum' :: (Num a) => [a] -> a
sum'= foldl (+) 0

map' :: (a -> b) -> [a] -> [b]
map' f xs = foldr (\x acc -> f x : acc) [] xs

elem' :: (Eq a) => a -> [a] -> Bool
elem' y ys = foldr (\x acc -> if x == y then True else acc) False ys

maximum' :: (Ord a) => [a] -> a
maximum' = foldl1 max

reverse' :: [a] -> [a]
reverse' = foldl (flip (:))  []

product' :: (Num a) => [a] -> a
product' = foldl (*) 1

--filter' :: (a -> Bool) -> [a] -> [a]
--filter' p = foldr (\x acc -> if p x then x : acc else acc) []

last' :: [a] -> a
last' = foldl1 (\_ x -> x)

and' :: [Bool] -> Bool
and' xs = foldr (&&) True xs

sqrtSums :: Int
sqrtSums = length (takeWhile (< 1000) (scanl1 (+) (map sqrt [1..]))) + 1
