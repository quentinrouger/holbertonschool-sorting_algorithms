#include "sort.h"

/**
 * selection_sort - Trie un tableau d'entiers par ordre croissant en utilisant
 *                  l'algorithme de tri par selection.
 * @array: Le tableau d'entiers a trier.
 * @size: La taille du tableau.
 */
void selection_sort(int *array, size_t size)
{
    size_t i, init, temp, j;

    for (i = 0; i < size - 1; i++)
    {
        init = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[init])
                init = j;
        }
        if (array[i] != array[init])
        {
            temp = array[i];
            array[i] = array[init];
            array[init] = temp;
            print_array(array, size);
        }
    }
}
