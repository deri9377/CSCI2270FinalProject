#include <iostream>
using namespace std;

#ifndef LINEARPROBING_HPP
#define LINEARPROBING_HPP

struct LPNode
{
    int key;
    struct LPNode* next;
};

class LinearProbing
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    LPNode* *table;
    int numOfcolision =0;
    LPNode* createLPNode(int key, LPNode* next);
public:
    LinearProbing(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    LPNode* searchItem(int key);
};

#endif 