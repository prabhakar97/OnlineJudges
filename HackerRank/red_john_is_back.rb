# https://www.hackerrank.com/challenges/red-john-is-back
def numways(n, arr)
  return 1 if [0, 1, 2, 3].include?(n)
  return arr[n] if arr[n] != nil
  arr[n] = numways(n-1, arr) + numways(n-4, arr)
end

def bsearch(arr, num)
  i = 0
  j = arr.size - 1
  mid = i+ (j - i)/2
  while arr[mid] != num
    if arr[mid] > num
      j = mid - 1
    else
      i = mid + 1
    end
    mid = i + (j - i)/2
    return i if arr[i] > num
  end
  return mid + 1
end

range = (1..218286).step(2).to_a
limit = Math.sqrt(218286).ceil
i = 1
while range[i] < limit
  (i += 1) && next if range[i] == 0
  for j in i+1..range.size-1
    next if range[j] == 0
    if ((range[j] % range[i]) == 0)
      range[j] = 0
    end
  end
  i += 1
end
range.reject!{|i| (i == 0)}
range[0] = 2
t = gets.chomp.to_i
arr = {}
t.times do
  n = gets.chomp.to_i
  m = numways n, arr
  puts bsearch(range, m)
end
