h, m = gets.chomp.split(':').map(&:to_i)
m += 5
if m >= 60
  m %= 60
  h += 1
end
if h >= 24
  h %= 24
  h = 0
end

printf "%02d:%02d", h, m
