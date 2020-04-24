#include <iostream>
using namespace std;


struct CNode
{
    int key;
    struct CNode* next;
};

class Chaining
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    CNode* *table;
    int numOfcolision =0;
    CNode* createCNode(int key, CNode* next);
public:
    Chaining(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    CNode* searchItem(int key);
};


Chaining::Chaining(int bsize) {
    tableSize = bsize;
    table = new CNode*[bsize];
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
    }
    return NULL;
}
