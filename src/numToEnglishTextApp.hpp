/*
 * numToEnglishTextApp.hpp
 *
 *  Created on: Sep 30, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_NUMTOENGLISHTEXTAPP_HPP_
#define SRC_NUMTOENGLISHTEXTAPP_HPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#include "../StanfordCPPLib/simpio.h"
#include "../StanfordCPPLib/error.h"
#include "../StanfordCPPLib/stack.h"
using namespace std;

// TODO: as class parser

/* private functions */
void numToEnglishTextApp(void);
std::string basicNumberToString(int number);
std::string tensNumberToString(int number);
std::string onesNumberToString(int number);
std::string numToText(int number);
void twoNumbers(int number, std::string& text);
void threeNumbers(int number, std::string& text);

#endif /* SRC_NUMTOENGLISHTEXTAPP_HPP_ */
