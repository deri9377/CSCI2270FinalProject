#include <iostream>
using namespace std;
#include "bST.hpp"

int main() {
    bST tree;
    tree.insert(5);
    tree.insert(10);
    tree.insert(4);
    cout << tree.search(10);
    tree.print();

    
}