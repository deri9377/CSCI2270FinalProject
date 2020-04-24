#include <iostream>
using namespace std;

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct LLNode {
    int key;
    LLNode *next;
};

class linkedList {
    private:
        LLNode* root;

    public:
        linkedList();
        ~linkedList();
        void insert(int k);
        LLNode* search(int key);
        void display();
};

#endif