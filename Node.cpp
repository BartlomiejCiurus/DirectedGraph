//
// Created by Karpatq on 2015-03-22.
//

#include "Node.h"
#include <iostream>

using namespace std;


void Node::changeValue(int value) {
    this->value = value;

}

Node::Node(int index) {
    this->value = 0;
    this->index = index;
}

void Node::readNeighbors() {
    for (int i = 0; i < neighbors.size(); ++i) {
        cout << " " ;
        neighbors.at(i)->toString();
    }
}


void Node::toString() {
    cout << "index(" << getIndex() << "), " << "value(" << getValue() << ")";
}

void Node::pushNeighbor(Node *node) {
    neighbors.push_back(node);
}

Node* Node::getIndexOfFirst() {
    if(neighbors.size() < 1)
        return nullptr;
    return neighbors.at(0);
}

Node* Node::getIndexOfAfter(int after) {
    if(after < 0 || after > neighbors.size())
        return nullptr;
    return neighbors.at(after+1);
}

Node *Node::getNeighbor(int index) {
    if(index < 0 || index > neighbors.size())
        return nullptr;
    for (int i = 0; i < neighbors.size(); ++i) {
        if(index == neighbors.at(i)->getIndex())
            return neighbors.at(i);
    }
        return nullptr;
}
