import Control.Monad.Writer
import Data.DList

finalCountDown :: Int -> Writer (DList String) ()
finalCountDown 0 = do
  tell (fromList ["0"])
finalCountDown x = do
  finalCountDown (x-1)
  tell (fromList [show x])

finalCountDownWithList :: Int -> Writer [String] ()
finalCountDownWithList 0 = do
  tell ["0"]
finalCountDownWithList x = do
  finalCountDownWithList (x-1)
  tell [show x]
