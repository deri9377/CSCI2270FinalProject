#include <iostream>
using namespace std;

#include "bST.hpp"

bST::bST() {
    root = NULL;
}

bST::~bST() {

}
Node* insertHelper(int key, Node* curr)
{
    if(curr == NULL)
    {
        Node* temp = new Node(); //New node created with the data given with flag initially
        temp->key = key;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    //Here the iterator choses to go left or right based on the laws of the BST
    else if(curr->key > key)
    {
        curr->left = insertHelper(key,curr->left);
    }
    else if(curr->key < key)
    {

        curr->right = insertHelper(key,curr->right);
    }
}
//Uses recursion here to traverse the tree and move things accordingly
void bST::insert(int key) {
    root = insertHelper(key, root);
    return;
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
//Helper for display
void displayHelper(int n, Node* here)
{
    if(here == NULL) //Leaf check
    {
        return;
    }
    n = n + 10; //This increments the spacing on the model
    displayHelper(n,here->right); //Right is traversed before left // Right - Here - Left
    cout << endl;
    for(int i = 10;i < n;i++) // Spacing the nodes
    {
        printf(" ");
    }
    printf("%d\n", here->key); // Actual node data
    displayHelper(n,here->left); //Finally the left is traversed
    return;
}
//Needs helper for recursion
void bST::display() 
{
    int spaceNum = 1;
    displayHelper(spaceNum, root);
    return;