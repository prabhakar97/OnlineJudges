#include <iostream>
#include <deque>
#include <set>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int> > data;
map<int, int> parent;
set<int> visited;
deque<int> q;
int furthest = 1;

void bfs(int start_node) {
  parent.clear();
  visited.clear();
  q.clear();
  q.push_back(start_node);
  while(!q.empty()) {
    int cur_node = q.front();
    q.pop_front();
    visited.insert(cur_node);
    furthest = cur_node;
    map<int, vector<int> >::iterator iter = data.find(cur_node);
    if(iter != data.end()) {
      for(vector<int>::iterator it = iter->second.begin(); it != iter->second.end(); it++) {
        if(visited.find(*it) != visited.end())
          continue;
        map<int, int>::iterator cur_par = parent.find(cur_node);
        if((cur_par == parent.end()) || (cur_par->second != *it)) {
          parent[*it] = cur_node;
        }   
        q.push_back(*it);
      }
    }
  }
}

int find_path_length(int node) {
  map<int, int>::iterator node_par = parent.find(node);
  if(node_par == parent.end())
    return 0;
  else
    return 1 + find_path_length(node_par->second);
}

int main() {
  int nodes;
  cin>>nodes;
  if(nodes <= 1) {
    cout<<0<<endl;
    return 0;
  }
  int u, v;
  for(int i=0; i<nodes-1; i++) {
    cin>>u>>v;
    map<int, vector<int> >::iterator iter = data.find(u);
    if(iter != data.end())
      iter->second.push_back(v);
    else {
      vector<int> v1;
      v1.push_back(v);
      data[u] = v1;
    }
    iter = data.find(v);
    if(iter != data.end())
      iter->second.push_back(u);
    else {
      vector<int> v2;
      v2.push_back(u);
      data[v] = v2;
    }
  }
  bfs(1);
  bfs(furthest);
  cout<<find_path_length(furthest)<<endl;
  return 0;
}
