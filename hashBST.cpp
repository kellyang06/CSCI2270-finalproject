#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "hashBST.hpp"
#include "BST.hpp"

#define TABLESIZE 10009

using namespace std;

HashTable::HashTable(int bsize){

    // allocate table of bsize for BST
    table = new BST[bsize];
    //set current tableSize to 0
    tableSize = 0;
    // set roots of each binary tree to NULL
    for (int i = 0; i < bsize; i ++){
        Node* _root = table[i].getRoot();
        _root = NULL;

    }
}

HashTable::~HashTable(){
    delete[] table; // free up allocated memory using delete
}

bool HashTable::insertItem(int key){
    // first hash function
    int indexOne = hashFunction(key);
    // if there is already a BST pre existing at that index, increase number of collisions
    if (table[indexOne].getRoot() != NULL){
        numOfcollision ++;
    }
    // check if the item is already in the BST using the searchkey from BST implementation
    if (table[indexOne].searchKey(key) == false){
        // if the key isn't there, then add node to the BST using the addnode from BST implementation
        table[indexOne].addNode(key);
        tableSize ++;
        return true;
    } else {
        // otherwise, return and don't do anything
        return false;
    }
}

unsigned int HashTable::hashFunction(int key){
    // define hash function
    return (key % TABLESIZE);
}

void HashTable::printTable(){
    // for loop to traverse through table and display each BST
    // use print tree function from BST implementation
    for (int i = 0; i < TABLESIZE; i ++){
        table[i].printTree();
    }
}

int HashTable::getNumOfCollision(){
    // return number of collisions
    return numOfcollision;
}

Node* HashTable::searchItem(int key){
    // first use hash index function to find which spot in the hash table
    int indexOne = hashFunction(key);
    // if there are multiple items with the same indexOne, then add to the number of collisions
        // check if there is already a tree/root at that index, then numOfCollision ++;
    if (table[indexOne].getRoot() != NULL){
        numOfcollision ++;
    }
    // then use BST implementation to search within the tree for the key
    table[indexOne].searchKey(key);
    return NULL;
}
