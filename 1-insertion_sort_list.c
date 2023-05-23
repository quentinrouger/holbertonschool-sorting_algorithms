#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order
 * @list: The linked list
 *
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *newNode;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	newNode = (*list)->next;

	while (newNode != NULL)
	{
		while (newNode->prev && newNode->n < newNode->prev->n)
		{
			newNode->prev->next = newNode->next;
			if (newNode->next)
				newNode->next->prev = newNode->prev;
			newNode->next = newNode->prev;
			newNode->prev = newNode->prev->prev;
			if (newNode->prev)
				newNode->prev->next = newNode;

			newNode->next->prev = newNode;

			if (!newNode->prev)
				*list = newNode;
			print_list(*list);
		}
		newNode = newNode->next;
	}
}
