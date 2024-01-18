#include "sort.h"

/**
 * insertion_sort_list - a doubly linked list with
 * insertion sort algorithm.
 * @list: double pointer to head of linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *currentNode, *nextElement;

	if (list == NULL || (*list) == NULL)
		return;

	currentNode = (*list)->next;

	while (currentNode)
	{
		nextElement = currentNode->next;
		while (currentNode->prev != NULL && currentNode->prev->n > currentNode->n)
		{
			currentNode->prev->next = currentNode->next;

			if (currentNode->next != NULL)
				currentNode->next->prev = currentNode->prev;

			currentNode->next = currentNode->prev;
			currentNode->prev = currentNode->next->prev;
			currentNode->next->prev = currentNode;

			if (currentNode->prev == NULL)
				(*list) = currentNode;
			else
				currentNode->prev->next = currentNode;
			print_list(*list);
		}
		currentNode = nextElement;
	}
}
