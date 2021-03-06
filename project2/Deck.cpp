#include "Deck.h"

/*
 * We will create a deck of cards in the order
 * 2D 3D 4D ... KD AD
 * 2C 3C 4C ... KC AC
 * 2H 3H 4H ... KH AH
 * 2S 3S 4S ... KS AS
 */
Deck::Deck()
{
	deck = new Queue<Card*>();

	for (int suit = 1; suit < 5; suit++) // Diamond -> Space
		for (int value = 2; value < 15; value++) // 2 -> Ace
			deck->enqueue(new Card(suit, value));
}

Deck::~Deck()
{
	while (! deck->empty() )
		delete deck->dequeue();

	delete deck;
}

Card Deck::draw()
{
	Card *dequeue = deck->dequeue();
	Card tmp(*dequeue);

	delete dequeue;
	return tmp;
}

bool Deck::empty()
{
	return deck->empty();
}

void Deck::swap(Card &c1, Card &c2)
{
	Card tmp = c1;
	c1 = c2;
	c2 = tmp;
}

void Deck::randomize(Card* arr[], int n)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = n-1; j > 0; j--)
		{
			int k = rand() % (j+1);
			swap(*arr[j], *arr[k]);
		}
	}
}

void Deck::shuffle()
{
	int size = deck->size();
	Queue<Card*> *tmp_deck = new Queue<Card*>();
	Card *tmp[size];

	for (int i = 0; i < size; i++)
		tmp[i] = deck->dequeue();

	randomize(tmp, size);

	for (int i = 0; i < size; i++)
		tmp_deck->enqueue(tmp[i]);

	delete deck;
	deck = tmp_deck;
}
