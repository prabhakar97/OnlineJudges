#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int>* findIncreasingSequences(vector<int> v) {
  map<int, int> *res = new map<int, int>;
  if(!v.size())
    return NULL;
  if(v.size()==1){
    (*res)[0] = 1;
    return res;
  }
  int length = 1, i;
  for(i=1; i<v.size(); i++) {
    if(i == v.size()-1) {
      if(v[i]>v[i-1])
        (*res)[i] = length+1;
      else {
        (*res)[i-1] = length;
        (*res)[i] = 1;
      }
    }
    else if(v[i]>v[i-1])
      length++;
    else {
      (*res)[i-1] = length;
      length = 1;
    }
  }
  return res;
}
map<int, int>* findDecreasingSequences(vector<int> v) {
  map<int, int> *res = new map<int, int>;
  if(!v.size())
    return NULL;
  if(v.size()==1){
    (*res)[0] = 1;
    return res;
  }
  int length = 1, i;
  for(i=1; i<v.size(); i++) {
    if(i == v.size()-1) {
      if(v[i]<v[i-1])
        (*res)[i] = length+1;
      else {
        (*res)[i-1] = length;
        (*res)[i] = 1;
      }
    }
    else if(v[i]<v[i-1])
      length++;
    else {
      (*res)[i-1] = length;
      length = 1;
    }
  }
  return res;
}

int main() {
  int n, m;
  cin>>n;
  m=n;
  map<int, int> *increasingList;
  map<int, int> *decreasingList;
  vector<int> v;
  int temp;
  while(n--) {
    cin>>temp;
    v.push_back(temp);
  }
  increasingList = findIncreasingSequences(v);
  decreasingList = findDecreasingSequences(v);
  vector<int> candyVector;
  candyVector.resize(m);
  for(map<int, int>::iterator it = (*increasingList).begin(); it != (*increasingList).end(); it++) {
    //cout<<it->first<<" - "<<it->second<<endl;
    if(it->second > 1) {
      int index = it->first;
      for(int i=it->second; i>0; i--) {
        candyVector[index]=i;
        index--;
      }
    }
  }

  for(map<int, int>::iterator it = (*decreasingList).begin(); it != (*decreasingList).end(); it++) {
    //cout<<it->first<<" - "<<it->second<<endl;
    if(it->second > 1) {
      int index = it->first;
      for(int i=1; i<=it->second; i++) {
        if(candyVector[index]>i)
          break;
        candyVector[index]=i;
        index--;
      }
    }
  }
  int result=0;
  for(int i=0; i<candyVector.size(); i++) {
    if(candyVector[i]==0)
      candyVector[i]=1;
    result+=candyVector[i];
    //cout<<candyVector[i]<<" ";
  }
  cout<<result;
  return 0;
}
