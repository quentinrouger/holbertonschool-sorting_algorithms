#include "sort.h"

/**
 * changement - swap the values of p1 and p2
 * @p1: pointer to the first integer
 * @p2: pointer to the second integer
 *
*/
void changement(int *p1, int *p2)
{
	int temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

/**
 * partition - Function that divides the array into unsorted parts.
 * @array: The array to sort
 * @deb: The first element of the array
 * @fin: The last element of the array
 * @size: The size of the array
 * Return: the index
*/
int partition(int *array, int deb, int fin, int size)
{
	int pivot = array[fin];
	int i = (deb - 1);
	int j = 0;

	for (j = deb; j <= fin; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			changement(&array[j], &array[i]);
			if (i != j)
				print_array(array, size);
		}
	}
	if (array[i] > pivot)
	{
		changement(&array[i], &array[fin]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_bis - Function that sorts the array.
 * @array: The array to sort
 * @deb: The first element of the array
 * @fin: The last element of the array
 * @size: The size of the array
 *
*/
void quick_sort_bis(int *array, int deb, int fin, int size)
{
	int result;

	if (deb < fin)
	{
		result = partition(array, deb, fin, size);
		quick_sort_bis(array, deb, result - 1, size);
		quick_sort_bis(array, result + 1, fin, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array
 * @size: Number of elements in the array
 *
*/
void quick_sort(int *array, size_t size)
{
	int deb;
	int fin;

	if (array == NULL || size < 2)
		return;

	deb = 0;
	fin = size - 1;

	quick_sort_bis(array, deb, fin, size);
}
