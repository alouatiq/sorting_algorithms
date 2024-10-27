#include <stdio.h>
#include "sort.h"

/* Helper function prototypes */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int direction);
void bitonic_merge(int *array, size_t low, size_t count, int direction);

/**
	* bitonic_sort - Sorts an array of integers in ascending order
	* using the Bitonic sort algorithm
	* @array: Array to be sorted
	* @size: Size of the array
	*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	bitonic_sort_recursive(array, 0, size, 1);
}

/**
	* bitonic_sort_recursive - Recursively sorts a bitonic sequence
	* @array: Array to be sorted
	* @low: Starting index of the sequence
	* @count: Number of elements in the sequence
	* @direction: 1 for ascending, 0 for descending
	*/
void bitonic_sort_recursive(int *array, size_t low, size_t count, int direction)
{
	size_t k;  /* Declaration moved to the top */

	if (count > 1)
	{
	k = count / 2;
	bitonic_sort_recursive(array, low, k, 1);
	bitonic_sort_recursive(array, low + k, k, 0);
	bitonic_merge(array, low, count, direction);
	}
}

/**
	* bitonic_merge - Merges two bitonic sequences
	* @array: Array to be merged
	* @low: Starting index of the sequence
	* @count: Number of elements in the sequence
	* @direction: 1 for ascending, 0 for descending
	*/
void bitonic_merge(int *array, size_t low, size_t count, int direction)
{
	size_t i, k;  /* Declaration moved to the top */

	if (count > 1)
	{
	k = count / 2;
	for (i = low; i < low + k; i++)
	{
	if ((direction == 1 && array[i] > array[i + k]) ||
	(direction == 0 && array[i] < array[i + k]))
	{
	int temp = array[i];
	array[i] = array[i + k];
	array[i + k] = temp;
	}
	}
	bitonic_merge(array, low, k, direction);
	bitonic_merge(array, low + k, k, direction);
	}
}
