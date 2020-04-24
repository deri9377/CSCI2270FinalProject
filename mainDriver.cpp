#include <iostream>
#include <fstream>
#include "ctime"
#include "linkedList.hpp"
#include "bST.hpp"
#include "linearProbing.hpp"
#include "chaining.hpp"
using namespace std;

//load the data from a set from a chaining hash map
double loadChaining(int data[], int dataSize) {
    clock_t t;
    Chaining hashChain(dataSize);
    t = clock();
    for (int i = 0; i < dataSize; i++) {
        hashChain.insertItem(data[i]);
    }
    t = clock() - t;
    return t;
}

//load data from a set for a linear probing hash map
double loadLinearProbing(int data[], int dataSize) {
    clock_t t;
    LinearProbing linearHash(dataSize);
    t = clock();
    for (int i = 0; i < dataSize; i++) {
        linearHash.insertItem(data[i]);
    }
    t = clock() - t;
    return t;
}

//load the data from a set for the linked list
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

//read the data for the binary search tree
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
    int dataSize = 40000; //data set is always constant size
    int dataA[dataSize];
    int dataB[dataSize];
    ifstream file1;
    ifstream file2;
    file1.open("dataSetA.csv"); //read all of data set A into array A
    if (file1.is_open()) {
        string line;
        for (int i = 0; i < 40000; i++) {
            getline(file1, line, ',');
            dataA[i] = stoi(line);
        }
    }
    file1.close();
    file2.open("dataSetB.csv"); // read all of data set B into array B
    if (file2.is_open()) {
        string line;
        for (int i = 0; i < 40000; i++) {
            getline(file2, line, ',');
            dataB[i] = stoi(line);
        }
    }

    //Data set A times
    int ll = loadLinkedList(dataA, dataSize);
    cout << "Linked List - It took: (" << (double)ll/CLOCKS_PER_SEC << " seconds) to load data set A" << endl;
    int bST = loadBST(dataA, dataSize);
    cout << "bST         - It took: (" << (double)bST/CLOCKS_PER_SEC << " seconds) to load data set A" << endl;
    int chain = loadChaining(dataA, dataSize);
    cout << "Chaining    - It took: (" << (double)chain/CLOCKS_PER_SEC << " seconds) to load data set A" << endl;
    int linear = loadLinkedList(dataA, dataSize);
    cout << "Linear      - It took: (" << (double)linear/CLOCKS_PER_SEC << " seconds) to load data set A" << endl;
    cout << endl;

    //Data set B times
    ll = loadLinkedList(dataB, dataSize);
    cout << "Linked List - It took: (" << (double)ll/CLOCKS_PER_SEC << " seconds) to load data set B" << endl;
    bST = loadBST(dataB, dataSize);
    cout << "bST         - It took: (" << (double)bST/CLOCKS_PER_SEC << " seconds) to load data set B" << endl;
    chain = loadChaining(dataB, dataSize);
    cout << "Chaining    - It took: (" << (double)chain/CLOCKS_PER_SEC << " seconds) to load data set B" << endl;
    linear = loadLinkedList(dataB, dataSize);
    cout << "Linear      - It took: (" << (double)linear/CLOCKS_PER_SEC << " seconds) to load data set B" << endl;
}


