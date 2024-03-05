#include "sort.h"

/* https://en.wikipedia.org/wiki/Selection_sort */

void swap(int *a, int *b);
int partition(int *array, int low, int high, size_t size);
void quick_sort_wrapper(int *array, int low, int high, size_t size);


/**
 * swap - swap values at index
 * @a: index to swap
 * @b: index to swap with
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - use lomuto partion scheme
 * @array: array
 * @low: low index
 * @high: high index
 * @size: size of array
 * Return: index where the pivot element ends up
 * after the paritioning process
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_wrapper - recursively sort the array
 * @array: array
 * @low: low index
 * @high: high index
 * @size: size of array
 * Return: void
 */

void quick_sort_wrapper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_wrapper(array, low, pivot - 1, size);
		quick_sort_wrapper(array, pivot + 1, high, size);
	}
}


/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array
 * @size: size
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_wrapper(array, 0, size - 1, size);
}








