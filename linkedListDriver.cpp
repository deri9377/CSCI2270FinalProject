#include <iostream>
#include "linkedList.hpp"
using namespace std;

int main() {
    linkedList list;
    list.insert(10);
    list.insert(5);
    list.insert(2);
    list.insert(8);
    list.insert(12);
    list.display();
    list.search(15);
    list.search(8);
}