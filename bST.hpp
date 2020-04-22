#include <iostream>
using namespace std;

#ifndef BST_HPP
#define BST_HPP

struct Node {
    int key;
    Node *left;
    Node *right;
};

class bST {
    private:
        Node *root;

    public:
        bST();
        ~bST();
        void insert(int key);
        Node* search(int key);
        void display();


};

#endif