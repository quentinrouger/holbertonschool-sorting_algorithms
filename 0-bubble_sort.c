#include "sort.h"

/**
 * bubble_sort - Trie un tableau d'entiers en utilisant l'algorithme Bubble Sort.
 *
 * @array: Le tableau à trier.
 * @size: La taille du tableau.
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j, k;
    int temp;

    for (i = 0; i < size - 1; i++) 
    {
        for (j = 0; j < size - i - 1; j++) 
        {
            if (array[j] > array[j + 1]) 
            {
                /* Échange des éléments */
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                /* Affichage du tableau après l'échange */
                for (k = 0; k < size; k++) 
                {
                    printf("%d ", array[k]);
                }
                printf("\n");
            }
        }
    }
}
