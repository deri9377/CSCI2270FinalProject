#include <iostream>
#include <fstream>
#include "ctime"
#include "linkedList.hpp"
#include "bST.hpp"
using namespace std;

double loadChaining(int data[], int dataSize) {
    return 0;
}

double loadLinearProbing(int data[], int dataSize) {
    return 0;
}

double loadLinkedList(int data[], int dataSize) {
    clock_t t;
    linkedList list;
    t = clock();
    for (int i = 0; i < dataSize; i++) {
        list.insert(data[i]);
    }
    t = clock() - t;
    return t;
}

double loadBST(int data[], int dataSize) {
    clock_t t;
    bST tree;
    t = clock();
    for (int i = 0; i < dataSize; i++) {
        tree.insert(data[i]);
    }
    t = clock() - t;
    return t;
}


int main() {
    int dataSize = 40000;
    int dataA[dataSize];
    int dataB[dataSize];
    ifstream file1;
    ifstream file2;
    file1.open("dataSetA.csv");
    if (file1.is_open()) {
        string line;
        for (int i = 0; i < 40000; i++) {
            getline(file1, line, ',');
            dataA[i] = stoi(line);
        }
    }
    file1.close();
    file2.open("dataSetB.csv");
    if (file2.is_open()) {
        string line;
        for (int i = 0; i < 40000; i++) {
            getline(file2, line, ',');
            dataB[i] = stoi(line);
        }
    }
    
    int ll = loadLinkedList(dataA, dataSize);
    cout << "Linked List - It took: (" << (double)ll/CLOCKS_PER_SEC << " seconds) to load the first 100 elemets" << endl;
    int bST = loadBST(dataA, dataSize);
    cout << "bST - It took: (" << (double)bST/CLOCKS_PER_SEC << " seconds) to load the first 100 elemets" << endl;
}


