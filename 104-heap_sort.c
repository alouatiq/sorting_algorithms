#include <stdio.h>
#include "sort.h"

/* Helper function prototype */
void heapify(int *array, size_t size, size_t root);

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;  /* Change ssize_t to int for compatibility */

    if (array == NULL || size < 2)
        return;

    /* Build the heap (rearrange array) */
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    /* Extract elements from the heap one by one */
    for (i = size - 1; i > 0; i--)
    {
        /* Move current root to end */
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        print_array(array, size);

        /* Call heapify on the reduced heap */
        heapify(array, i, 0);
    }
}

/**
 * heapify - Maintains the max-heap property
 * for a subtree rooted at index root
 * @array: Array representing the heap
 * @size: Total size of the heap
 * @root: Index of the root of the subtree
 */
void heapify(int *array, size_t size, size_t root)
{
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    /* If left child is larger than root */
    if (left < size && array[left] > array[largest])
        largest = left;

    /* If right child is larger than largest so far */
    if (right < size && array[right] > array[largest])
        largest = right;

    /* If largest is not root */
    if (largest != root)
    {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;

        /* Recursively heapify the affected sub-tree */
        heapify(array, size, largest);
    }
}
