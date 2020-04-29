#include <iostream>
using namespace std;
#include "linkedList.hpp"

//Basic constructor
LinkedList::LinkedList() {
    root = NULL;
}
//Deconstructor
LinkedList::~LinkedList() {
    if (root != NULL) { //Goes through the entirety of the LL and frees the memory of each node
        while (root->next != NULL) {
            LLNode *temp = root->next;
            delete root;
            root = temp;
        }
    }
}
//Searches for the given key through the entire linked list and returns
//the node that contains that key
LLNode* LinkedList::search(int key) {
    LLNode* current = root;
    while (current != NULL) {
        if (current->key == key) { // Traverses the entire linked list until found
            return current;
        }
        current = current->next;
    }
    cout << "Not found" << endl; //Failcase for if the key is not found by the end
    return NULL;
}
//Insertion function for adding a new key into the linked list
void LinkedList::insert(int k) {
    LLNode *temp = new LLNode();
    temp->key = k;
    if (root == NULL) { //For empty tree, the root becomes the inserted node
        root = temp;
        return;
    }
    LLNode* current = root;
    while (current != NULL) { // Otherwise a new node is added to the end of the linked list
        if (current->next == NULL) {
            current->next = temp;
            return;
        }
        current = current->next;
    }
}
//Prints the entire linked list if it is not empty
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