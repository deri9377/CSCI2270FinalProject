
/*
Devin Riess:
wrote the Insert and Search methods 

Henry Saver:
Wrote the class and other helper methods
*/

#ifndef HASH_HPP
#define HASH_HPP

#include <string>


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
    ~Chaining(); //Deconstructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    CNode* searchItem(int key);
};

#endif
