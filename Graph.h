//
// Created by Karpatq on 2015-03-22.
//

#ifndef _UNTITLED2_GRAPH_H_
#define _UNTITLED2_GRAPH_H_

#include <vector>
#include "Node.h"
using namespace std;

class Graph {

    vector<Node*> nodes;
    int numberOfNodes;

public:
    int first(int nodeIndex);
    int next(int nodeIndex, int afterWhich);
    Node* vertex(int nodeIndex, int indexOfNeighbor);
    bool createNodeWithValue(int index, int value);
    Node* getNode(int index);
    void neighbourhoodList();


    vector<Node *> const &getNodes() const {
        return nodes;
    }

public:
    int getNumberOfNodes() const {
        return numberOfNodes;
    }

public:
    Graph(int numberOfNodes);
    ~Graph();
};


#endif //_UNTITLED2_GRAPH_H_
