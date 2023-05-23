#include "sort.h"

void quick_sort(int *array, size_t size)
{
    size_t deb = 0;
    size_t fin = size - 1;
    if (array == NULL)
        return;
    if (size <= 1)
        return;
    partition(array, deb, fin, size);
    print_array(array, size);
}

void changement(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void quick_sort_desieme(int *array, int deb, int fin, int size)
{
    if (deb < fin)
    {
        int pivot = partition(array, deb, fin, size);
        quick_sort_desieme(array, deb, pivot -1, size);
        quick_sort_desieme(array, fin, pivot +1, size);
    }
}

int partition(int *array, int deb, int fin, int size)
{
    int pivot = array[fin];
    int i = deb;
    int j = 0;
    
     for (j = deb; j < fin; j++)
    {
        if (array[j] < pivot)
        {
            changement(&array[j], &array[i]);
            print_array(array, size);
        }
        i++;
    }
    if (array[i] > pivot)
    {
        changement(&array[i], &array[fin]);
        print_array(array, size);
    }
    return (i);
}
