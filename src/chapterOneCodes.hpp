/*
 * powerTab.hpp
 *
 *  Created on: Sep 29, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_CHAPTERONECODES_HPP_
#define SRC_CHAPTERONECODES_HPP_

/* Libraries inclusions */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#include "../StanfordCPPLib/simpio.h"
#include "../StanfordCPPLib/error.h"
using namespace std;

/* private functions */
void powerTabApp(void);
int intToPower(int base, int to);
void averageThreeApp(void);
bool isLeapYear(int year);
bool isVowel(char character);
int digitSum(int number);
void addListOfIntegerApp(void);
void leapYearsApp(void);
void quadraticEquationSolverApp(void);
void getCoefficients(double& a, double& b, double& c);
void solveRoots(double& a, double& b, double& c, double& x1, double& x2);
void displayRoots(double& x1, double&x2);


#endif /* SRC_CHAPTERONECODES_HPP_ */










