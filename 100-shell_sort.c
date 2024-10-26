#include "sort.h"

/**
 * shell_sort - Sorts an array of integers
 * in ascending order using Shell sort
 *              with the Knuth sequence.
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1;
    size_t i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    /* Generate initial Knuth sequence gap */
    while (gap < size / 3)
        gap = gap * 3 + 1;

    /* Perform shell sort */
    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];
            array[j] = temp;
        }
        print_array(array, size);
      /* Print the array after each gap reduction */
        gap = (gap - 1) / 3;
    }
}
