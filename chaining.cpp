#include <iostream>
#include "chaining.hpp"
using namespace std;

Chaining::Chaining(int bsize) {
    tableSize = bsize;
    table = new CNode*[bsize];
}

Chaining::~Chaining() {
    delete[] table;
    table = new CNode*[tableSize];
}

//creates a new node and sets the key and next to the key and next parameters
//returns the pointer to the node
CNode* Chaining::createCNode(int key, CNode *next) {
    CNode *temp = new CNode();
    temp->key = key;
    temp->next = next;
    return temp;
}

/*
creates a new node with key and inserts it into the hash map
*/
bool Chaining::insertItem(int key) {
    unsigned int hash = hashFunction(key);      //get the initial hash
    if (table[hash] == NULL) {                  //if the bucket is empty put a new node at the root of the bucket
        table[hash] = createCNode(key, NULL); 
        return true;
    } else {                                    //otherwise add a new node to the end of the linked list in the bucket
        numOfcolision++;
        CNode* current = table[hash];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createCNode(key, NULL); //once the node is incerted return true
        return true;
    }
    cout << "didn't insert" << endl;            //cout that the node was not inserted 
    return false;                               //return false if the node was not inserted
}

unsigned int Chaining::hashFunction(int key) {
    return key % tableSize;                     //the hash key is the key divided by the size of the table
}

//prints out all the elements in the table
void Chaining::printTable() {
    for (int i = 0; i < tableSize; i++) {       //loop through each bucket
        cout << "[" << i << "]:";
        if (table[i] != NULL) {                 //if the bucket isn't empty loop through the linked list
            CNode* current = table[i];
            while (current != NULL) {           //print out each element in the bucket chain
                cout << " -> " << current->key;
                current = current->next;
            }
        }
        cout << endl;
    }
}

/* searches through the hash map for the elements 
    with the same key and return the object
*/
CNode* Chaining::searchItem(int key) {
    unsigned int hash = hashFunction(key);      //create the hash key
    CNode* current = table[hash];   
    while (current != NULL) {                   //if the bucket is not empty loop through the chain
        if (current->key == key) {              //in the bucket for the element with key
            return current;                     //if the object with the same key is found return the object
        }
        current = current->next;
    }
    cout << "Not found";                        //if the object is not found then print out that is wasn't 
    return NULL;                                //reutrn NULL
}
