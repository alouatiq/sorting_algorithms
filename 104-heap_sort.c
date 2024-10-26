#include "sort.h"

/**
	* heap_sort - Sorts an array of integers
	* in ascending order using Heap sort.
	* @array: Pointer to the array to be sorted
	* @size: Number of elements in the array
	*/
void heap_sort(int *array, size_t size)
{
	int temp;
	ssize_t i;

	if (array == NULL || size < 2)
	return;

	/* Build the max heap */
	for (i = size / 2 - 1; i >= 0; i--)
	heapify(array, size, i);

	/* Extract elements from the heap */
	for (i = size - 1; i > 0; i--)
	{
	/* Swap the root of the heap with the last element */
	temp = array[0];
	array[0] = array[i];
	array[i] = temp;
	print_array(array, size);

	/* Rebuild the heap with reduced size */
	heapify(array, i, 0);
	}
}

/**
	* heapify - Converts a subtree into a max heap.
	* @array: Pointer to the array
	* @size: Total size of the array
	* @root: Index of the root of the subtree
	*/
void heapify(int *array, size_t size, size_t root)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;
	int temp;

	/* If left child is larger than root */
	if (left < size && array[left] > array[largest])
	largest = left;

	/* If right child is larger than largest so far */
	if (right < size && array[right] > array[largest])
	largest = right;

	/* If largest is not root, swap and recursively heapify */
	if (largest != root)
	{
	temp = array[root];
	array[root] = array[largest];
	array[largest] = temp;
	print_array(array, size);
	heapify(array, size, largest);
	}
}
