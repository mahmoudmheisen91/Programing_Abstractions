/*
 * chapterFourProblems.hpp
 *
 *  Created on: Oct 2, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_CHAPTERFOURPROBLEMS_HPP_
#define SRC_CHAPTERFOURPROBLEMS_HPP_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <cctype>

#include "../StanfordCPPLib/simpio.h"
#include "../StanfordCPPLib/error.h"
#include "../StanfordCPPLib/random.h"
#include "../StanfordCPPLib/vector.h"
#include "../StanfordCPPLib/queue.h"
#include "../StanfordCPPLib/grid.h"
#include "../StanfordCPPLib/lexicon.h"
#include "../StanfordCPPLib/tokenscanner.h"
using namespace std;

/* functions prototypes */
void askUserForInputFile(std::string prompt, std::ifstream & infile);
bool checkForWin(Grid<char> & board, char mark);
bool checkLine(Grid<char> & board, char mark, int row, int col, int dRow, int dCol);
void runSimulation();
void reportResults(int nServed, long totalWait, long totalLength);
bool isAllAlpha(string & str);
void twoLetters(void);
void checkSpelling(void);

#endif /* SRC_CHAPTERFOURPROBLEMS_HPP_ */
















