/*
 * chapterFiveProblems.hpp
 *
 *  Created on: Oct 3, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_CHAPTERFIVEPROBLEMS_HPP_
#define SRC_CHAPTERFIVEPROBLEMS_HPP_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <cctype>

#include "StanfordCPPLib.hpp"
using namespace std;

/* functions prototypes */
int additiveSequence(int n, int t0, int t1);
int fib(int n);
int fibonacciSequence(int n);
bool isPalindromeRecursive(std::string word);
bool efficientIsPalindromeRecursive(std::string word);
bool checkPalindrome(std::string word, int firstPos, int lastPos);
int binarySearch(int key, int array[], int low, int high);
int Power(int n, int k);
int gcd(int x, int y);
int digitSumRecursive(int number);
int digitalRoot(int number);
int combinations(int n, int k);
std::string reverse(std::string word);
std::string toReverse(std::string word, int firstPos, int lastPos);
int cannonBall(int level);

#endif /* SRC_CHAPTERFIVEPROBLEMS_HPP_ */



















