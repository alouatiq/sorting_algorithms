#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
    int *count, *output;
    int max = 0;
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];

    /* Allocate and initialize count array */
    count = malloc((max + 1) * sizeof(int));
    if (!count)
        return;
    for (i = 0; i <= (size_t)max; i++)
        count[i] = 0;

    /* Store the count of each element */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Print the counting array */
    print_array(count, max + 1);

    /* Update count array to store the actual positions */
    for (i = 1; i <= (size_t)max; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    output = malloc(size * sizeof(int));
    if (!output)
    {
        free(count);
        return;
    }
    for (i = size; i > 0; i--)
    {
        output[count[array[i - 1]] - 1] = array[i - 1];
        count[array[i - 1]]--;
    }

    /* Copy the sorted output array into original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}
