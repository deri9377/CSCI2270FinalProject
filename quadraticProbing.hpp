#ifndef QUADRATICPROBING_HPP
#define QUADRATICPROBING_HPP

#include <string>


using namespace std;

struct QPNode
{
    int key;
    struct QPNode* next;
};

class QuadraticProbing
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    QPNode* *table;
    int numOfcolision =0;
    QPNode* createQPNode(int key, QPNode* next);
public:
    QuadraticProbing(int bsize);  // Constructor
    ~QuadraticProbing(); //Deconstructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    QPNode* searchItem(int key);
};

#endif
