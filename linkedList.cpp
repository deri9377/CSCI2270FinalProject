#include <iostream>
using namespace std;
#include "linkedList.hpp"


linkedList::linkedList() {
    root = NULL;
}

linkedList::~linkedList() {

}

LLNode* linkedList::search(int key) {
    LLNode* current = root;
    while (current != NULL) {
        if (current->key == key) {
            cout << "LLNode found" << endl;
            return current;
        }
        current = current->next;
    }
    cout << key << " is not in the list" << endl;
    return NULL;
}

void linkedList::insert(int k) {
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

void linkedList::display() {
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