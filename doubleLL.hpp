#ifndef DOUBLELL_HPP
#define DOUBLELL_HPP
#include <iostream>

using namespace std;

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
    Node* getHead();
    void insertNode(int key);
    Node* searchNode(int key);
    void displayNode();
};

#endif
