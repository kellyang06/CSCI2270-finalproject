#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <unistd.h>
#include <thread>
#include <cstdlib>
#include "doubleLL.hpp"

using namespace std;

/* driver for doubly linked list */

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

    NodeList doubleLinkedList = NodeList();

    // For loop to run a timing test (insert/search 200, 50 times)
    for (int i = 0; i < 50; i ++){
        // Start timing
        auto start = chrono::steady_clock::now();
        // Insert 200 elems into linked list (with for loop, call insertNode)
        for (int j = 0; j < 200; j ++){
            insertIndex = (i * 200) + j;
            doubleLinkedList.insertNode(intArr[insertIndex]);
        }
        // End timing and record search result
        auto end = chrono::steady_clock::now();
        insert[i] = chrono::duration_cast<chrono::nanoseconds>(end - start).count()/200.0;


        // Generate 200 pseudo-random numbers as indices to search (store into array)
        for (int k = 0; k < 200; k ++){
            // random number between 0 and number of elements inserted in linked list
            // store generated random numbers into array
            randomArr[k] = rand() % (200 * (k + 1));
        }

        // Start timing
        start = chrono::steady_clock::now();
        // Search 200 times (iterate through pseudo-random number array and find in doubleLL with searchNode)
        for (int m = 0; m < 200; m ++){
            doubleLinkedList.searchNode(randomArr[m]);
        }
        // End timing and record search results
        end = chrono::steady_clock::now();
        search[i] = chrono::duration_cast<chrono::nanoseconds>(end - start).count()/200.0;
    }
    
    // Record data to CSV
    ofstream out_file;
    out_file.open("insert_search_performance_doubly_ll.csv");

    for (int n = 0; n < 50; n ++){
        out_file << insert[n] << "," << search[n] << endl;
    }
}
