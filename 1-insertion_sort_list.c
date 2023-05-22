#include "sort.h"

/**
 * insertion_sort_list - Trie une liste doublement chaînée d'entiers en utilisant l'algorithme d'insertion.
 *
 * @list: Pointeur vers le pointeur de la liste à trier.
 */
void insertion_sort_list(listint_t **list)
{
	if (*list == NULL || (*list)->next == NULL)
		return;

	listint_t *sorted = *list; // Pointeur vers la position triée actuelle
	listint_t *current = sorted->next; // Pointeur vers le nœud suivant

	while (current != NULL)
	{
		listint_t *insertion_point = sorted;
		listint_t *next = current->next;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			insertion_point = insertion_point->prev;
		}

		if (insertion_point == NULL)
		{
			current->prev = NULL;
			current->next = sorted;
			sorted->prev = current;
			sorted = current;
		}
		else
		{
			current->prev = insertion_point;
			current->next = insertion_point->next;

			if (insertion_point->next != NULL)
				insertion_point->next->prev = current;

			insertion_point->next = current;
		}

		current = next;
	}

	*list = sorted;
}
