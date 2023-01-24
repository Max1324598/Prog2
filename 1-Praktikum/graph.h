#ifndef GRAPH_H
#define GRAPH_H


#include "tile.h"
#include <list>
#include <vector>
#include "unordered_map"


struct Node {
    Tile* tile;
    int row;
    int col;
    int distance;
    Node* parent;
    bool isSearched;
};

struct Edge {

    Node *from;
    Node *to;
};

class Graph

{
public:
    Graph(int row, int col);
    ~Graph();
    void addNode(Node* node);
    void addEdge(Edge* edge);
    void print();
    std::vector<Node*> getConnections (Node* node);

    const std::vector<std::vector<Node *> > &getNodeVector() const;

    const std::unordered_map<Node *, std::list<Edge *> > &getAdjacencyList() const;

private:
    std::unordered_map <Node*, std::list<Edge*> > adjacencyList;
    std::vector<std::vector<Node*>> nodeVector;

};

#endif // GRAPH_H
