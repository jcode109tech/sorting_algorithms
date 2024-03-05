#include "sort.h"


/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */


void counting_sort(int *array, size_t size)
{
    int max = 0;
    int i, j;
    int Sizet = size;
    int *count = NULL;
    int *sorted_array = NULL;

    if (array == NULL || size < 2)
		return;
    
    for (i = 0; i < Sizet; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
        return;

    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < Sizet; i++)
    {
        count[array[i]]++;
    }

   
    printf("Counting array:");
    for (i = 0; i <= max; i++)
    {
        printf(" %d", count[i]);
    }
    printf("\n");

    sorted_array = malloc(sizeof(int) * size);
    if (sorted_array == NULL)
    {
        free(count);
        return;
    }

    j = 0;
    for (i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            sorted_array[j++] = i;
            count[i]--;
        }
    }

    for (i = 0; i < Sizet; i++)
    {
        array[i] = sorted_array[i];
    }

    free(count);
    free(sorted_array);
}

