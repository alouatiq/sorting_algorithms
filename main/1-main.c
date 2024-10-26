#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list, or NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list = NULL, *node;
    int *tmp;

    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        if (list)
            list->prev = node;
        list = node;
    }
    return (list);
}

/**
 * main - Entry point for testing Insertion Sort on a doubly linked list
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);

    printf("Original list:\n");
    print_list(list);
    printf("\nSorting using Insertion Sort:\n");
    insertion_sort_list(&list);
    printf("\nSorted list:\n");
    print_list(list);
    return (0);
}
