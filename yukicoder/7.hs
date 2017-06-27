primes :: Int -> [Int]
primes 2 = [ 2 ]
primes n =  primes (n - 1) ++ isPrime n
  where
    isPrime :: Int -> [Int]
    isPrime 3 = [ 3 ]
    isPrime n
      | even n      = [ ]
      | notPrime n  = [ ]
      | otherwise   = [ n ]
    notPrime :: Int -> Bool
    notPrime n =
      elem 0 . map (mod n) . tail .  primes . floor . sqrt . fromIntegral $ n

slove :: Int -> String
slove n
    | n == 2 = "Win"
    | n == 0 || n == 1 = "Lose"
    | n > 1 = slove $ n - (last $ primes n')
    where
        n' = n - 1

main :: IO()
main = do
    n <- readLn :: IO Int
    putStrLn $ slove n
