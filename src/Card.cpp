/*
 * Card.cpp
 *
 *  Created on: Oct 2, 2015
 *      Author: Mahmoud Mheisen
 */

/*
* File: Card.cpp
* ------------------
* This file implement the Card interface from
* Programming Abstractions in C++, Eric S. Roberts and Julie Zelenski
*/
#include "Card.hpp"

/*
 * private functions
 * ------------------
 * Will not be exported through the interface
 * */
std::string rankToString(RankT rank);
std::string suitToString(SuitT suit);

/*
 * Card API
 * -------------------------
 * Interface implementation
 */
CardT::CardT() {
	this->rank = NONR;
	this->suit = NONS;
}

CardT::CardT(RankT rank, SuitT suit) {
	this->rank = rank;
	this->suit = suit;
}

RankT CardT::getRank() {
	return this->rank;
}

SuitT CardT::getSuit() {
	return this->suit;
}

void CardT::setRank(RankT rank) {
	this->rank = rank;
}

void CardT::setSuit(SuitT suit) {
	this->suit = suit;
}

std::string CardT::toString(void) {
	return rankToString(this->rank) + suitToString(this->suit);
}

/*
 * Function: rankToString
 * Usage: string s = rankToString(rank);
 * --------------------------------------
 * This function will transfer the rank type to
 * string type
 */
std::string rankToString(RankT rank) {
	switch(rank) {
		case Ace: return "A";
		case Two: return "2";
		case Three: return "3";
		case Four: return "4";
		case Five: return "5";
		case Six: return "6";
		case Seven: return "7";
		case Eight: return "8";
		case Nine: return "9";
		case Ten: return "10";
		case Jack: return "J";
		case Queen: return "Q";
		case King: return "K";
		default: return "";
	}
}

/*
 * Function: suitToString
 * Usage: string s = suitToString(suit);
 * --------------------------------------
 * This function will transfer the suit type to
 * string type
 */
std::string suitToString(SuitT suit) {
	switch(suit) {
		case Clubs: return "C";
		case Diamonds: return "D";
		case Hearts: return "H";
		case Spades: return "S";
		default: return "";
	}
}
































