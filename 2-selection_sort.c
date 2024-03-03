#include "sort.h"


void swap(int *ar, int *pos);

/**
 * selection_sort - a function that sorts an array of integers 
 * in ascending order using the Selection sort algorithm
 * @array: array
 * @size: size
 * Return: void
*/

void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i+1; j < size; j++)
        {
            if (array[j] < array[min_idx])
            {
                min_idx = j;
                print_array(array, size);
            }
        }

        swap(&array[min_idx], &array[i]);
    }
}


/**
 * swap - swap 
 * @ar: to swap
 * @pos: to swap
 * Return: void
*/

void swap(int *ar, int *pos)
{
    int temp = *ar;
    *ar = *pos;
    *pos = temp;
}
