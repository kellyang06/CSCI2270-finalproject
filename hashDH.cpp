#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "hashDH.hpp"

#define TABLESIZE 10009

using namespace std;

HashTable::HashTable(int bsize){
    // allocate table of bsize
    table = new int[bsize];
    //set current tableSize to 0
    tableSize = 0;
    // set elements in table to -1, meaning there's nothing there
    for (int i = 0; i < bsize; i ++){
        table[i] = -1;
    }
}

bool HashTable::insertItem(int key){
    int i = 1;

    // first hash function
    int oneIndex = hashFunction(key);
    if (table[oneIndex] == -1){
        // if there's no collision, set key to the index
        table[oneIndex] = key;
    } else {
        // otherwise, if that spot is taken and there's a collision, then...
        // use second hash function to resolve collision
        int twoIndex = hashFunctionDH(key);
        //combined hashing for a key x at i-th probe
        for (int k = 0; k < TABLESIZE; k ++){
            // double_hashing(x) = (h(x) + i x h2(x)) % m
            int doubleHashing = (oneIndex + (i * twoIndex)) % TABLESIZE;
            // check that doubleHashing is in table bounds
            // if not, use circular array
            if (doubleHashing >= TABLESIZE){
                doubleHashing = doubleHashing % TABLESIZE;
            }
            // if the spot is empty, then set the index equal to it
            if (table[doubleHashing] == -1){
                table[doubleHashing] = key;
                break;
            }
            i ++;
            return true; 
        }
        numOfcollision ++;
    }
    tableSize ++;
    return false;
}


unsigned int HashTable::hashFunction(int key){
    // define hash function
    return (key % TABLESIZE);
}

unsigned int HashTable::hashFunctionDH(int key){
    // secondary hash function to resolve collisions
    // use h2(x) = R - (x % R), where R is a prime number below 10000
    return (7253) - (key % 7253);
}

void HashTable::printTable(){
    // loop through table and print contents
    for (int i = 0; i < TABLESIZE; i ++){
        cout << i << " || " << table[i] << endl;
    }
}

int HashTable::getNumOfCollision(){
    // return number of collisions
    return numOfcollision;
}

int HashTable::searchItem(int key){
    // first calculate the hash value for the search key to determine index 
    int indexOne = hashFunction(key);
    // determine how much the index is incremented by
    int indexIncrement = hashFunctionDH(key);
    // traverse through until key is found
    while (table[indexOne] != -1){
        // if key is found, then return
        if (table[indexOne] == key){
            return table[indexOne];
        }
        // keep incrementing to find the key
        indexOne = indexOne + indexIncrement; 
        indexOne = indexOne % tableSize;
        // increase number of collisions
        numOfcollision ++;
    }
    return -1;
}
