#ifndef DOUBLELL_HPP
#define DOUBLELL_HPP
#include <iostream>

using namespace std;

/* doubly linked list hpp file */

struct Node {
    int key;
    Node* next;
    Node* prev;
};

class NodeList {
private:
    Node* head;
public:
    NodeList();
    ~NodeList();
    void insertNode(int key);
    Node* searchNode(int key);
    void displayNode();
};

#endif
