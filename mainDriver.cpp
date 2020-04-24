#include <iostream>
#include <fstream>
#include "ctime"
#include "linkedList.hpp"
#include "bST.hpp"
using namespace std;

double loadChaining() {

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
    int dataA[40000];
    int dataB[40000];
    ifstream file1;
    ifstream file2;
    file1.open("dataSetA.csv");
    if (file1.is_open()) {
        string line;
        for (int i = 0; i < 40000; i++) {
            
        }
    }
    int ll = loadLinkedList();
    cout << "Linked List - It took: (" << (double)ll/CLOCKS_PER_SEC << " seconds) to load the first 100 elemets" << endl;
    int bST = loadBST();
    cout << "bST - It took: (" << (double)bST/CLOCKS_PER_SEC << " seconds) to load the first 100 elemets" << endl;
}


