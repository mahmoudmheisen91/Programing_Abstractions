/*
 * chapterEightProblems.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: Mahmoud Mheisen
 */

/*
* File: chapterEightProblems.cpp
* ------------------
* This file contain chapter eight problems from
* Programming Abstractions in C++, Eric S. Roberts and Julie Zelenski
*/
#include "chapterEightProblems.hpp"
#include <algorithm>
#include </usr/include/i386-linux-gnu/sys/time.h>

void selecetionSort(Vector<int>& vec) {
	for(int i = 0; i < vec.size(); i++) {
		int min = i;
		for(int j = i+1; j < vec.size(); j++) {
			if(vec[j] < vec[min]) {
				min = j;
			}
		}
		int temp = vec[i];
		vec[i] = vec[min];
		vec[min] = temp;
	}
}

void mergeSort(Vector<int>& vec) {
	if(vec.size() <= 1) return;

	Vector<int> v1, v2;
	for(int i = 0; i < vec.size(); i++) {
		if(i < vec.size() / 2)
			v1.push_back(vec[i]);
		else
			v2.push_back(vec[i]);
	}
	mergeSort(v1);
	mergeSort(v2);
	vec.clear();
	merge(vec, v1, v2);
}

void merge(Vector<int>& vec, const Vector<int>& vec1, const Vector<int> vec2) {
	int p1, p2;
	p1 = p2 = 0;

	while(p1 < vec1.size() && p2 < vec2.size()) {
		if(vec1[p1] < vec2[p2])
			vec.push_back(vec1[p1++]);
		else
			vec.push_back(vec2[p2++]);
	}

	while (p1 < vec1.size()) vec.push_back(vec1[p1++]);
	while (p2 < vec2.size()) vec.push_back(vec2[p2++]);
}

/*
* Function: partition
* -------------------
* This function rearranges the elements of the vector so that the
* small elements are grouped at the left end of the vector and the
* large elements are grouped at the right end. The distinction
* between small and large is made by comparing each element to the
* pivot value, which is initially taken from vec[start]. When the
* partitioning is done, the function returns a boundary index such
* that vec[i] < pivot for all i < boundary, vec[i] == pivot
* for i == boundary, and vec[i] >= pivot for all i > boundary.
*/
int partition(Vector<int> & vec, int start, int finish) {
	int pivot = vec[start];
	int lh = start + 1;
	int rh = finish;

	while (true) {
		while (lh < rh && vec[rh] >= pivot)
			rh--;

		while (lh < rh && vec[lh] < pivot)
			lh++;

		if (lh == rh)
			break;

		int temp = vec[lh];
		vec[lh] = vec[rh];
		vec[rh] = temp;
	}

	if (vec[lh] >= pivot)
		return start;

	vec[start] = vec[lh];
	vec[lh] = pivot;

	return lh;
}

/*
* Function: doQuickSort
* -------------------
* Sorts the elements in the vector between index positions
* start and finish, inclusive. The Quicksort algorithm begins
* by "partitioning" the vector so that all elements smaller
* than a designated pivot element appear to the left of a
* boundary and all equal or larger values appear to the right.
* Sorting the subsidiary vectors to the left and right of the
* boundary ensures that the entire vector is sorted.
*/
void doQuickSort(Vector<int> & vec, int start, int finish) {
	if (start >= finish)
		return;

	int boundary = partition(vec, start, finish);

	doQuickSort(vec, start, boundary - 1);
	doQuickSort(vec, boundary + 1, finish);
}

/*
* Function: quickSort
* --------------
* This function sorts the elements of the vector into
* increasing numerical order using the Quicksort algorithm.
* In this implementation, Sort is a wrapper function that
* calls Quicksort to do all the work.
*/
void quickSort(Vector<int> & vec) {
	doQuickSort(vec, 0, vec.size() - 1);
}

double raiseToPowerLogN(double x, int n) {
	if(n == 0) return 1;
	if(n == 1) return x;
	return raiseToPowerLogN(x, n/2) * raiseToPowerLogN(x, (1+n)/2);
}

void insertionSort(Vector<int>& vec) {
	// first element is considered to be sorted:
	for(int i = 1; i < vec.size(); i++) {
		// every element before i is sorted:
		int key = vec[i];

		int j = i - 1;
		while(j >= 0 && vec[j] > key) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j+1] = key;
	}
}

void countSort(Vector<int>& vec) {
	int size = vec.size();

	// Find max:
	int max = *(std::max_element(vec.begin(), vec.end()));

	// Init count vector:
	Vector<int> countVec(max+1, 0);

	// Count:
	for(int i = 0; i < size; i++) countVec[vec[i]]++;

	// Sort by filling the vector with the number of times:
	vec.clear();
	for(int i = 0; i < max+1; i++) {
		for(int j = 0; j < countVec[i]; j++) {
			vec.push_back(i);
		}
	}
}

int fibonacciGold(int k) {
	double goldenRatio = (1 + sqrt(5))/2;
	return round(raiseToPowerLogN(goldenRatio, k) / sqrt(5));
}

double stopwatch(void)
{
	double diff = 0.0;

	struct timeval timenow;
	static struct timeval timeprev;	/* static to save prev. time */

	gettimeofday(&timenow, NULL);

	diff = ((double) timenow.tv_sec  + 1.0e-6 * (double) timenow.tv_usec) -
		   ((double) timeprev.tv_sec + 1.0e-6 * (double) timeprev.tv_usec);

	timeprev.tv_sec = timenow.tv_sec;
	timeprev.tv_usec = timenow.tv_usec;

	return diff;
}
















