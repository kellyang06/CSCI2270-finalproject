#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <unistd.h>
#include <thread>
#include <cstdlib>
#include "hashDH.hpp"

using namespace std;

int main(){
    // Read in the data from CSV file
    ifstream in_file;
    in_file.open("dataSetA-updated.csv");

    string elements;
    int intArr[10000];
    int index = 0; 

    while (in_file){
        getline(in_file, elements, ',');
        int element = stoi(elements);
        intArr[index] = element;
        index ++;
    }
    
    // define
    int insertIndex; 
    int randomArr[200];
    float insert[50];
    float search[50];
    int collisionsBeforeInsert[50];
    int collisionsAfterInsert[50];
    int collisionsBeforeSearch[50];
    int collisionsAfterSearch[50];

    // table size should be set to 10,009
    HashTable hashTable = HashTable(10009);

    // For loop to run a timing test (insert/search 200, 50 times)
    for (int i = 0; i < 50; i ++){
        // Start timing
        auto start = chrono::steady_clock::now();
        // store number of collisions before inserting anything
        collisionsBeforeInsert[i] = hashTable.getNumOfCollision();
        // Insert 200 elems into hash table (with for loop, call insertNode)
        for (int j = 0; j < 200; j ++){
            insertIndex = (i * 200) + j;
            hashTable.insertItem(intArr[insertIndex]);
        }
        // store number of collisions from insert operation
        collisionsAfterInsert[i] = hashTable.getNumOfCollision() - collisionsBeforeInsert[i];
        // End timing and record search result
        auto end = chrono::steady_clock::now();
        insert[i] = chrono::duration_cast<chrono::nanoseconds>(end - start).count()/200.0;


        // Generate 200 pseudo-random numbers as indices to search (store into array)
        for (int k = 0; k < 200; k ++){
            // random number between 0 and number of elements inserted in hash table
            // store generated random numbers into array
            randomArr[k] = rand() % (200 * (k + 1));
        }

        // Start timing
        start = chrono::steady_clock::now();
        // store number of collisions before searching anything
        collisionsBeforeSearch[i] = hashTable.getNumOfCollision();
        // Search 200 times (iterate through pseudo-random number array and find in table with searchNode)
        for (int m = 0; m < 200; m ++){
            hashTable.searchItem(randomArr[m]);
        }
        // store number of collisions from search operation
        collisionsAfterSearch[i] = hashTable.getNumOfCollision() - collisionsBeforeSearch[i];
        // End timing and record search results
        end = chrono::steady_clock::now();
        search[i] = chrono::duration_cast<chrono::nanoseconds>(end - start).count()/200.0;
    }
    
    // Record data to CSV
    ofstream out_file;
    out_file.open("insert_search_performance_hash_bst.csv");

    for (int n = 0; n < 50; n ++){
        out_file << insert[n] << "," << collisionsAfterInsert[n] << "," << search[n] << "," << collisionsAfterSearch[n] << endl;
    }
}
