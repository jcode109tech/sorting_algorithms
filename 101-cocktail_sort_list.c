#include "sort.h"


/**
 * swap_nodes - swaps nodes by use of cocktail_shaker_sort
 * https://en.wikipedia.org/wiki/Cocktail_shaker_sort
 * @list: doubly list
 * @a: node 
 * @b: node
 * Return: void
*/
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
    listint_t *temp;

    if (a->prev != NULL)
        a->prev->next = b;
    else
        *list = b;
    if (b->next != NULL)
        b->next->prev = a;

    temp = b->next;
    b->next = a;
    a->prev = b;
    a->next = temp;
    b->prev = a->prev;
    if (temp != NULL)
        temp->prev = a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list 
 * of integers in ascending order using the 
 * Cocktail shaker sort algorithm
 * @list: Pointer to a pointer to the head of the list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *ptr;

    if (list == NULL || *list == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        for (ptr = *list; ptr->next != NULL; ptr = ptr->next)
        {
            if (ptr->n > ptr->next->n)
            {
                swap_nodes(list, ptr, ptr->next);
                swapped = 1;
                print_list(*list);
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (; ptr->prev != NULL; ptr = ptr->prev)
        {
            if (ptr->n < ptr->prev->n)
            {
                swap_nodes(list, ptr->prev, ptr);
                swapped = 1;
                print_list(*list);
            }
        }
    }
}
