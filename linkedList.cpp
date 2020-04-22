#include <iostream>
using namespace std;
#include "linkedList.hpp"


linkedList::linkedList() {
    root = NULL;
}

linkedList::~linkedList() {

}

Node* linkedList::search(int key) {
    Node* current = root;
    while (current != NULL) {
        if (current->key == key) {
            cout << "Node found" << endl;
            return current;
        }
        current = current->next;
    }
    cout << key << " is not in the list" << endl;
    return NULL;
}

void linkedList::insert(int k) {
    Node *temp = new Node();
    temp->key = k;
    if (root == NULL) {
        root = temp;
        return;
    }
    Node* current = root;
    while (current != NULL) {
        if (current->next == NULL) {
            current->next = temp;
            return;
        }
        current = current->next;
    }
}

void linkedList::display() {
    Node *current = root;
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