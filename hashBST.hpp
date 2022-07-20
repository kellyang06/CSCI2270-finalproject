#ifndef HASHBST_HPP
#define HASHBST_HPP

#include <string>
#include "BST.hpp"


using namespace std;


class HashTable
{
    int tableSize;  

    // Pointer to an array containing buckets
    BST *table;
    int numOfcollision = 0;

public:
    HashTable(int bsize);  // Constructor
    ~HashTable(); // Deconstructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    Node* searchItem(int key);
};

#endif
