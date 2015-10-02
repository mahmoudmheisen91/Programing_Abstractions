/*
 * Card.hpp
 *
 *  Created on: Oct 2, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_CARD_HPP_
#define SRC_CARD_HPP_

// Include libraries:
#include <iostream>
#include <string>

/*
 * Type: RankT
 * ------------
 * This type represent the rank of the card
 */
enum RankT {
	NONR, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
};

/*
 * Type: SuitT
 * -----------
 * This type represent the suit of the card
 */
enum SuitT {
	NONS, Clubs, Diamonds, Hearts, Spades
};

/*
 * Type: CardT
 * ------------
 * This type represent the card itself
 */
class CardT {
public:
	CardT();
	CardT(RankT rank, SuitT suit);

	RankT getRank();
	SuitT getSuit();

	void setRank(RankT rank);
	void setSuit(SuitT suit);

	std::string toString(void);

private:
	RankT rank;
	SuitT suit;
};

#endif /* SRC_CARD_HPP_ */


























