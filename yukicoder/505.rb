gets
arr = gets.chomp.split.map(&:to_i)

dp = {}
dp[0] = []
dp[0][0] = dp[0][1] = arr[0]

def calc_min_and_max(arr, cur)
  r = []
  c = 0
  0.upto(1) do |i|
    r[c] = arr[i] + cur
    c += 1
    r[c] = arr[i] - cur
    c += 1
    r[c] = arr[i] * cur
    c += 1
    if cur != 0
      r[c] = (arr[i] / (cur + 0.0)).ceil
      c += 1
    end
  end
  [r.min, r.max]
end

1.upto(arr.length - 1) do |i|
  dp[i] = {}
  dp[i] = calc_min_and_max(dp[i - 1], arr[i])
end

puts dp[arr.size - 1].max
