#include "sort.h"

void quick_sort(int *array, size_t size)
{
    size_t deb = 0;
    size_t fin = size - 1;
    partition(array, deb, fin);
    print_array(array, size);
}

void partition(int *array, size_t deb, size_t fin)
{
    int pivot = array[fin];
    size_t i = deb - 1;
    size_t j = 0;
    int temp;
    size_t ipivot;

    if (deb < fin)
    {
        for (j = deb; j < fin; j++)
        {
            if (array[j] <= pivot)
            {
                i++;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        
        temp = array[i + 1];
        array[i + 1] = array[fin];
        array[fin] = temp;
        
        ipivot = i + 1;
        
        partition(array, deb, ipivot - 1);
        partition(array, ipivot + 1, fin);
    }
}
