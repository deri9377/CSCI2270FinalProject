#include <iostream>
#include <fstream>
#include "ctime"
#include "linkedList.hpp"
#include "bST.hpp"
#include "hash.hpp"
using namespace std;

double loadChaining() {
    return 0;
}

double loadLinearProbing() {
    return 0;
}

double loadLinkedList() {
    clock_t t;
    linkedList list;
    ifstream file;
    file.open("dataSetB.csv");
    if (file.is_open()) {
        string line;
        //Run everything
        // while (getline(file, line, ',')) {
        //     list.insert(stoi(line));
        // }
        //First 100 elements
        t = clock();
        for (int i = 0; i < 100; i++) {
            getline(file, line, ',');
            list.insert(stoi(line));
        }
    }
    t = clock() - t;
    file.close();
    return t;
}

double loadBST() {
    clock_t t;
    bST tree;
    ifstream file;
    file.open("dataSetB.csv");
    if (file.is_open()) {
        string line;
        //Run everything
        // while (getline(file, line, ',')) {
        //     list.insert(stoi(line));
        // }
        //First 100 elements
        t = clock();
        for (int i = 0; i < 100; i++) {
            getline(file, line, ',');
            tree.insert(stoi(line));
        }
    }
    t = clock() - t;
    file.close();
    return t;
}


int main() {
    int ll = loadLinkedList();
    cout << "Linked List - It took: (" << (double)ll/CLOCKS_PER_SEC << " seconds) to load the first 100 elemets" << endl;
    int bST = loadBST();
    cout << "bST - It took: (" << (double)bST/CLOCKS_PER_SEC << " seconds) to load the first 100 elemets" << endl;
}


