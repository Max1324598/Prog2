#include "graph.h"
#include <iostream>



Graph::Graph(int row, int col)
    : adjacencyList{}, nodeVector{}
{
    nodeVector.resize(row);
    for (int i{}; i<row; i++){
        nodeVector.at(i).resize(col);
    }
}

Graph::~Graph()
{
    for(int i{}; i<nodeVector.size();i++){
        for (int j{}; j<nodeVector.at(i).size();j++){
            delete nodeVector.at(i).at(j);
        }
    }
    nodeVector.clear();

    auto it = adjacencyList.begin();
    while (it != adjacencyList.end()){
        adjacencyList.erase(it);
        it++;
    }
}

void Graph::addNode(Node* node)
{
    nodeVector.at(node->row).at(node->col) = node;
    std::list<Edge*> tempList;
    adjacencyList[node] = tempList;
}

void Graph::addEdge(Edge *edge)
{
    adjacencyList[edge->from].push_back(edge);
}

std::vector<Node *> Graph::getConnections(Node *node)
{
    std::vector<Node*> connections;
    auto it = adjacencyList[node].begin();
    for(int i{}; i<adjacencyList[node].size();i++){
        Edge* currentEdge = *it;
        connections.push_back(currentEdge->to);
        it++;
    }
    return connections;
}
const std::vector<std::vector<Node *> > &Graph::getNodeVector() const
{
    return nodeVector;
}

const std::unordered_map<Node *, std::list<Edge *> > &Graph::getAdjacencyList() const
{
    return adjacencyList;
}

