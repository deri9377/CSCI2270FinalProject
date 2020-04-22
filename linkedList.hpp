#include <iostream>
using namespace std;

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct Node {
    int key;
    Node *next;
};

class linkedList {
    private:
        Node* root;

    public:
        linkedList();
        ~linkedList();
        void insert(int k);
        Node* search(int key);
        void display();
};

#endif