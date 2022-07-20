#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "doubleLL.hpp"

using namespace std;

// doubly linked list

NodeList::NodeList(){
    /* constructor */
    head = NULL; 
}

NodeList::~NodeList(){
    /* deconstructor */
    while (head){
        Node* currNode = head;
        head = head -> next;
        delete currNode;
    }
}

Node* NodeList::searchNode(int key){
    /* search the nodes */
    Node* sPtr = head;
    while (sPtr != nullptr && sPtr -> key != key){
        sPtr = sPtr -> next;
    }
    return sPtr;
}

void NodeList::displayNode(){
    /* display list of nodes */
    Node* current = head;
    if (head == nullptr){
        cout << "nothing in path" << endl;
    } else {
        while (current -> next != nullptr){
            cout << current -> key << " -> ";
            current = current -> next;
        }
        cout << current -> key << " -> NULL" << endl;
    }
}

void NodeList::insertNode(int key){
    /* inserts node at the end */
    Node* currNode = new Node;
    currNode -> key = key;
    currNode -> next = NULL;
    currNode -> prev = NULL;

    // If LL is empty:
    if (head == NULL){
        head = currNode;
        return;
    }
    // If LL not empty:
    else {
        // Traverse entire list
        Node* tempNode = head;
        while (tempNode -> next != NULL){
            tempNode = tempNode -> next;
        }
        // Append to end
        tempNode -> next = currNode;
        currNode -> prev = tempNode;
    }

}
