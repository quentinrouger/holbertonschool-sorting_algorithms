#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *sorted = NULL;  /* Pointeur vers la position triée actuelle */
    listint_t *current = *list;  /* Pointeur vers le nœud actuel */

    if (*list == NULL || (*list)->next == NULL)
        return;

    while (current != NULL)
    {
        listint_t *next = current->next;  /* Pointeur vers le prochain nœud */

        while (sorted != NULL && sorted->n > current->n)
        {
            sorted = sorted->prev;  /* Déplace le pointeur vers la gauche */
        }

        if (sorted == NULL)
        {
            /* Insère le nœud au début de la liste */
            current->prev = NULL;
            current->next = *list;
            (*list)->prev = current;
            *list = current;
        }
        else
        {
            /* Insère le nœud à la position triée appropriée */
            current->prev = sorted;
            current->next = sorted->next;

            if (sorted->next != NULL)
                sorted->next->prev = current;

            sorted->next = current;
        }

        sorted = current;  /* Met à jour le pointeur vers la position triée actuelle */
        current = next;  /* Passe au prochain nœud */

    }
}
