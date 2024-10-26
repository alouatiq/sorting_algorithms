#include "deck.h"
#include <string.h>

/**
	* compare_cards - Compares two cards based on their value and suit.
	* @card1: First card
	* @card2: Second card
	* Return: -1 if card1 is less than card2, 1 if greater, 0 if equal
	*/
int compare_cards(const card_t *card1, const card_t *card2)
{
	const char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
	"Jack", "Queen", "King"};
	int val1, val2;

	for (val1 = 0; val1 < 13; val1++)
	if (strcmp(card1->value, values[val1]) == 0)
	break;

	for (val2 = 0; val2 < 13; val2++)
	if (strcmp(card2->value, values[val2]) == 0)
	break;

	if (val1 != val2)
	return (val1 - val2);
	return (card1->kind - card2->kind);
}

/**
	* insertion_sort_deck - Sorts a deck of cards using insertion sort.
	* @deck: Double pointer to the head of the deck
	*/
void insertion_sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *next, *temp;

	if (!deck || !*deck || !(*deck)->next)
	return;

	current = (*deck)->next;
	while (current)
	{
	next = current->next;
	temp = current;

	while (temp->prev && compare_cards(temp->card, temp->prev->card) < 0)
	{
	/* Swap nodes */
	if (temp->next)
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	temp->next = temp->prev;
	temp->prev = temp->prev->prev;
	temp->next->prev = temp;

	if (temp->prev)
	temp->prev->next = temp;
	else
	*deck = temp;
	}
	current = next;
	}
}

/**
	* sort_deck - Sorts a deck of cards.
	* @deck: Double pointer to the head of the deck
	*/
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
	return;

	insertion_sort_deck(deck);
}
