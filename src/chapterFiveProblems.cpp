/*
 * chapterFiveProblems.cpp
 *
 *  Created on: Oct 3, 2015
 *      Author: Mahmoud Mheisen
 */

/*
* File: chapterFiveProblems.cpp
* ------------------
* This file contain chapter five problems from
* Programming Abstractions in C++, Eric S. Roberts and Julie Zelenski
*/
#include "chapterFiveProblems.hpp"

int additiveSequence(int n, int t0, int t1) {
	if(n == 0) return t0;
	if(n == 1) return t1;
	return additiveSequence(n-1, t1, t0+t1);
}

int fib(int n) {
	if(n <= 1) return n;
	return fib(n-1) +  fib(n-2);
}

int fibonacciSequence(int n) {
	return additiveSequence(n, 0, 1);
}

/*
* Function: isPalindrome
* Usage: if (IsPalindrome(str)) . . .
* -----------------------------------
* This function returns true if and only if the string is a.
* palindrome. This implementation operates recursively by noting
* that all strings of length 0 or 1 are palindromes (the simple
* case) and that longer strings are palindromes only if their first
* and last characters match and the remaining substring is a
* palindrome.
*/
bool isPalindromeRecursive(std::string word) {
	int len = word.length();
	if(len <= 1) return true;
	return ((word[0] == word[len-1]) && isPalindromeRecursive(word.substr(1, len - 2)));
}

bool efficientIsPalindromeRecursive(std::string word) {
	return checkPalindrome(word, 0, word.length() - 1);
}

bool checkPalindrome(string word, int firstPos, int lastPos) {
	if(firstPos >= lastPos) return true;
	return ((word[firstPos] == word[lastPos]) && checkPalindrome(word, firstPos+1, lastPos-1));
}

int binarySearch(int key, int array[], int low, int high) {
	if(low > high) return -1;
	int mid = (low+high)/2;
	if(key == array[mid]) return mid;

	if(key < array[mid])
		return binarySearch(key, array, low, mid-1);
	else
		return binarySearch(key, array, mid+1, high);
}

int Power(int n, int k) {
	if(k==0) return 1;
	return n * Power(n, k-1);
}

int gcd(int x, int y) {
	if((x % y) == 0) return y;
	return gcd(y, x % y);
}

int digitSumRecursive(int number) {
	if(number < 10) return number;
	return number % 10 + digitSumRecursive(number/10);
}

int digitalRoot(int number) {
	if(number < 10) return number;
	return digitalRoot(digitSumRecursive(number));
}

int combinations(int n, int k) {
	if(k==0) return 1;
	if(k==n) return 1;
	return combinations(n-1, k-1) + combinations(n-1, k);
}

std::string reverse(std::string word) {
	return toReverse(word, 0, word.length()-1);
}

std::string toReverse(std::string word, int firstPos, int lastPos) {
	if(firstPos >= lastPos) return word;

	char temp = word[firstPos];
	word[firstPos] = word[lastPos];
	word[lastPos] = temp;

	return toReverse(word, ++firstPos, --lastPos);
}

// 1 2 3 4  5  6  7  8  9 10 level
// 1 2 2 3  3  3  4  4  4  4 number of ball in that level
// 1 3 5 8 11 14 18 22 26 30 total number of ball up to that level
int cannonBall(int level) {
	if(level == 1) return level;
}
















