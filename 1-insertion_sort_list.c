#include "sort.h"
/**
 * insertion_sort_list -  function that sorts a doubly linked list of integers
 *												in ascending order using the Insertion sort algorithm
 * @list: doubly linked list.
 * Return: Nothing (void)
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/*Swaping the nodes*/
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			/*Update the prev node next pointer*/
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

			/*print list after swap*/
			print_list(*list);
		}
		current = current->next;
	}
}
