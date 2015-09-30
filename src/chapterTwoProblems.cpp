/*
 * chapterTwoProblems.cpp
 *
 *  Created on: Sep 30, 2015
 *      Author: Mahmoud Mheisen
 */

/*
* File: chapterOneProblems.cpp
* ------------------
* This file contain chapter two problems from
* Programming Abstractions in C++, Eric S. Roberts and Julie Zelenski
*/
#include "chapterTwoProblems.hpp"

/*
 * Function: arrayRanges
 * Usage: arrayRanges(array, size, min, max);
 * -------------------------------------------
 * This function will return the min and max in array with size equal to
 * size
 */
void arrayRanges(const int* array, const int& size, int& min, int& max) {
	min = 99999;
	max = -99999;

	for(int i = 0; i < size; i++) {
		if(array[i] < min)
			min = array[i];
		if(array[i] > max)
			max = array[i];
	}
}

/*
 * Function: sieveOfEratosthenesPrimes
 * Usage: sieveOfEratosthenesPrimes(number);
 * -----------------------------------
 * This function will print the prime numbers between 2 and number
 * using sieve of Eratosthenes algorithm
 */
void sieveOfEratosthenesPrimes(int number) {
	int size = number - 2;
	int *array = new int[size];
	for(int i = 0; i < size; i++)
		array[i] = i + 2;

	int next = 0;
	while(next < size) {
		for(int i = next+1; i < size; i++) {
			if(array[next] != 0 && array[i] % array[next] == 0)
				array[i] = 0;
		}
		//deleteZero(array, size);
		next++;
	}

	printArray(array, size);
}

// TODO: resize
/*
 * Function: deleteZero
 * Usage: deleteZero(array, size)
 * --------------------------------
 * This function delete the zeros from array
 */
void deleteZero(int* array, int size) {
	int* arrayCopy = new int[size];

	int j = 0;
	for(int i = 0; i < size; i++) {
		if(array[i] != 0) {
			arrayCopy[j] = array[i];
			j++;
		}
	}

	for(int i = 0; i < j; i++) {
		array[i] = arrayCopy[i];
	}
}

void printArray(int* array, int size) {
	for(int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}

	cout << endl;
}










