n = gets.chomp
flags = n.split('').map { |i| i == '7' }.reverse
start = 0
flags.each_with_index { |f, i| start += 10**i if f == true }
printf("%d %d\n", start, n.to_i - start)
