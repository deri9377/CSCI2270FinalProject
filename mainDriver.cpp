#include <iostream>
#include <fstream>
#include "ctime"
#include "linkedList.hpp"
#include "bST.hpp"
#include "linearProbing.hpp"
#include "chaining.hpp"
#include "quadraticProbing.hpp"
using namespace std;

//load the data from a set from a chaining hash map
double loadChaining(int data[], Chaining &hashChain, int start, int end) {
    clock_t t;
    t = clock();
    for (int i = start; i < end; i++) {
        hashChain.insertItem(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//search for all the items in the data set
double searchChaining(int data[], int size, Chaining &hashChain) {
    clock_t t;
    t = clock();
    for (int i = 0; i < size; i++) {
        hashChain.searchItem(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//load data from a set for a linear probing hash map
double loadLinearProbing(int data[], LinearProbing &linearHash, int start, int end) {
    clock_t t;
    t = clock();
    for (int i = start; i < end; i++) {
        linearHash.insertItem(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//search for all the items in the data set
double searchLinearProbing(int data[], int size, LinearProbing &linearHash) {
    clock_t t;
    t = clock();
    for (int i = 0; i < size; i++) {
        linearHash.searchItem(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//load the data from a set for the linked list
double loadLinkedList(int data[], LinkedList &list, int start, int end) {
    clock_t t;
    t = clock();
    for (int i = start; i < end; i++) {
        list.insert(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//search for all the items in the data set
double searchLinkedList(int data[], int size, LinkedList &list) {
    clock_t t;
    t = clock();
    for (int i = 0; i < size; i++) {
        list.search(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//read the data for the binary search tree
double loadBST(int data[], bST &tree, int start, int end) {
    clock_t t;
    t = clock();
    for (int i = start; i < end; i++) {
        tree.insert(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//search for all the items in the data set
double searchBST(int data[], int size, bST &tree) {
    clock_t t;
    t = clock();
    for (int i = 0; i < size; i++) {
        tree.search(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//read the data for the Quadratic hash
double loadQuadraticProbing(int data[], QuadraticProbing &quadraticHash, int start, int end) {
    clock_t t;
    t = clock();
    for (int i = start; i < end; i++) {
        quadraticHash.insertItem(data[i]);
    }
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}

//search for all the items in the data set
double searchQuadraticProbing(int data[], int size, QuadraticProbing &quadraticHash) {
    clock_t t;
    t = clock();
    for (int i = 0; i < size; i++) {
        quadraticHash.searchItem(data[i]);
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
    QuadraticProbing quadraticHash(dataSize);

    //Data set A
    double cInsertA[400];
    double lPInsertA[400];
    double lLInsertA[400];
    double bSTInsertA[400];
    double QPInsertA[400];
    double cSearchA[400];
    double lPSearchA[400];
    double lLSearchA[400];
    double bSTSearchA[400];
    double QPSearchA[400];

    int random[100];    //list of 100 random elements already inserted
    for (int i = 0; i < 400; i++) {     //loop through the iteration 400 times
        for (int j = 0; j < 100; j++) { //fill the random array with 100 random elements
            random[j] = dataA[rand() % ((i * 100) + 100)];
        }
        //call all of the load and searches for all the data structures 
        cInsertA[i] = loadChaining(dataA, hashChain, i * 100, (i * 100) + 100)/100;
        lPInsertA[i] = loadLinearProbing(dataA, linearHash, i * 100, (i * 100) + 100)/100;
        lLInsertA[i] = loadLinkedList(dataA, list, i * 100, (i * 100) + 100)/100;
        bSTInsertA[i] = loadBST(dataA, tree, i * 100, (i * 100) + 100)/100;
        QPInsertA[i] = loadQuadraticProbing(dataA, quadraticHash, i * 100, (i * 100) + 100)/100;
        cSearchA[i] = searchChaining(random, 100, hashChain)/100;
        lPSearchA[i] = searchLinearProbing(random, 100, linearHash)/100;
        lLSearchA[i] = searchLinkedList(random, 100, list)/100;
        bSTSearchA[i] = searchBST(random, 100, tree)/100;
        QPSearchA[i] = searchQuadraticProbing(random, 100, quadraticHash)/100;
    }
    //call a deconstructor for all of the data structurs 
    hashChain.~Chaining();
    linearHash.~LinearProbing();
    list.~LinkedList();
    tree.~bST();
    quadraticHash.~QuadraticProbing();
  
    //Data set B
    double cInsertB[400];
    double lPInsertB[400];
    double lLInsertB[400];
    double bSTInsertB[400];
    double QPInsertB[400];
    double cSearchB[400];
    double lPSearchB[400];
    double lLSearchB[400];
    double bSTSearchB[400];
    double QPSearchB[400];

    for (int i = 0; i < 400; i++) {
        for (int j = 0; j < 100; j++) {
            random[j] = dataB[rand() % ((i * 100) + 100)];
        }
        cInsertB[i] = loadChaining(dataB, hashChain, i * 100, (i * 100) + 100)/100;
        lPInsertB[i] = loadLinearProbing(dataB, linearHash, i * 100, (i * 100) + 100)/100;
        lLInsertB[i] = loadLinkedList(dataB, list, i * 100, (i * 100) + 100)/100;
        bSTInsertB[i] = loadBST(dataB, tree, i * 100, (i * 100) + 100)/100;
        QPInsertB[i] = loadQuadraticProbing(dataB, quadraticHash, i * 100, (i * 100) + 100)/100;
        cSearchB[i] = searchChaining(random, 100, hashChain)/100;
        lPSearchB[i] = searchLinearProbing(random, 100, linearHash)/100;
        lLSearchB[i] = searchLinkedList(random, 100, list)/100;
        bSTSearchB[i] = searchBST(random, 100, tree)/100;
        QPSearchB[i] = searchQuadraticProbing(random, 100, quadraticHash)/100;
    }


    ofstream mfile;

    //Chaining
    mfile.open("chaining.csv");
    mfile << "A" << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << cInsertA[i] << ",";
    }
    mfile << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << cSearchA[i] << ",";
    }
    mfile << endl << "B" << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << cInsertB[i] << ",";
    }
    mfile << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << cSearchB[i] << ",";
    }
    mfile.close();


    //Linear Probing
    mfile.open("linearProbing.csv");
    mfile << "A" << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << lPInsertA[i] << ",";
    }
    mfile << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << lPSearchA[i] << ",";
    }
    mfile << endl << "B" << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << lPInsertB[i] << ",";
    }
    mfile << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << lPSearchB[i] << ",";
    }
    mfile << endl;
    mfile.close();

    //Linked List
    mfile.open("linkedList.csv");
    mfile << "A" << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << lLInsertA[i] << ",";
    }
    mfile << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << lLSearchA[i] << ",";
    }
    mfile << endl << "B" << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << lLInsertB[i] << ",";
    }
    mfile << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << lLSearchB[i] << ",";
    }
    mfile.close();

    //BST
    mfile.open("BST.csv");
    mfile << "A" << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << bSTInsertA[i] << ",";
    }
    mfile << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << bSTSearchA[i] << ",";
    }
    mfile << endl;
    mfile << "B" << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << bSTInsertB[i] << ",";
    }
    mfile << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << bSTSearchB[i] << ",";
    }
    mfile << endl;
    mfile.close();

    //Quadratic Probing
    mfile.open("quadraticProbing.csv");
    mfile << "A" << endl;
    for (int i = 0; i < 400; i++) {
        mfile << QPInsertA[i] << ",";
    }
    mfile << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << QPSearchA[i] << ",";
    }
    mfile << endl;
    mfile << "B" << endl;
    for (int i = 0; i < 400; i++) {
        mfile << QPInsertB[i] << ",";
    }
    mfile << endl;
    for(int i = 0; i < 400;i++)
    {
        mfile << QPSearchB[i] << ",";
    }
    mfile.close();
}
