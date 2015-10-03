/*
 * chapterThreeProblems.cpp
 *
 *  Created on: Oct 2, 2015
 *      Author: Mahmoud Mheisen
 */

/*
* File: chapterThreeProblems.cpp
* ------------------
* This file contain chapter three problems from
* Programming Abstractions in C++, Eric S. Roberts and Julie Zelenski
*/
#include "chapterThreeProblems.hpp"


// TODO:
/*
 * Function: clearComments
 * Usage: clearComments(input, output);
 * -------------------------------------
 * This function copy the input file and remove the comments from it
 * and put it in the output file
 */
void clearComments(std::ifstream& input, std::ofstream& output) {
	char first, second;
	bool commentFlag = false;

	while ((first = input.get()) != EOF) {
		if (commentFlag) {
			if (first == '*') {
				second = input.get();
				if (second == '/')
					commentFlag = false;
				else
					input.unget();
			}
		}
		else {
			if (first == '/') {
				second = input.get();
				if (second == '*')
					commentFlag = true;
				else
					input.unget();
			}
			if (!commentFlag)
				output.put(first);
		}
	}
}

/*
 * Main program
 * ------------
 * This program will init a deck of cards, shuffle and
 * display them
 */
void cardApp(void) {
	CardT deck[52];

	// init:
	int j = 0;
	for(int rank = 1; rank <= 13; rank++) {
		for(int suit = 1; suit <= 4; suit++) {
			deck[j++] = CardT(RankT(rank), SuitT(suit));
		}
	}

	// shuffle:
	for(int i = 0; i < 52; i++) {
		int newPos = randomInteger(i, 51);
		CardT temp = deck[i];
		deck[i] = deck[newPos];
		deck[newPos] = temp;
	}

	// display:
	for(int i = 0; i < 52; i++) {
		cout << setw(4) << deck[i].toString();
		if((i+1) % 13 == 0) cout << endl;
	}
}




















