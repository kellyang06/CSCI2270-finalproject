#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;


class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    int *table;
    int numOfcollision = 0;

public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    // hash function for double hashing
    unsigned int hashFunctionDH(int key);

    void printTable();
    int getNumOfCollision();

    int searchItem(int key);
};

#endif
