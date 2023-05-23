#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t **sorted;
    listint_t *current;
    listint_t **insertion_point;

    if (*list == NULL || (*list)->next == NULL)
        return;

    sorted = list;
    insertion_point = sorted;
    while ((*sorted)->next && (*sorted)->next != NULL)
    {
        (*sorted) = (*sorted)->next;
    }
    while ((*sorted)->prev && (*sorted)->prev == NULL)
    {
        current = (*sorted)->prev;
        if ((current->n) > ((*sorted)->n))/*sorted doit etre toujours superieur a courent*/
        {
            (*insertion_point)->prev = current;
        }     
        (*sorted) = (*sorted)->prev;
    }
    list = insertion_point;
}
