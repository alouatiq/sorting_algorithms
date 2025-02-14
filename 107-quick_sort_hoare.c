#include "sort.h"

/* Forward declarations */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);

/**
	* quick_sort_hoare - Sorts an array of integers in ascending order using
	*                    the Quick sort algorithm with Hoare partition scheme.
	* @array: The array to be sorted
	* @size: Size of the array
	*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	quick_sort_hoare_recursive(array, 0, size - 1, size);
}

/**
	* quick_sort_hoare_recursive - Recursively sorts an array using Quick sort.
	* @array: The array to be sorted
	* @low: Starting index
	* @high: Ending index
	* @size: Size of the array
	*/
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
	int p = hoare_partition(array, low, high, size);
	quick_sort_hoare_recursive(array, low, p, size);
	quick_sort_hoare_recursive(array, p + 1, high, size);
	}
}

/**
	* hoare_partition - Hoare partition scheme for Quick Sort.
	* @array: The array to be partitioned
	* @low: Starting index
	* @high: Ending index
	* @size: Size of the array
	* Return: Partition index
	*/
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1;
	int j = high + 1;
	int temp;

	while (1)
	{
	do {
	i++;
	} while (array[i] < pivot);

	do {
	j--;
	} while (array[j] > pivot);

	if (i >= j)
	return j;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size); /* Print array after each swap */
	}
}
