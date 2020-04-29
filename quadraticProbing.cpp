#include <iostream>
#include "quadraticProbing.hpp"
using namespace std;

//create a new node 
QPNode* QuadraticProbing::createQPNode(int key, QPNode* next) {
    QPNode* temp = new QPNode();                //creates a new node                   
    temp->key = key;                            //sets the key to key
    temp->next = next;                          //sets the next to next
    return temp;                                //returns the temp pointer
}

QuadraticProbing::~QuadraticProbing() {
    table = new QPNode*[tableSize];             //creates a new table
}

QuadraticProbing::QuadraticProbing(int bsize) {
    tableSize = bsize;                          //sets the table size to bsize
    table = new QPNode*[bsize];
}

//creates a new node and inserts it in the hash table
bool QuadraticProbing::insertItem(int key) {    
    unsigned int hash = hashFunction(key);      //creates an initial hash key
    numOfcolision = 1;
    while (table[hash] != NULL) {               //while the hash spot is full create a new hash spot
        hash = hashFunction(key + (numOfcolision * numOfcolision)); //new hash spot is based on the key + the square of the iteration
        numOfcolision++;
        if (numOfcolision == tableSize) {       //if the number of itteration equals the table size then it couldn't find a spot to insert
            cout << "didnt insert" << endl;     //return false and say the node couldn't be inserted
            return false;
        }
    }
    table[hash] = createQPNode(key, NULL);      //create a new node and insert it at the open spot 
    return true;                                //return true
}

unsigned int QuadraticProbing::hashFunction(int key) {
    return key % tableSize;                     //creats a hash key based on table size
}

//prints all the buckets in the table
void QuadraticProbing::printTable() {
    for (int i = 0; i < tableSize; i++) {       //loops through each index in the table
        if (table[i] == NULL) {
            cout << "[" << i << "]:" << endl;   //if the table is empty print nothing
        } else {
            cout << "[" << i << "]:" << " -> " << table[i]->key << endl;    //else print the value at the table
        }
    }
}

int QuadraticProbing::getNumOfCollision() {
    return numOfcolision;                       //returns the number of collisions
}

//searches for a node with the given value
QPNode* QuadraticProbing::searchItem(int key) {
    unsigned int hash = hashFunction(key);      //start with the given hash
    numOfcolision = 1;
    while (table[hash]->key != key) {           //while the key at the bucket is not the right one 
        hash = hashFunction(key + (numOfcolision * numOfcolision)); //create a new hash based on the key + the itteration squared
        numOfcolision++;
        if (hash == tableSize - 1){
            hash = 0;
        }
        if (numOfcolision == tableSize) {       //if the itterations equal the table size say that the node was not found
            cout << "Not found" << endl;
            return NULL;
        }
    }
    return table[hash];                         //return the node at the hash bucket
}