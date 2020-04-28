#include <iostream>
#include "quadraticProbing.hpp"
using namespace std;

QPNode* QuadraticProbing::createQPNode(int key, QPNode* next) {
    QPNode* temp = new QPNode();
    temp->key = key;
    temp->next = next;
    return temp;
}

QuadraticProbing::~QuadraticProbing() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != NULL) {
            delete table[i];
            table[i] = new QPNode();
        }
    }
}

QuadraticProbing::QuadraticProbing(int bsize) {
    tableSize = bsize;
    table = new QPNode*[bsize];
}

bool QuadraticProbing::insertItem(int key) {
    unsigned int hash = hashFunction(key);
    numOfcolision = 1;
    while (table[hash] != NULL) {
        hash = hashFunction(key + (numOfcolision * numOfcolision));
        numOfcolision++;
        if (numOfcolision == tableSize) {
            cout << "didnt insert" << endl;
            return false;
        }
    }
    table[hash] = createQPNode(key, NULL);
    return true;
}

unsigned int QuadraticProbing::hashFunction(int key) {
    return key % tableSize;
}

void QuadraticProbing::printTable() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] == NULL) {
            cout << "[" << i << "]:" << endl;
        } else {
            cout << "[" << i << "]:" << " -> " << table[i]->key << endl;
        }
    }
}

int QuadraticProbing::getNumOfCollision() {
    return numOfcolision;
}

QPNode* QuadraticProbing::searchItem(int key) {
    unsigned int hash = hashFunction(key);
    numOfcolision = 1;
    while (table[hash]->key != key) {
        hash = hashFunction(key + (numOfcolision * numOfcolision));
        numOfcolision++;
        if (hash == tableSize - 1){
            hash = 0;
        }
        if (numOfcolision == tableSize) {
            cout << "Not found" << endl;
            return NULL;
        }
    }
    return table[hash];
}