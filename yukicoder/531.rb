n, m = gets.chomp.split.map(&:to_i)
if n <= m
  puts 1
elsif n % 2 == 1
  puts -1
elsif m >= n / 2
  puts n / (n / 2)
else
  puts -1
end
