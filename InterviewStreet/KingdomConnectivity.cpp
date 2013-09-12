#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <sstream>

using namespace std;

enum colors_t {
  WHITE,
  GRAY,
  BLACK
};

class Node {
  int id_;
  list<Node*> predecessors;
  colors_t color_;
  public:
  Node() {
    color_ = WHITE;
  }
  int getId() {
    return id_;
  }
  void setId(int id) {
    id_ = id;
  }
  list<Node*> getPredecessors() {
    return predecessors;
  }
  void addPredecessor(Node *node) {
    predecessors.push_back(node);
  }
  void setColor(colors_t color) {
    color_ = color;
  }
  bool operator<(const Node &input) {
    return (this->id_ < input.id_);
  }
};

class Edge {
  Node *dest_;
  int weight_;
  public:
  Edge() {
    Edge(NULL);
  }
  Edge(Node *dest) {
    Edge(dest, 1);
  }
  Edge(Node *dest, int weight) {
    dest_ = dest;
    weight_ = weight;
  }
  int getWeight() {
    return weight_;
  }
  Node *getDestNode() {
    return dest_;
  }
  bool operator<(Edge &in) {
    return (this->dest_->getId() < in.dest_->getId());
  }
};

// This graph stores its edges in an adjacency list structure. Each list is sorted and requires log(n) search
class Graph {
  vector< multiset<Edge>* > edgeList;
  vector<Node *> nodeList;
  public:
  void init(int numNodes) {
    edgeList.resize(numNodes);
    nodeList.resize(numNodes);
    for(int i=0; i<numNodes; i++) {
      edgeList.push_back(new multiset<Edge>);
      Node *node = new Node;
      node->setId(i);
      nodeList.push_back(node);
    }
  }
  void addEdge(int source, int dest) {
    Edge edge(nodeList.at(dest-1));
    edgeList.at(source-1)->insert(edge);
  }
};

string solve(Graph *g, int source, int dest) {
  return NULL;
}

int main() {
  return 0;
}
