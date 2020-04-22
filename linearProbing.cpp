#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node* next;
};

class LinearProbing
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numOfcolision =0;
    node* createNode(int key, node* next);
public:
    LinearProbing(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    node* searchItem(int key);
};

node* LinearProbing::createNode(int key, node* next) {
    node* temp;
    temp->key = key;
    temp->next = next;
    return temp;
}

LinearProbing::LinearProbing(int bsize) {
    tableSize = bsize;
    table = new node*[bsize];
}

bool LinearProbing::insertItem(int key) {
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
    table[hash] = createNode(key, NULL);
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

node* LinearProbing::searchItem(int key) {
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