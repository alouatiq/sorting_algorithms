#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/* Helper function prototypes */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right);
void merge(int *array, int *temp, size_t left, size_t mid, size_t right);

/**
	* merge_sort - Sorts an array of integers in ascending order
	* using the Merge sort algorithm
	* @array: Array to be sorted
	* @size: Size of the array
	*/
void merge_sort(int *array, size_t size)
{
	int *temp;  /* Declaration moved to the top */

	if (array == NULL || size < 2)
	return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
	return;

	merge_sort_recursive(array, temp, 0, size - 1);
	free(temp);
}

/**
	* merge_sort_recursive - Recursively sorts subarrays
	* @array: Array to be sorted
	* @temp: Temporary array to store merged elements
	* @left: Left index of the subarray
	* @right: Right index of the subarray
	*/
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	if (left < right)
	{
	size_t mid = left + (right - left) / 2;
	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid + 1, right);
	merge(array, temp, left, mid, right);
	}
}

/**
	* merge - Merges two sorted subarrays into a single sorted array
	* @array: Original array with subarrays to be merged
	* @temp: Temporary array to store merged elements
	* @left: Left index of the subarray
	* @mid: Middle index of the subarray
	* @right: Right index of the subarray
	*/
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right)
	{
	if (array[i] <= array[j])
	temp[k++] = array[i++];
	else
	temp[k++] = array[j++];
	}
	while (i <= mid)
	temp[k++] = array[i++];
	while (j <= right)
	temp[k++] = array[j++];

	for (i = left; i <= right; i++)
	array[i] = temp[i];

	/* Print array after each merge */
	print_array(array, right + 1);
}
