/**
 * @brief You will implement the "optimized" quick sort algorithms for a linked list in this file
 */
#include "sorting.h"


/**
 * Implement a hybrid of insertion sort and quick sort algorithm. 
 * The algorithm is based on the idea that if the array is short,
 * it is better to use insertion sort.
 * It uses quicksort until the list gets small enough, and then 
 * uses insertion sort or another sort to sort the small lists
 *
 */


void hybridQuickSort(int array[], int lowindex, int highindex, bool reversed) {
    // Only sort if at least 2 elements exist
    if (highindex <= lowindex) {
        return;
    }

    if (highindex - lowindex <= 10) {//when partition size is less than 11 insertionSort is called as it is more efficient
        insertionSort(array, lowindex, highindex, reversed);
        return;
    }

    int high = partition(array, lowindex, highindex, reversed);

    // Recursively sort the left partition
    hybridQuickSort(array, lowindex, high, reversed);

    // Recursively sort the right partition
    hybridQuickSort(array, high + 1, highindex, reversed);
}