#include "sort.h"
#include <stdlib.h>

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort.
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(sizeof(int) * size);
    if (!temp)
        return;

    merge_sort_recursive(array, temp, 0, size - 1);
    free(temp);
}

/**
 * merge_sort_recursive - Helper function to recursively split and merge.
 * @array: Pointer to the array
 * @temp: Temporary storage array
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    size_t mid;

    if (left < right)
    {
        mid = left + (right - left) / 2;
        merge_sort_recursive(array, temp, left, mid);
        merge_sort_recursive(array, temp, mid + 1, right);
        merge(array, temp, left, mid, right);
    }
}

/**
 * merge - Merges two sorted halves of an array.
 * @array: Pointer to the array
 * @temp: Temporary storage array
 * @left: Left index of the first half
 * @mid: Midpoint index
 * @right: Right index of the second half
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i, j, k;

    i = left;
    j = mid + 1;
    k = left;

    /* Merge the two halves */
    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    /* Copy remaining elements of left half */
    while (i <= mid)
        temp[k++] = array[i++];

    /* Copy remaining elements of right half */
    while (j <= right)
        temp[k++] = array[j++];

    /* Copy the sorted subarray into the original array */
    for (i = left; i <= right; i++)
        array[i] = temp[i];

    /* Print the merging result for visualization */
    print_array(array + left, right - left + 1);
}
