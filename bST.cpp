#include <iostream>
using namespace std;

#include "bST.hpp"

bST::bST() {
    root = NULL;
}

void deleteHelper(bSTNode *node) { 
    if (node != NULL) {
        deleteHelper(node->left);
        deleteHelper(node->right);
        delete node;
        
    }
}

bST::~bST() {
    deleteHelper(root);
    root = NULL;
}

bSTNode* insertHelper(int key, bSTNode* curr)
{
    if(curr == NULL)
    {
        bSTNode* temp = new bSTNode(); //New bSTNode created with the data given with flag initially
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
    return curr;
}
//Uses recursion here to traverse the tree and move things accordingly
void bST::insert(int key) {
    root = insertHelper(key, root);
    return;
}

bSTNode* recursiveSearch(int key, bSTNode* current) {
    if(current == NULL)
    {
        cout << "Not found" << endl;
        return NULL;
    }
    if (current->key == key) {
        return current;
    }
    if (current->key < key) {
        return recursiveSearch(key, current->right);
    }
    return recursiveSearch(key, current->left);
}

bSTNode* bST::search(int key) {
    return recursiveSearch(key, root);
}


//This will print a visual model of the BST so that all bSTNode and their respective children/parent bSTNodes can be seen
//Helper for display
void displayHelper(int n, bSTNode* here)
{
    if(here == NULL) //Leaf check
    {
        return;
    }
    n = n + 10; //This increments the spacing on the model
    displayHelper(n,here->right); //Right is traversed before left // Right - Here - Left
    cout << endl;
    for(int i = 10;i < n;i++) // Spacing the bSTNodes
    {
        printf(" ");
    }
    printf("%d\n", here->key); // Actual bSTNode data
    displayHelper(n,here->left); //Finally the left is traversed
    return;
}
//Needs helper for recursion
void bST::display() 
{
    int spaceNum = 1;
    displayHelper(spaceNum, root);
    return;
}

void printHelper(bSTNode *node) {
    if (node == NULL) {

    } else {
        printHelper(node->left);
        cout << node->key << " ";
        printHelper(node->right);
    }
}

void bST::print() {
    printHelper(root);
}