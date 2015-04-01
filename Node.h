//
// Created by Karpatq on 2015-03-22.
//

#ifndef _UNTITLED2_NODE_H_
#define _UNTITLED2_NODE_H_

#include <vector>
#include <iosfwd>

using namespace std;


class Node {

    int value;
    int index;
    vector<Node*> neighbors;

public:
    Node* getIndexOfFirst();
    Node* getIndexOfAfter(int after);
    Node* getNeighbor(int index);
    void changeValue(int value);
    void toString();
    void pushNeighbor(Node *);

    int getValue() const {
        return value;
    }

    int getIndex() const {
        return index;
    }

    void readNeighbors();
    Node(int index);
};


#endif //_UNTITLED2_NODE_H_
