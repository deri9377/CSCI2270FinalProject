/*
Devin Riess:
Wrote the search function and the constructor/deconstructor.

Henry Saver:
Created class and insert function as well as display method.

*/

#include <iostream>
using namespace std;

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct LLNode {
    int key;
    LLNode *next;
};

class LinkedList {
    private:
        LLNode* root;

    public:
        LinkedList();
        ~LinkedList();
        void insert(int k);
        LLNode* search(int key);
        void display();
};

#endif