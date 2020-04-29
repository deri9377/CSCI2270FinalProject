#include <iostream>
#include "linearProbing.hpp"
using namespace std;

//create a new node with key and next
LPNode* LinearProbing::createLPNode(int key, LPNode* next) {
    LPNode* temp = new LPNode();            //creates a new node
    temp->key = key;                        //sets the key to key
    temp->next = next;                      //sets the next to the next
    return temp;                            //returns the new node pointer
}

LinearProbing::~LinearProbing() {
    table = new LPNode*[tableSize];         //creates a new table
}

//creates a new hash map with size bsize
LinearProbing::LinearProbing(int bsize) {
    tableSize = bsize;
    table = new LPNode*[bsize];
}

//creates a new node and inserts it at the next available bucket based on the hash key
bool LinearProbing::insertItem(int key) {
    unsigned int hash = hashFunction(key);  //create the hash key based of the key
    numOfcolision = 1;
    while (table[hash] != NULL) {           //while the bucket is full increase the hash by one each time
        hash++;
        numOfcolision++;
        if (hash == tableSize) {
            hash = 0;
        }
        if (numOfcolision == tableSize) {   //if all the buckets have been searched through then return that it wasn't inserted
            cout << "didn't insert" << endl; 
            return false;
        }
    }
    table[hash] = createLPNode(key, NULL);  //create a new node and put it at the bucket
    return true;
}

//creates a hash key based on the given key
unsigned int LinearProbing::hashFunction(int key) {
    return key % tableSize;                 //creates a hash key based on table size
}

//prints out each bucket in the table
void LinearProbing::printTable() {
    for (int i = 0; i < tableSize; i++) {   //loops through every bucket in the hash map
        if (table[i] == NULL) {
            cout << "[" << i << "]:" << endl;   //if the bucket is empty print nothing
        } else {
            cout << "[" << i << "]:" << " -> " << table[i]->key << endl;    //print out the value at the bucket
        }
    }
}


int LinearProbing::getNumOfCollision() {
    return numOfcolision;                  //returns the number of collisions that have occured
}

//searches for a pointer with the given key
LPNode* LinearProbing::searchItem(int key) {
    unsigned int hash = hashFunction(key);  //creates a hash key based on the given value
    numOfcolision = 1;
    while (table[hash] != NULL && table[hash]->key != key) {    //searches through every bucket until the key is found
        hash++;
        numOfcolision++;
        if (hash == tableSize){
            hash = 0;
        }
        if (numOfcolision == tableSize) {   //if all the buckets have been visited then return not found
            cout << "Not found" << endl;
            return NULL;
        }
    }
    return table[hash];                     //if it was found return the pointer 
}