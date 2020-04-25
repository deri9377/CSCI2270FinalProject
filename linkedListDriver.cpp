#include <iostream>
#include <fstream>
#include "linkedList.hpp"
#include "ctime"
using namespace std;

int main() {
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
    list.display();
    cout << "It took: (" << (double)t/CLOCKS_PER_SEC << " seconds) to load the first 100 elemets" << endl;
}