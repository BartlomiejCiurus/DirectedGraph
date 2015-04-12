//
// Created by Karpatq on 2015-03-22.
//

#include <iostream>
#include "Graph.h"
using namespace std;


int Graph::first(int nodeIndex) {
    if(nodeIndex < 0 || nodeIndex > nodes.size())
        return -1;
    return nodes.at(nodeIndex)->getIndexOfFirst()->getIndex();
}

int Graph::next(int nodeIndex, int afterWhich) {
    if(nodeIndex < 0 || nodeIndex > nodes.size()-2)
        return -1;
    if(nodes.at(nodeIndex)->getIndexOfAfter(afterWhich) != nullptr)
        return nodes.at(nodeIndex)->getIndexOfAfter(afterWhich)->getIndex();
    else
        return -1;
}

Node *Graph::vertex(int nodeIndex, int indexOfNeighbor) {
    if(nodeIndex < 0 || nodeIndex > nodes.size())
        return nullptr;
    return nodes.at(nodeIndex)->getNeighbor(indexOfNeighbor);
}

Graph::Graph(int numberOfNodes) {
    this->numberOfNodes = numberOfNodes;
    for (int i = 0; i < numberOfNodes; ++i) {
        nodes.push_back(new Node(i));
    }
}
bool Graph::createNodeWithValue(int index, int value) {
    if(index >= 0 && index < nodes.size()) {
        nodes.at(index)->changeValue(value);
        return true;
    }
    return false;
}

Node *Graph::getNode(int index) {
    if(index >= 0 && index < nodes.size()) {
        return nodes.at(index);
    }
    return nullptr;
}

Graph::~Graph() {
    for (int i = 0; i < nodes.size(); ++i) {
        delete nodes.at(i);
    }
}

void Graph::neighbourhoodList() {
    for (int i = 0; i < nodes.size(); ++i) {
        nodes.at(i)->toString();
        cout << " ->";
        nodes.at(i)->readNeighbors();
        cout << endl;
    }
}

