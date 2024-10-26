#include "sort.h"
#include <stdlib.h>

/**
	* get_max - Finds the maximum value in an array.
	* @array: The array
	* @size: The size of the array
	* Return: The maximum integer in the array
	*/
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	if (array[i] > max)
	max = array[i];
	return (max);
}

/**
	* counting_sort_radix - Performs counting sort based on a digit represented by exp.
	* @array: The array to be sorted
	* @size: Size of the array
	* @exp: Exponent representing the current digit place
	*/
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (!output)
	return;

	/* Store count of occurrences */
	for (i = 0; i < size; i++)
	count[(array[i] / exp) % 10]++;

	/* Change count[i] to contain the actual position of the digit */
	for (i = 1; i < 10; i++)
	count[i] += count[i - 1];

	/* Build the output array */
	for (i = size; i > 0; i--)
	{
	output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
	count[(array[i - 1] / exp) % 10]--;
	}

	/* Copy the output array to array[] */
	for (i = 0; i < size; i++)
	array[i] = output[i];

	free(output);
	print_array(array, size); /* Print the array after each significant digit sort */
}

/**
	* radix_sort - Sorts an array of integers in ascending order using Radix sort.
	* @array: The array to be sorted
	* @size: Size of the array
	*/
void radix_sort(int *array, size_t size)
{
	int max;
	int exp;

	if (array == NULL || size < 2)
	return;

	max = get_max(array, size);

	/* Apply counting sort for each digit (1's, 10's, 100's, etc.) */
	for (exp = 1; max / exp > 0; exp *= 10)
	counting_sort_radix(array, size, exp);
}
