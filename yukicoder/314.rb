n = gets.chomp.to_i
MAX = (10 ** 9) + 7
if n == 1
  puts 1
  exit 0
end
dp = [1, 2, 2]
(3..n).each { |i| dp.push((dp[i - 2] + dp[i - 3]) % MAX) }
puts dp[dp.length - 2]
