solve :: Int -> Int
solve n
    | n == 1 = 1
    | n == 2 = 2
    | n == 3 = 2
    | otherwise = solve(n - 2) + solve(n - 3)

main :: IO()
main = do
    n <- readLn :: IO Int
    putStrLn $ show $ solve n
