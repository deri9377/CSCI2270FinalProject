#include <iostream>
#include "linearProbing.hpp"
using namespace std;

LPNode* LinearProbing::createLPNode(int key, LPNode* next) {
    LPNode* temp = new LPNode();
    temp->key = key;
    temp->next = next;
    return temp;
}

LinearProbing::~LinearProbing() {
    table = new LPNode*[tableSize];
}

LinearProbing::LinearProbing(int bsize) {
    tableSize = bsize;
    table = new LPNode*[bsize];
}

bool LinearProbing::insertItem(int key) {
    unsigned int hash = hashFunction(key);
    numOfcolision = 1;
    while (table[hash] != NULL) {
        hash++;
        numOfcolision++;
        if (hash == tableSize) {
            hash = 0;
        }
        if (numOfcolision == tableSize) {
            cout << "didn't insert" << endl; 
            return false;
        }
    }
    table[hash] = createLPNode(key, NULL);
    return true;
}

unsigned int LinearProbing::hashFunction(int key) {
    return key % tableSize;
}

void LinearProbing::printTable() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] == NULL) {
            cout << "[" << i << "]:" << endl;
        } else {
            cout << "[" << i << "]:" << " -> " << table[i]->key << endl;
        }
    }
}

int LinearProbing::getNumOfCollision() {
    return numOfcolision;
}

LPNode* LinearProbing::searchItem(int key) {
    unsigned int hash = hashFunction(key);
    numOfcolision = 1;
    while (table[hash] != NULL && table[hash]->key != key) {
        hash++;
        numOfcolision++;
        if (hash == tableSize){
            hash = 0;
        }
        if (numOfcolision == tableSize) {
            cout << "Not found" << endl;
            return NULL;
        }
    }
    return table[hash];
}