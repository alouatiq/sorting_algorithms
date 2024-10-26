#include "sort.h"

/**
	* bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort.
	* @array: The array to be sorted
	* @size: Size of the array
	*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	bitonic_sort_recursive(array, 0, size, 1);
}

/**
	* bitonic_sort_recursive - Recursively sorts a bitonic sequence.
	* @array: The array
	* @low: Starting index
	* @count: Number of elements in the sequence
	* @direction: 1 for ascending, 0 for descending
	*/
void bitonic_sort_recursive(int *array, size_t low, size_t count, int direction)
{
	if (count < 2)
	return;

	size_t k = count / 2;

	bitonic_sort_recursive(array, low, k, 1);
	bitonic_sort_recursive(array, low + k, k, 0);
	bitonic_merge(array, low, count, direction);
}

/**
	* bitonic_merge - Merges two halves of a bitonic sequence.
	* @array: The array
	* @low: Starting index
	* @count: Number of elements in the sequence
	* @direction: 1 for ascending, 0 for descending
	*/
void bitonic_merge(int *array, size_t low, size_t count, int direction)
{
	if (count < 2)
	return;

	size_t k = count / 2;
	size_t i;

	for (i = low; i < low + k; i++)
	if (direction == (array[i] > array[i + k]))
	{
	int temp = array[i];
	array[i] = array[i + k];
	array[i + k] = temp;
	print_array(array, count); /* Print after every swap */
	}

	bitonic_merge(array, low, k, direction);
	bitonic_merge(array, low + k, k, direction);
}
