require 'set'
require 'thread'

num = gets.to_i
if num <= 1
  puts 0
  abort
end
$data = Hash.new
$parent = Hash.new
$queue = Queue.new
$visited = Set.new

# Get the input
(num-1).times do
  node1, node2 = gets.split(" ").map{ |i| i.to_i }
  if $data[node1] == nil
    $data[node1] = [node2]
  else
    $data[node1] << node2
  end
  if $data[node2] == nil
    $data[node2] = [node1]
  else
    $data[node2] << node1
  end
end

# BFS
def bfs(start_node)
  $queue.clear
  $visited.clear
  $parent.clear
  $queue.push start_node
  until $queue.empty?
    cur_node = $queue.pop
    # next if $visited.include? cur_node
    $visited.add cur_node
    $furthest = cur_node
    unless $data[cur_node].nil?
      $data[cur_node].each do |node|
        next if $visited.include? node
        $parent[node] = cur_node unless $parent[cur_node] == node
        $queue.push node
      end
    end
  end
end

def find_path_length(node)
  if $parent[node] == nil
    return 0
  else
    return 1 + find_path_length($parent[node])
  end
end

# start from node number 1
bfs(1)
# puts "Furthest is #{$furthest}"
# puts "Furthest cur_node is #{$cur_node}"

# Do another BFS and find furthest from here
bfs($furthest)
# puts "Furthest is #{$furthest}"
# puts "Furthest cur_node is #{$cur_node}"

#puts $parent.inspect
#puts $visited.inspect
#puts $data.inspect
#puts "Longest path length is #{find_path_length($furthest)}"
puts find_path_length $furthest
