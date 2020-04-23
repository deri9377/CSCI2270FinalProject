#include <iostream>
using namespace std;

#include "bST.hpp"

bST::bST() {
    root = NULL;
}

bST::~bST() {

}

void bST::insert(int key) {
    Node *temp = new Node();
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
        //current = temp;
        //cout << "Setting new node: " << current->key << endl;
        if (key < prev->key) {
            prev->left = temp;
            cout << "SETTING LEFT " << prev->key << " " << prev->left->key << endl;
            } 
        else {
            prev->right = temp;
            cout << "SETTING RIGHT " << prev->key << " " << prev->right->key << endl;
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


//This will print a visual model of the BST so that all node and their respective children/parent nodes can be seen
void displayHelper(int n, Node* here)
{
    if(here == NULL) //Leaf check
    {
        return;
    }
    cout << here->key << endl;
    displayHelper(n,here->left);
    displayHelper(n,here->right);
    // n = n + 10; //This increments the spacing on the model
    // displayHelper(n,here->right); //Right is traversed before left // Right - Here - Left
    // cout << endl;
    // for(int i = 10;i < n;i++)
    // {
    //     printf(" ");
    // }
    // printf("%d\n", here->key);
    // displayHelper(n,here->left);
    return;
}
void bST::display() 
{
    int spaceNum = 1;
    displayHelper(spaceNum, root);
    return;
}