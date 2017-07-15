a, b = gets.chomp.split.map(&:to_i)

if (a % 3).zero? || (b % 3).zero? || ((a + b) % 3).zero?
  puts 'Possible'
else
  puts 'Impossible'
end
