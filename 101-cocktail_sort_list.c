#include "sort.h"

/**
 * swap_from_ahead - swap nodes from head
 *
 * @head: head of doubly linked list.
 * @behind: tail of doubly linked list.
 * @temp: node to insert in the doubly linked list
 *
 * Return: Nothing (void)
 */
void swap_from_ahead(listint_t **head, listint_t **behind, listint_t **temp)
{
	listint_t *t;

	t = (*temp)->next;

	if ((*temp)->prev != NULL)
		(*temp)->prev->next = t;
	else
		*head = t;

	t->prev = (*temp)->prev;
	(*temp)->next = t->next;

	if (t->next != NULL)
		t->next->prev = *temp;
	else
		*behind = *temp;

	(*temp)->prev = t;
	t->next = (*temp);
	(*temp) = t;
}

/**
 * swap_from_behind - swap nodes from behind
 *
 * @head: head of doubly linked list.
 * @behind: tail of doubly linked list.
 * @temp: node to insert in the doubly linked list
 *
 * Return: Nothing (void)
 */
void swap_from_behind(listint_t **head, listint_t **behind, listint_t **temp)
{
	listint_t *t;

	t = (*temp)->prev;

	if ((*temp)->next != NULL)
		(*temp)->next->prev = t;
	else
		*behind = t;

	t->next = (*temp)->next;
	(*temp)->prev = t->prev;

	if (t->prev != NULL)
		t->prev->next = (*temp);
	else
		*head = *temp;

	(*temp)->next = t;
	t->prev = (*temp);
	(*temp) = t;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: doubly linked list.
 * Return: Nothing (void)
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *from_behind;
	listint_t *temp;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	from_behind = (*list);

	while (from_behind->next != NULL)
		from_behind = from_behind->next;

	while (swapped == 1)
	{
		swapped = 0;
		for (temp = *list; temp != from_behind; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_from_ahead(list, &from_behind, &temp);
				print_list(*list);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		for (temp = temp->prev; temp != *list; temp = temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_from_behind(list, &from_behind, &temp);
				print_list(*list);
				swapped = 1;
			}
		}
	}
}
