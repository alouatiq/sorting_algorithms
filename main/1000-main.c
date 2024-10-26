#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

void print_deck(const deck_node_t *deck);  /* Forward declaration of print_deck */

/**
 * main - Entry point for testing deck sorting
 *
 * Return: Always 0
 */
int main(void)
{
    card_t cards[52] = {
        {"Jack", CLUB}, {"4", HEART}, {"3", HEART}, {"3", DIAMOND}, {"Queen", HEART},
        {"5", HEART}, {"5", SPADE}, {"10", HEART}, {"6", HEART}, {"5", DIAMOND},
        {"6", SPADE}, {"9", HEART}, {"7", DIAMOND}, {"Jack", SPADE}, {"Ace", DIAMOND},
        {"9", CLUB}, {"Jack", DIAMOND}, {"7", SPADE}, {"King", DIAMOND}, {"10", CLUB},
        {"King", SPADE}, {"8", CLUB}, {"9", SPADE}, {"6", CLUB}, {"Ace", CLUB},
        {"3", SPADE}, {"8", SPADE}, {"9", DIAMOND}, {"2", HEART}, {"4", DIAMOND},
        {"6", DIAMOND}, {"3", CLUB}, {"Queen", CLUB}, {"10", SPADE}, {"8", DIAMOND},
        {"8", HEART}, {"Ace", SPADE}, {"Jack", HEART}, {"2", CLUB}, {"4", SPADE},
        {"2", SPADE}, {"2", DIAMOND}, {"King", CLUB}, {"Queen", SPADE}, {"Queen", DIAMOND},
        {"7", CLUB}, {"7", HEART}, {"5", CLUB}, {"10", DIAMOND}, {"4", CLUB},
        {"King", HEART}, {"Ace", HEART}
    };
    deck_node_t *deck;

    deck = init_deck(cards);  /* Initialize the deck */
    print_deck(deck);          /* Print initial deck */
    printf("\n");

    sort_deck(&deck);          /* Sort the deck */
    printf("\n");

    print_deck(deck);          /* Print sorted deck */
    return (0);
}

/**
 * print_deck - Prints the deck of cards
 * @deck: Pointer to the head of the deck linked list
 */
void print_deck(const deck_node_t *deck)
{
    size_t i;
    char kinds[4] = {'S', 'H', 'C', 'D'};

    i = 0;
    while (deck)
    {
        if (i)
            printf(", ");
        printf("{%s, %c}", deck->card->value, kinds[deck->card->kind]);
        if (i == 12)
            printf("\n");
        i = (i + 1) % 13;
        deck = deck->next;
    }
}
