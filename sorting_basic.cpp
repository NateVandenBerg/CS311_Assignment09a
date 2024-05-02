/**
 * Implemention of selected sorting algorithms
 * @file sorting.cpp
 */

#include "sorting.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

/** 
 * Implement the insertionSort algorithm correctly
 */
void insertionSort(int array[], int lowindex, int highindex, bool reversed) {
    //sort in descending order
    if (reversed == true) {
        for (int i = lowindex; i <= highindex; i++) {
            int j = i;
            while (j > 0 && array[j-1] < array[j]) {
                // Swap numbers[j] and numbers [j - 1]
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                j--;
            }
        }
        return;
    }

    else//sort in ascending order
    for (int i = lowindex; i <= highindex; i++) {
        int j = i;
        while (j > 0 && array[j] < array[j-1]) {
            // Swap numbers[j] and numbers [j - 1]
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
}
/**
 * @brief Implementation of the partition function used by quick sort
 * 
 */
int partition(int array[], int lowindex, int highindex, bool reversed) {
    int midpoint = lowindex + (highindex - lowindex) / 2;
    int pivot = array[midpoint];
    int low = lowindex;
    int high = highindex;

    bool done = false;


    if (reversed == true) {
        while (!done) {
            // increase low by 1 while array[low] > pivot
            while (array[low] > pivot) {
                low = low + 1;
            }

            // reduce high by 1 while pivot > array[high]
            while (pivot > array[high]) {
                high = high - 1;
            }

            // If low and high have crossed each other, the loop
            // is done. If not, the elements are swapped, low is
            // incremented and high is decremented.
            if (low >= high) {
                done = true;
            }
            else {
                int temp = array[low];
                array[low] = array[high];
                array[high] = temp;
                low = low + 1;
                high = high - 1;
            }
        }

        // "high" is the last index in the left partition.
        return high;
    }

    else if (reversed == false) {
        while (!done) {
            // increase low by 1 while array[low] < pivot
            while (array[low] < pivot) {
                low = low + 1;
            }

            // reduce high by 1 while pivot < array[high]
            while (pivot < array[high]) {
                high = high - 1;
            }

            // If low and high have crossed each other, the loop
            // is done. If not, the elements are swapped, low is
            // incremented and high is decremented.
            if (low >= high) {
                done = true;
            }
            else {
                int temp = array[low];
                array[low] = array[high];
                array[high] = temp;
                low = low + 1;
                high = high - 1;
            }
        }
        
    }
    // "high" is the last index in the left partition.
    return high;
}

/**
 * Implement the quickSort algorithm correctly
 */
void quickSort(int array[], int lowindex, int highindex, bool reversed) {
    // Only sort if at least 2 elements exist
    while (lowindex < highindex) {
        int high = partition(array, lowindex, highindex,reversed);
        if (high - lowindex <= highindex - (high + 1)) {
            quickSort(array, lowindex, high, reversed);
            lowindex = high + 1;
        }
        else {
            quickSort(array, high + 1, highindex, reversed);
            highindex = high;
        }
    }



    // Partition the array
    //int high = partition(array, lowindex, highindex, reversed);

    // Recursively sort the left partition
    //quickSort(array, lowindex, high, reversed);

    // Recursively sort the right partition
    //quickSort(array, high + 1, highindex, reversed);
}


