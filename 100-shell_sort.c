#include "sort.h"


void swap_values(int *a, int *b);

/**
 * shell_sort - perfors a shell sort using knuth sequence
 * https://en.wikipedia.org/wiki/Shellsort
 * knuth sequence
 * @array: array
 * @size: size of array
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_values(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}


/**
 * swap_values - Swap  in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_values(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

