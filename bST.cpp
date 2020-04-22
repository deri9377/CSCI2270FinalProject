#include <iostream>
using namespace std;

#include "bST.hpp"

bST::bST() {
    root = NULL;
}

bST::~bST() {

}

void bST::insert(int key) {
    Node *temp;
    temp->key = key;
    if (root == NULL) {
        root = temp;
    } else {
        Node *current = root;
        Node *prev = current;
        while (current != NULL) {
            if (current->key < key) {
                prev = current;
                current = current->left;
            } else {
                prev = current;
                current = current->right;
            }
        }
        if (key < prev->key) {
            prev->left = temp;
        } else {
            prev->right = temp;
        }
    }
}

Node* recursiveSearch(int key, Node* current) {
    if (current->key == key) {
        return current;
    } else {
        if (current->key < key) {
            recursiveSearch(key, current->right);
        } else {
            recursiveSearch(key, current->left);
        }
    }
    return NULL;
}

Node* bST::search(int key) {
    if (root->key == key) {
        return root;
    }
    return recursiveSearch(key, root);
}

void bST::display() {
    
}