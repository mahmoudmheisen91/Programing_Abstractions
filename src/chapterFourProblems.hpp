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

#include "StanfordCPPLib.hpp"
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
void countWordFrequency(void);
bool isPalindrome(std::string word);
void morseCode(void);
void constructSymbolTable(Map<std::string, std::string>& symbolTable);
void toMorse(std::string word, Map<std::string, std::string>& symbolTable);
void toAlpha(std::string word, Map<std::string, std::string>& symbolTable);

#endif /* SRC_CHAPTERFOURPROBLEMS_HPP_ */
















