/*
Devin Riess:
Made the class structure and did the Insert method and some of the helpers

Henry Saver:
Made the search method and some of the helpers
*/

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
    ~LinearProbing(); //Deconstructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    LPNode* searchItem(int key);
};

#endif 