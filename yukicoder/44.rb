n = gets.chomp.to_i
dp = [1, 2, 3]
if n <= 3
  puts dp[n - 1]if n <= 3
  exit 0
end
(3...n).each { |i| dp.push(dp[i  - 2] + dp[i - 1]) }
puts dp[dp.length - 1]
