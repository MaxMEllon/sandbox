n = gets.chomp.to_i
r = (n ** (1/2.0)).to_i
list = []
(1..r).each {|i|
  if n % i == 0
    b = n / i
    list.push(i.to_s << b.to_s)
    list.push(b.to_s << i.to_s)
  end
}
puts list.uniq.size