#include "sort.h"

/* Forward declarations */
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);

/**
	* quick_sort - Sorts an array of integers
	* in ascending order using Quick Sort
	* @array: Pointer to the array to sort
	* @size: Number of elements in the array
	*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
	* quick_sort_recursive - Helper recursive function for Quick Sort
	* @array: Pointer to the array
	* @low: Start index of the partition
	* @high: End index of the partition
	* @size: Total size of the array (for printing)
	*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
	int pi = lomuto_partition(array, low, high, size);

	quick_sort_recursive(array, low, pi - 1, size);

	quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
	* lomuto_partition - Lomuto partition scheme for Quick Sort
	* @array: Pointer to the array
	* @low: Start index
	* @high: End index (pivot)
	* @size: Total size of the array (for printing)
	* Return: The partitioning index
	*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int temp;

	for (int j = low; j < high; j++)
	{
	if (array[j] <= pivot)
	{
	i++;
	if (i != j)
	{
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
	}
	}
	}
	if (i + 1 != high)
	{
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);
	}
	return (i + 1);
}
