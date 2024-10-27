#ifndef DECK_H
#define DECK_H

/**
	* enum kind_e - Enumeration of card suits.
	* @SPADE: Spade suit
	* @HEART: Heart suit
	* @CLUB: Club suit
	* @DIAMOND: Diamond suit
	*/
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
	* struct card_s - Playing card structure
	* @value: The card value, ranging from "Ace" to "King"
	* @kind: The suit of the card (SPADE, HEART, CLUB, DIAMOND)
	*/
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
	* struct deck_node_s - Node of a doubly linked list representing a deck of cards
	* @card: Pointer to the card data for this node
	* @prev: Pointer to the previous node in the deck
	* @next: Pointer to the next node in the deck
	*/
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* Function prototypes */
void sort_deck(deck_node_t **deck);
void print_deck(const deck_node_t *deck); /* Add if needed in other files */

#endif /* DECK_H */
