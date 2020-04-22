#include <iostream>
using namespace std;


struct node
{
    int key;
    struct node* next;
};

class Chaining
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numOfcolision =0;
    node* createNode(int key, node* next);
public:
    Chaining(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    node* searchItem(int key);
};


Chaining::Chaining(int bsize) {
    tableSize = bsize;
    table = new node*[bsize];
}

bool Chaining::insertItem(int key) {
    unsigned int hash = hashFunction(key);
    if (table[hash] == NULL) {
        table[hash] = createNode(key, NULL);
    } else {
        numOfcolision++;
        node* current = table[hash];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createNode(key, NULL);
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
            node* current = table[i];
            cout << "[" << i << "]:";
            while (current != NULL) {
                cout << " -> " << current->key;
                current = current->next;
            }
        }
    }
}

node* Chaining::searchItem(int key) {
    unsigned int hash = hashFunction(key);
    node* current = table[hash];
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
    }
    return NULL;
}
