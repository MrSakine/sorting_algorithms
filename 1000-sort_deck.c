#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "deck.h"

/**
 * compare_cards - This function is used as a comparator
 * for the qsort function. It compares two cards to
 * determine their order in the sorted array.
 * @a: pointer to the first card.
 * @b: pointer to the second card.
 * Return:  integer less than, equal to,
 * or greater than zero if the first card
 * is considered to be respectively less than,
 * equal to, or greater than the second card.
*/
int compare_cards(const void *a, const void *b)
{
	const card_t *card1 = ((deck_node_t *)a)->card;
	const card_t *card2 = ((deck_node_t *)b)->card;
	int value1, value2;

	if (strcmp(card1->value, "Ace") == 0)
		value1 = 1;
	else if (strcmp(card1->value, "Jack") == 0)
		value1 = 11;
	else if (strcmp(card1->value, "Queen") == 0)
		value1 = 12;
	else if (strcmp(card1->value, "King") == 0)
		value1 = 13;
	else
		value1 = atoi(card1->value);

	if (strcmp(card2->value, "Ace") == 0)
		value2 = 1;
	else if (strcmp(card2->value, "Jack") == 0)
		value2 = 11;
	else if (strcmp(card2->value, "Queen") == 0)
		value2 = 12;
	else if (strcmp(card2->value, "King") == 0)
		value2 = 13;
	else
		value2 = atoi(card2->value);

	if (value1 != value2)
		return (value1 - value2);

	return (card1->kind - card2->kind);
}

/**
* sort_deck - This function sorts a doubly-linked
* list of cards (deck) using the qsort algorithm.
* @deck: pointer to the head of the doubly-linked list.
* Return: Nothing.
*/
void sort_deck(deck_node_t **deck)
{
	size_t size = 0, i;
	deck_node_t **deck_array, *current;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	current = *deck;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	deck_array = malloc(size * sizeof(deck_node_t *));
	if (deck_array == NULL)
		return;

	current = *deck;
	for (i = 0; i < size; ++i)
	{
		deck_array[i] = current;
		current = current->next;
	}

	qsort(deck_array, size, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < size; ++i)
	{
		deck_array[i]->prev = (i > 0) ? deck_array[i - 1] : NULL;
		deck_array[i]->next = (i < size - 1) ? deck_array[i + 1] : NULL;
	}

	*deck = deck_array[0];

	free(deck_array);
}
