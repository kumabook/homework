import Data.Monoid
import Control.Monad.Writer

gcd' :: Int -> Int -> Writer [String] Int
gcd' a b
    | b == 0 = do
      tell ["Finished with " ++ show a]
      return a
    | otherwise = do
      tell [show a ++ " mod " ++ show b ++ " = " ++ show (a `mod` b)]
      gcd' b (a `mod` b)

gcdReverse :: Int -> Int -> Writer [String] Int
gcdReverse a b
    | b == 0 = do
      tell ["Finished with " ++ show a]
      return a
    | otherwise = do
      result <- gcdReverse b (a `mod` b)
      tell [show a ++ " mod " ++ show b ++ " = " ++ show (a `mod` b)]
      return result

newtype DiffList a = DiffList { getDiffList :: [a] -> [a] }

toDiffList :: [a] -> DiffList a
toDiffList xs = DiffList (xs++)

fromDiffList :: DiffList a -> [a]
fromDiffList (DiffList f) = f []

instance Monoid (DiffList a) where
    mempty = DiffList (\xs -> [] ++ xs)
    (DiffList f) `mappend` (DiffList g) = DiffList (\xs -> f (g xs))

gcdFast :: Int -> Int -> Writer (DiffList String) Int
gcdFast a b
    | b == 0 = do
      tell (toDiffList ["Finished with " ++ show a])
      return a
    | otherwise = do
      result <- gcdFast b (a `mod` b)
      tell (toDiffList [show a ++ " mod " ++ show b ++
                             " = " ++ show (a `mod` b)])
      return result
