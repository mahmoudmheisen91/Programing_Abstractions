/*
 * chapterOneProblems.cpp
 *
 *  Created on: Sep 30, 2015
 *      Author: Mahmoud Mheisen
 */

/*
* File: chapterOneProblems.cpp
* ------------------
* This file contain chapter one problems from
* Programming Abstractions in C++, Eric S. Roberts and Julie Zelenski
*/
#include "chapterOneProblems.hpp"

/*
* Constants
* ---------
* Low -- Lowest value for perfect numbers app
* HIGH -- Highest value for perfect numbers app
* NUMBER_OF_TURNS -- Number of round to calculate the pi value using Leibniz algorithm
*/
static const int LOW = 2;
static const int HIGH = 9999;
static const int NUMBER_OF_TURNS = 10000;

/*
 * Main program
 * -------------
 * This program prompt the user to enter a number and it
 * will display the reverse of that number
 */
void reverseNumberApp(void) {
	long int num = getReal("Enter a number:");

	if(num == 0) {
		cout << num;
		return;
	}

	while(num != 0) {
		cout << num % 10;
		num /= 10;
	}
}

/*
 * Function: isPerfect
 * Usage: bool b = isPerfect(number);
 * ----------------------------------
 * This function return true if the number is perfect number,
 * perfect number is a number that its divisor sum is equal to it.
 */
bool isPerfect(int num) {
	int to = int(sqrt(num)) + 1;

	int sum = 1;
	for(int i = 2; i <= to; i++) {
		if(num % i == 0 && num/i > i) {
			sum += i;
			sum += num / i;
		}
	}

	return sum == num;
}

/*
 * Main program
 * -------------
 * This program will display the perfect number from LOW
 * to HIGH
 */
void displayPerfectNumbersApp(void) {
	cout << "Perfect numbers between " << LOW << " and " << HIGH << " are:" << endl;
	for(int i = LOW; i <= HIGH; i++) {
		if(isPerfect(i))
			cout << i << endl;
	}
}

/*
 * Function: roundDouble
 * Usage: int a = roundDouble(number);
 * -----------------------------
 * This function will round the number to next integer
 */
int roundDouble(double num) {
	return (num > 0) ? num + 0.5 : num - 0.5;
}

/*
 * Function: piLeibniz
 * Usage: double pi = piLeibniz();
 * -------------------------------
 * This function will return the value of pi using Leibniz algorithm,
 * the accuracy of this algorithm is determined by NUMBER_OF_TURNS
 * constant
 */
double piLeibniz(void) {
	double pi = 0;
	double one = 1.0;
	for(int i = 1; i < NUMBER_OF_TURNS; i+=2) {
		pi += one/i;
		one = -one;
	}
	return pi * 4;
}

/*
 * Function: karlFriedrichSum
 * usage: int sum = karlFriedrichSum(to);
 * --------------------------------
 * This function sum the numbers from one up to number using Karl Friedrich
 * algorithm, the number must be multiple of 10
 */
int karlFriedrichSum(int number) {
	if ((number % 10)) error("Choose a number that is multiple of 10");
	return (1 + number) * (number / 2);
}



















