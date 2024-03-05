#include "sort.h"

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
    size_t gap = 1, j, i;
    size_t k;

    
	if (array == NULL || size < 2)
		return;

    while (gap <= size / 3) 
    {
        gap = gap * 3 + 1; 
    }

    while (gap > 0) 
    {
        for (k = 0; k < size; k++) {
            print_array(array, size);
        }
        printf("\n");

        for (i = gap; i < size; i++) {
            j = i;
            while (j >= gap && array[j - gap] > array[i]) 
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = array[i];
        }
        gap = (gap - 1) / 3;
    }
}
