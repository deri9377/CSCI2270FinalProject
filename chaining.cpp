#include <iostream>
#include "chaining.hpp"
using namespace std;

Chaining::Chaining(int bsize) {
    tableSize = bsize;
    table = new CNode*[bsize];
}

Chaining::~Chaining() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != NULL) {
            delete table[i];
            table[i] = NULL;
        }
    }
}

CNode* Chaining::createCNode(int key, CNode *next) {
    CNode *temp = new CNode();
    temp->key = key;
    temp->next = next;
    return temp;
}

bool Chaining::insertItem(int key) {
    unsigned int hash = hashFunction(key);
    if (table[hash] == NULL) {
        table[hash] = createCNode(key, NULL);
    } else {
        numOfcolision++;
        CNode* current = table[hash];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createCNode(key, NULL);
        return true;
    }
    return false;
}

unsigned int Chaining::hashFunction(int key) {
    return key % tableSize;
}

void Chaining::printTable() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] == NULL) {
            cout << "[" << i << "]:" << endl;
        } else {
            CNode* current = table[i];
            cout << "[" << i << "]:";
            while (current != NULL) {
                cout << " -> " << current->key;
                current = current->next;
            }
        }
    }
}

CNode* Chaining::searchItem(int key) {
    unsigned int hash = hashFunction(key);
    CNode* current = table[hash];
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    cout << "Not found" << endl;
    return NULL;
}
