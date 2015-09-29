/*
 * powerTab.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: Mahmoud Mheisen
 */

/*
* File: chapterOneCodes.cpp
* ------------------
* This program contain chapter one code from
* Programming Abstractions in C++, Eric S. Roberts and Julie Zelenski
*/

#include "chapterOneCodes.hpp"

/*
* Constants
* ---------
* LOWER -- Starting value for the table
* UPPER -- Final value for the table
* SENTINEL -- Value of enter it entered it will cause the program to close
* BEGIN_YEAR -- Starting value for the leap year table
* END_YEAR -- Final value for the leap year table
*/
static const int LOWER = 0;
static const int UPPER = 20;
static const int SENTINEL = -1;
static const int BEGIN_YEAR = 1992;
static const int END_YEAR = 2060;

/*
 * Main program
 * -------------
 * This program generates a table comparing values
 * of the functions n^2 and 2^n.
 */
void powerTabApp(void) {
	cout << "  N |  N2 |     2N" << endl;
	cout << "----+-----+---------" << endl;
	for(int i = LOWER; i <= UPPER; ++i) {
		cout << setw(3) << right << i << " |" ;
		cout << setw(4) << right << intToPower(i, 2) << " |" ;
		cout << setw(7) << left << intToPower(2, i) << endl;
	}
}

/*
* Function: intToPower
* Usage: int result = intToPower(n, k);
* ---------------------------------
* This function returns n to the kth power.
*/
int intToPower(int base, int to) {
	int result = 1;
	for(int i = 0; i < to; i++) {
		result *= base;
	}
	return result;
}

/*
 * Main program
 * ------------
 * This program request the user to enter three numbers
 * and will output the average of them
 */
void averageThreeApp(void) {
	double num1, num2, num3, result;

	num1 = getReal("Enter first number: ");
	num2 = getReal("Enter second number: ");
	num3 = getReal("Enter third number: ");

	result = (num1 + num2 + num3) / 3;

	cout << "Result is: " << result << endl;
}

/*
 * Function: isVowel
 * Usage: bool b = isVowel(character);
 * -------------------------------
 * This function return true if character is vowel (A, E, I, O, U)
 */
bool isVowel(char character) {
	switch(character) {
		case 'A': case 'E': case 'I': case 'O': case 'U':
		case 'a': case 'e': case 'i': case 'o': case 'u':
			return true;
		default:
			return false;
	}
}

/*
 * Function: digitSum
 * Usage: int result = digitSum(number);
 * ----------------------------------
 * This function return the sum of number's digits
 */
int digitSum(int number) {
	int sum = 0;
	while(number != 0) {
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

/*
 * Main program
 * ------------
 * This program will request the user to enter a list of
 * numbers until he enter the SENTINEL and it will return
 * the sum of them.
 */
void addListOfIntegerApp(void) {
	double number, result = 0.0;

	cout << "Use " << SENTINEL << " to signal the end:" << endl;

	number = getReal("Enter a number:");
	while(number != SENTINEL) {
		result += number;
		number = getReal("Enter a number:");
	}

	cout << "The result is: " << result << endl;
}

/*
 * Function: isLeapYear
 * Usage: bool b = isLeapYear(year);
 * ------------------------------
 * This function return true if year is a leap year
 * else it will print false.
 */
bool isLeapYear(int year) {
	return ( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) );
}

/*
 * Main program
 * -------------
 * This program will print all leap years from BEGIN_YEAR
 * to END_YEAR
 */
void leapYearsApp(void) {
	std::cout << setw(6) << left << "Year" << "|";
	std::cout << setw(20) << right << "isLeapYear?" << std::endl;
	for(int year = BEGIN_YEAR; year <= END_YEAR; year++) {
		std::cout << setw(6) << left << year << "|";
		std::cout << setw(20) << right << (isLeapYear(year)? "Is Leap Year": "Is Not Leap Year");
		std::cout << std::endl;
	}
}

/*
 * Function: getCoefficients
 * Usage: getCoefficients(a, b, c);
 * ---------------------------------
 * This function prompt the user to enter three values for
 * quadratic equation coefficients
 */
void getCoefficients(double& a, double& b, double& c) {
	a = getReal("Enter first coefficient:");
	if(a == 0) error("first coefficients must not be zero");

	b = getReal("Enter second coefficient:");
	c = getReal("Enter third coefficient:");
}

/*
 * Function: solveRoots
 * Usage: solveRoots(a, b, c, x1, x2);
 * -----------------------------------
 * This function will solve the roots for the quadratic
 * equation and put the result in x1 and x2
 */
void solveRoots(double& a, double& b, double& c, double& x1, double& x2) {
	double upper = b * b - 4 * a * c;
	if(upper < 0) error("The solution is complex");

	upper = sqrt(upper);
	x1 = (-b + upper) / (2*a);
	x2 = (-b - upper) / (2*a);
}

/*
 * Function: displayRoots
 * Usage: displayRoots(x1, x2);
 * -----------------------------
 * This function will display the roots of the equation
 */
void displayRoots(double& x1, double&x2) {
	if (x1 == x2)
		std::cout << "There is a double root at " << x1 << std::endl;
	else
		std::cout << "The roots are " << x1 << " and " << x2 << std::endl;
}

/*
 * Main program
 * -------------
 * This program will prompt the user to enter three coefficients and
 * will solve the quadratic equation that is constructed from those values
 */
void quadraticEquationSolverApp(void) {
	double a, b, c, x1, x2;

	getCoefficients(a, b, c);
	solveRoots(a, b, c, x1, x2);
	displayRoots(x1, x2);
}



















