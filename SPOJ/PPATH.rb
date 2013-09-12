require 'set'
require 'prime'

$prime_set = Prime.each(9999).select{|i| i>1000}.to_set

$visited = Set.new
$set = Set.new
$queue = Queue.new
$parent_of = Hash.new

def generate_candidates(num)
  $set.clear
  4.times do |i|
    num_temp = num.to_s
    (0..9).each do |digit|
      next if (i == 0 and digit == 0)
      num_temp[i] = digit.to_s
      next if $visited.include? num_temp.to_i
      next unless $prime_set.include? num_temp.to_i
      $set.add num_temp.to_i
    end
  end
end

def find_path(i, prime1)
  path = 1
  while $parent_of[i] != prime1
    i = $parent_of[i]
    path += 1
  end
  path
end

def find_ppath(prime1, prime2)
  if prime1 == prime2
    return 0
  else
    $queue.push prime1
    $visited.add prime1
    until $queue.empty? 
      num = $queue.pop
      generate_candidates(num)
      $set.each do |i|
        $visited.add i
        $parent_of[i] = num
        if i == prime2
          return find_path(i, prime1)
        end
        $queue.push i
      end
    end
  end
  "Impossible"
end

num_cases = gets.chomp.to_i

num_cases.times do
  $visited.clear
  $parent_of.clear
  $queue.clear
  prime1, prime2 = gets.split(" ").map{|i| i.to_i}
  puts find_ppath prime1, prime2
end

