#include <iostream>
using namespace std;

#ifndef BST_HPP
#define BST_HPP

struct bSTNode {
    int key;
    bSTNode *left;
    bSTNode *right;
};

class bST {
    private:
        bSTNode *root;

    public:
        bST();
        ~bST();
        void insert(int key);
        bSTNode* search(int key);
        void display();
        void print();
};

#endif