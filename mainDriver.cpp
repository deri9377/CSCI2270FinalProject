#include <iostream>
#include <fstream>
#include "ctime"
#include "linkedList.hpp"
#include "bST.hpp"
#include "linearProbing.hpp"
#include "chaining.hpp"
using namespace std;

//load the data from a set from a chaining hash map
double loadChaining(int data[], Chaining hashChain, int start, int end) {
    clock_t t;
    t = clock();
    for (int i = start; i < end; i++) {
        hashChain.insertItem(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//search for all the items in the data set
double searchChaining(int data[], int size, Chaining hashChain) {
    clock_t t;
    t = clock();
    for (int i = 0; i < size; i++) {
        //hashChain.searchItem(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//load data from a set for a linear probing hash map
double loadLinearProbing(int data[], LinearProbing linearHash, int start, int end) {
    clock_t t;
    t = clock();
    for (int i = start; i < end; i++) {
        linearHash.insertItem(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//search for all the items in the data set
double searchLinearProbing(int data[], int size, LinearProbing linearHash) {
    clock_t t;
    t = clock();
    for (int i = 0; i < size; i++) {
        linearHash.searchItem(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//load the data from a set for the linked list
double loadLinkedList(int data[], LinkedList list, int start, int end) {
    clock_t t;
    t = clock();
    for (int i = start; i < end; i++) {
        list.insert(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//search for all the items in the data set
double searchLinkedList(int data[], int size, LinkedList list) {
    clock_t t;
    t = clock();
    for (int i = 0; i < size; i++) {
        list.search(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//read the data for the binary search tree
double loadBST(int data[], bST tree, int start, int end) {
    clock_t t;
    t = clock();
    for (int i = start; i < end; i++) {
        tree.insert(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//search for all the items in the data set
double searchBST(int data[], int size, bST tree) {
    clock_t t;
    t = clock();
    for (int i = 0; i < size; i++) {
        tree.search(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
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

    //Declare all the data objects
    Chaining hashChain(dataSize);
    LinearProbing linearHash(dataSize);
    LinkedList list;
    bST tree;

    //Data set A
    double cInsertA[400];
    double lPInsertA[400];
    double lLInsertA[400];
    double bSTInsertA[400];
    double cSearchA[400];
    double lPSearchA[400];
    double lLSearchA[400];
    double bSTSearchA[400];

    int random[100];
    for (int i = 0; i < 400; i++) {
        for (int j = 0; j < 100; j++) {
            random[j] = dataA[rand() % ((i * 100) + 100)];
        }
        cInsertA[i] = loadChaining(dataA, hashChain, i * 100, (i * 100) + 100)/100;
        lPInsertA[i] = loadLinearProbing(dataA, linearHash, i * 100, (i * 100) + 100)/100;
        lLInsertA[i] = loadLinkedList(dataA, list, i * 100, (i * 100) + 100)/100;
        bSTInsertA[i] = loadBST(dataA, tree, i * 100, (i * 100) + 100)/100;
        cSearchA[i] = searchChaining(random, 100, hashChain);
        // lPSearchA[i] = searchLinearProbing(random, 100, linearHash);
        // lLSearchA[i] = searchLinkedList(random, 100, list);
        // bSTSearchA[i] = searchBST(random, 100, tree);
    }

    hashChain.~Chaining();
    linearHash.~LinearProbing();
    list.~LinkedList();
    tree.~bST();

    //Data set B
    // double cInsertB[400];
    // double lPInsertB[400];
    // double lLInsertB[400];
    // double bSTInsertB[400];
    // double cSearchB[400];
    // double lPSearchB[400];
    // double lLSearchB[400];
    // double bSTSearchB[400];

    // for (int i = 0; i < 400; i++) {
    //     for (int j = 0; j < 100; j++) {
    //         random[j] = dataA[rand() % ((i * 100) + 100)];
    //     }
    //     cInsertB[i] = loadChaining(dataA, hashChain, i * 100, (i * 100) + 100)/100;
    //     lPInsertB[i] = loadLinearProbing(dataA, linearHash, i * 100, (i * 100) + 100)/100;
    //     lLInsertB[i] = loadLinkedList(dataA, list, i * 100, (i * 100) + 100)/100;
    //     bSTInsertB[i] = loadBST(dataA, tree, i * 100, (i * 100) + 100)/100;
    //     cSearchB[i] = searchChaining(random, 100, hashChain);
    //     lPSearchB[i] = searchLinearProbing(random, 100, linearHash);
    //     lLSearchB[i] = searchLinkedList(random, 100, list);
    //     bSTSearchB[i] = searchBST(random, 100, tree);
    // }
}


