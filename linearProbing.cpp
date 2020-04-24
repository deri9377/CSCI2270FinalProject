#include <iostream>
using namespace std;

struct LPNode
{
    int key;
    struct LPNode* next;
};

class Chaining
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    LPNode* *table;
    int numOfcolision =0;
    LPNode* createLPNode(int key, LPNode* next);
public:
    Chaining(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    LPNode* searchItem(int key);
};

LPNode* Chaining::createLPNode(int key, LPNode* next) {
    LPNode* temp;
    temp->key = key;
    temp->next = next;
    return temp;
}

Chaining::Chaining(int bsize) {
    tableSize = bsize;
    table = new LPNode*[bsize];
}

bool Chaining::insertItem(int key) {
    unsigned int hash = hashFunction(key);
    int collisions = 0;
    while (table[hash] != NULL) {
        hash++;
        numOfcolision++;
        collisions++;
        if (hash == tableSize) {
            hash = 0;
        }
        if (collisions == tableSize) {
            return false;
        }
    }
    table[hash] = createLPNode(key, NULL);
    return true;
}

unsigned int Chaining::hashFunction(int key) {
    return key % tableSize;
}

void Chaining::printTable() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] == NULL) {
            cout << "[" << i << "]:" << endl;
        } else {
            cout << "[" << i << "]:" << " -> " << table[i]->key << endl;
        }
    }
}

int Chaining::getNumOfCollision() {
    return numOfcolision;
}

LPNode* Chaining::searchItem(int key) {
    unsigned int hash = hashFunction(key);
    int collisions = 0;
    while (table[hash]->key != key) {
        hash++;
        numOfcolision++;
        collisions++;
        if (hash == tableSize){
            hash = 0;
        }
        if (collisions == tableSize) {
            return NULL;
        }
    }
    return table[hash];
}