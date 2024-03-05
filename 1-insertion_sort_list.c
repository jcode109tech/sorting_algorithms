#include "sort.h"

/*
* insertion_sort_list -a  function that sorts a
* doubly linked list of integers in ascending order
* using the Insertion sort algorithm
* @list: list
* Return: Void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		prev = current->prev;

		while (prev != NULL && temp->n < prev->n)
		{
			if (temp->next != NULL)
				temp->next->prev = prev;

			if (prev->prev != NULL)
				prev->prev->next = temp;

			temp->prev = prev->prev;
			prev->next = temp->next;
			prev->prev = temp;
			temp->next = prev;

			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);

			prev = temp->prev;
		}

		current = current->next;
	}
}
/**
 * void insertionSort(int arr[], int n) {
 *  int i, key, j;
 *  for (i = 1; i < n; i++) {
 *      key = arr[i];
 *      j = i - 1;
 *       Move elements of arr[0..i-1], that are greater than key,
 *      to one position ahead of their current position
 *      while (j >= 0 && arr[j] > key) {
 *          arr[j + 1] = arr[j];
 *      j = j - 1;
 *      }
 *      arr[j + 1] = key;
 *  }
 *}
*/
