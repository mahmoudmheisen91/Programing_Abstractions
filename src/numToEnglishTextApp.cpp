/*
 * numToEnglishTextApp.cpp
 *
 *  Created on: Sep 30, 2015
 *      Author: Mahmoud Mheisen
 */

/*
* File: numToEnglishTextApp.cpp
* ------------------
* This file solve the problem of transferring numbers to text from
* Programming Abstractions in C++, Eric S. Roberts and Julie Zelenski
*/
#include "numToEnglishTextApp.hpp"

/*
 * Main program
 * -------------
 *  This program prompt the user to enter a number and it will display the
 *  english text for it
 */
void numToEnglishTextApp(void) {
	long number = getInteger("Enter a number between 0 and 999999:");
	if(number < 0 || number > 999999)
		error("The number must be between 0 and 999999");

	std::string text = numToText(number);
	cout << "The number in english text is: " << text << endl;
}

/*
 * Function: basicNumberToString
 * Usage: std::string s = basicNumberToString(number);
 * ----------------------------------------------------
 * This function transfer the basic numbers from 0 to 9, to english text
 * string
 */
std::string basicNumberToString(int number) {
	switch (number) {
		case 0: return "zero";
		case 1: return "one";
		case 2: return "two";
		case 3: return "three";
		case 4: return "four";
		case 5: return "five";
		case 6: return "six";
		case 7: return "seven";
		case 8: return "eight";
		case 9: return "nine";
		default:
			error("Illegal call to basicNumberToString");
			return "";
	}
}

/*
 * Function: onesNumberToString
 * Usage: std::string s = onesNumberToString(number);
 * ----------------------------------------------------
 * This function transfer the ones numbers from 10 to 19, to english text
 * string
 */
std::string onesNumberToString(int number) {
	switch (number) {
		case 10: return "ten";
		case 11: return "eleven";
		case 12: return "twelve";
		case 13: return "thirteen";
		case 14: return "fourteen";
		case 15: return "fifteen";
		case 16: return "sixteen";
		case 17: return "seventeen";
		case 18: return "eighteen";
		case 19: return "nineteen";
		default:
			error("Illegal call to onesNumberToString");
			return "";
	}
}

/*
 * Function: tensNumberToString
 * Usage: std::string s = tensNumberToString(number);
 * ----------------------------------------------------
 * This function transfer the tens numbers 20, 30, ... , 90, to english
 * text string
 */
std::string tensNumberToString(int number) {
	switch (number) {
		case 20: return "twenty";
		case 30: return "thirty";
		case 40: return "forty";
		case 50: return "fifty";
		case 60: return "sixty";
		case 70: return "seventy";
		case 80: return "eighty";
		case 90: return "ninety";
		default:
			error("Illegal call to tensNumberToString");
			return "";
	}
}

/*
 * Function: numToText
 * Usage: std::string s = numToText(number);
 * -----------------------------------------
 * This function transfer number to english text
 */
std::string numToText(int number) {
	int firstDigit;
	std::string  text= "";

	if (number >= 100000 && number < 1000000) {
		firstDigit = number / 1000;
		threeNumbers(firstDigit, text);
		number %= 1000;

		if(number == 0)
			text += " thousands.";
		else
			text += " thousands and";
	}

	if (number >= 1000 && number < 100000) {
		firstDigit = number / 1000;
		twoNumbers(firstDigit, text);
		number %= 1000;

		if(number == 0)
			text += " thousands.";
		else
			text += " thousands and";
	}

	threeNumbers(number, text);
	return text;
}

/*
 * Function: threeNumbers
 * Usage: std::string s = threeNumbers(number);
 * --------------------------------------------
 * This function transfer three digits number to english text
 */
void threeNumbers(int number, std::string& text) {
	int firstDigit, secondDigit;

	if (number >= 100 && number < 1000) {
		firstDigit = number / 100;
		number %= 100;
		if(number == 0)
			text += " " + basicNumberToString(firstDigit) + " hundred";
		else
			text += " " + basicNumberToString(firstDigit) + " hundred and";
	}

	twoNumbers(number, text);
}

/*
 * Function: twoNumbers
 * Usage: std::string s = twoNumbers(number);
 * --------------------------------------------
 * This function transfer two digits number to english text
 */
void twoNumbers(int number, std::string& text) {
	int firstDigit, secondDigit;

	while(number != 0) {
		firstDigit = number % 10;
		number /= 10;
		secondDigit = number % 10;

		if(secondDigit == 0)
			text += " " + (basicNumberToString(firstDigit));

		else if(secondDigit == 1)
			text += " " + (onesNumberToString(firstDigit+10));

		else if(secondDigit > 1 && firstDigit == 0)
			text += " " + (tensNumberToString(secondDigit*10));

		else {
			text += " " + (tensNumberToString(secondDigit*10));
			text += " " + (basicNumberToString(firstDigit));
		}

		if (number < 10) break;
	}
}

















