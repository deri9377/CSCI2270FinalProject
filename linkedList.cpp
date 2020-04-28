#include <iostream>
using namespace std;
#include "linkedList.hpp"


LinkedList::LinkedList() {
    root = NULL;
}

LinkedList::~LinkedList() {
    if (root != NULL) {
        while (root->next != NULL) {
            LLNode *temp = root->next;
            delete root;
            root = temp;
        }
    }
}

LLNode* LinkedList::search(int key) {
    LLNode* current = root;
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    cout << "Not found" << endl; 
    return NULL;
}

void LinkedList::insert(int k) {
    LLNode *temp = new LLNode();
    temp->key = k;
    if (root == NULL) {
        root = temp;
        return;
    }
    LLNode* current = root;
    while (current != NULL) {
        if (current->next == NULL) {
            current->next = temp;
            return;
        }
        current = current->next;
    }
}

void LinkedList::display() {
    LLNode *current = root;
    if (current == NULL) {
        cout << "The list is Empty" << endl;
    } else {
        cout << "List:";
        while (current != NULL) {
            cout << " " << current->key;
            current = current->next;
        }
        cout << endl;
    }
}