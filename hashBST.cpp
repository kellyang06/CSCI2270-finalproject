#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "hashBST.hpp"
#include "BST.hpp"

#define TABLESIZE 10009

using namespace std;

HashTable::HashTable(int bsize){
    /////////////////////-------------///////////////////
    /*for (int i = 0; i < bsize; i ++){
        table[i] = new BST;
        table[i].getRoot() = NULL;
    }*/


    // allocate table of bsize for BST
    table = new BST[bsize];
    //set current tableSize to 0
    tableSize = 0;
    // set roots of each binary tree to NULL
    // ?????????????????????
    /*for (int i = 0; i < bsize; i ++){
        table[i] = -1;
    }*/
}

bool HashTable::insertItem(int key){
    // first hash function
    // use binary tree at that index and create item to insert into BST
    // if there is no BST at that index, then make the new item the root
        // increase the table size
            // increase number of collisions because a second item hashed to the same place
    // check if the item is already in the BST using the searchkey from BST implementation
        // if the key isn't there, then add node to the BST using the addnode from BST implementation
        // otherwise, return and don't do anything
    int indexOne = hashFunction(key);
    if (table[indexOne].getRoot() != NULL){
        numOfcollision ++;
    }
    if (table[indexOne].searchKey(key) == false){
        table[indexOne].addNode(key);
        tableSize ++;
        return true;
    } else {
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

// finish constructor
// get num of collisions
    // check if a BST is already preexisting somehow
// test code
