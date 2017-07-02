n = gets.chomp.to_i
arr = []
(0...n).each do
  arr.push gets.chomp
end

class Symbol
  def call(*a,&b)
    proc {|m| m.send(self, *a, &b) }
  end
end

arr.map!(&:split.(''))

g_memo = {}
p_memo = {}

def create_memo_of_humming(str, line, start)
  r = []
  str.split('').each_with_index do |c, i|
    r.push line[start + i] == c
  end
  r
end

def create_memo(str, line)
  memo = {}
  line.each_with_index do |_, j|
    break if line.length - str.length < j
    r = create_memo_of_humming(str, line, j)
    memo[j] = { memo: r, start: j }
  end
  memo
end

arr.each_with_index do |line, i|
  g_memo[i] = {}
  p_memo[i] = {}
  g_memo[i] = create_memo('good', line)
  p_memo[i] = create_memo('problem', line)

  min = 0xFFFFFFF
  g_memo[i].each do |gkv|
    gc = 4 - gkv[1][:memo].count(true)
    ge = gkv[1][:start] + 3
    p_memo[i].each do |pkv|
      pc = 7 - pkv[1][:memo].count(true)
      pi = pkv[1][:start]
      min = gc + pc if (ge < pi) && (min > gc + pc)
    end
  end
  puts min
end
