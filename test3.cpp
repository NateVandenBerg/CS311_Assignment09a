/**
 * This file tests the implementation of "optimized" quick sort.
 * It will compare its performance to that of a standard quick sort algorithm
 */
#include "sorting.h"
#include "print_array.h"
#include <chrono>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    
    int arraySize[] = { 10, 16, 32, 64, 128, 256, 512, 1024,
                        2048, 4096, 8192, 16384, 32768, 65536,
                        13072, 262144, 524288};
    ofstream myfile;
    
    myfile.open("QuickSort.txt");
    cout << "quickSort";
    for (auto i : arraySize) {
        string str;
        int arrayAscend[i];
        int arrayDescend[i];
        int arrayRandom[i];

        //add values in the ascending array
        for (int j = 0; j < i; j++) {
            arrayAscend[j] = j;
        }

        str += "\n\nsize: ";
        str += to_string(i);

        str += "\nascending\n";
        cout << "\n\n size: " << i;
        cout<< "\nQuickSort\nascending\n\tProgress: ";
        //run quicksort for ascending array 40 times
        for (int k = 0; k < 5; k++) {
            auto t1 = std::chrono::high_resolution_clock::now();
            quickSort(arrayAscend, 0, i - 1, false);
            auto t2 = std::chrono::high_resolution_clock::now();
            str += to_string(std::chrono::duration_cast<std::chrono::duration<double>>((t2 - t1)*10000).count()) + "\t";
            cout << "[]";
        }

        str += "\ndescending\n";
        cout << "\ndescending\n\tProgress: ";
        //run quicksort for descending array 40 times
        for (int k = 0; k < 5; k++) {
            //update values in the descending array after each sort
            for (int j = 0; j < i; j++) {
                arrayDescend[j] = j * (-1);
            }
            auto t1 = std::chrono::high_resolution_clock::now();
            quickSort(arrayDescend, 0, i - 1, false);
            auto t2 = std::chrono::high_resolution_clock::now();
            str += to_string(std::chrono::duration_cast<std::chrono::duration<double>>((t2 - t1)*10000).count()) + "\t";
            cout << "[]";
        }

        str += "\nrandom\n";
        cout << "\nrandom\n\tProgress: ";
        //run quicksort for random array 40 times
        for (int k = 0; k < 5; k++) {
            //update values in the random array after each sort
            for (int j = 0; j < i; j++) {
                arrayRandom[j] = rand() % i;
            }
            auto t1 = chrono::high_resolution_clock::now();
            quickSort(arrayRandom, 0, i - 1, false);
            auto t2 = chrono::high_resolution_clock::now();
            str += to_string(std::chrono::duration_cast<std::chrono::duration<double>>((t2 - t1)*10000).count()) + "\t";
            cout << "[]";
        }
        //add the runtimes to the .txt file
        myfile << str;
    }
    myfile.close();

    myfile.open("insertionSort.txt");
    cout << "insertionSort";
    for (auto i : arraySize) {
        string str;
        int arrayAscend[i];
        int arrayDescend[i];
        int arrayRandom[i];

        //add values in the ascending array
        for (int j = 0; j < i; j++) {
            arrayAscend[j] = j;
        }

        str += "\n\nsize: ";
        str += to_string(i);

        str += "\nascending\n";
        cout << "\n\n size: " << i;
        cout << "\nInsertionSort\nascending\n\tProgress: ";
        //run insertionSort for ascending array 40 times
        for (int k = 0; k < 5; k++) {
            auto t1 = std::chrono::high_resolution_clock::now();
            insertionSort(arrayAscend, 0, i - 1, false);
            auto t2 = std::chrono::high_resolution_clock::now();
            str += to_string(std::chrono::duration_cast<std::chrono::duration<double>>((t2 - t1) * 10000).count()) + "\t";
            cout << "[]";
        }

        str += "\ndescending\n";
        cout << "\ndescending\n\tProgress: ";
        //run insertionSort for descending array 40 times
        for (int k = 0; k < 5; k++) {
            //update values in the descending array after each sort
            for (int j = 0; j < i; j++) {
                arrayDescend[j] = j * (-1);
            }
            auto t1 = std::chrono::high_resolution_clock::now();
            insertionSort(arrayDescend, 0, i - 1, false);
            auto t2 = std::chrono::high_resolution_clock::now();
            str += to_string(std::chrono::duration_cast<std::chrono::duration<double>>((t2 - t1) * 10000).count()) + "\t";
            cout << "[]";
        }

        str += "\nrandom\n";
        cout << "\nrandom\n\tProgress: ";
        //run insertionSort for ascending array 40 times
        for (int k = 0; k < 5; k++) {
            //update values in the random array after each sort
            for (int j = 0; j < i; j++) {
                arrayRandom[j] = rand() % i;
            }
            auto t1 = chrono::high_resolution_clock::now();
            insertionSort(arrayRandom, 0, i - 1, false);
            auto t2 = chrono::high_resolution_clock::now();
            str += to_string(std::chrono::duration_cast<std::chrono::duration<double>>((t2 - t1) * 10000).count()) + "\t";
            cout << "[]";
        }
        //add the runtimes to the .txt file
        myfile << str;
    }
    myfile.close();
    cout<<"\n\n";
    return 0;
}
