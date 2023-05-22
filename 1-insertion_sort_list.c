#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    if (*list == NULL || (*list)->next == NULL)
        return;

    listint_t **sorted;
    listint_t *current;

    (*sorted) = *list;
    current = (*sorted)->next;

    while (current != NULL)
    {
        listint_t *insertion_point = (*sorted);
        listint_t *next = current->next;

        while (insertion_point != NULL && insertion_point->n > current->n)
        {
            insertion_point = insertion_point->prev;
        }

        if (insertion_point == NULL)
        {
            current->prev = NULL;
            current->next = (*sorted);
            (*sorted)->prev = current;
            (*sorted) = current;
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

    *list = (*sorted);
}
