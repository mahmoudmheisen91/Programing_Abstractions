/*
 * chapterEightProblems.hpp
 *
 *  Created on: Oct 5, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_CHAPTEREIGHTPROBLEMS_HPP_
#define SRC_CHAPTEREIGHTPROBLEMS_HPP_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <cctype>

#include "StanfordCPPLib.hpp"
using namespace std;

/* functions prototypes */
void selecetionSort(Vector<int>& vec);
void mergeSort(Vector<int>& vec);
void merge(Vector<int>& vec, const Vector<int>& vec1, const Vector<int> vec2);
int partition(Vector<int> & vec, int start, int finish);
void doQuickSort(Vector<int> & vec, int start, int finish);
void quickSort(Vector<int> & vec);
double raiseToPowerLogN(double x, int n);
void insertionSort(Vector<int>& vec);
void countSort(Vector<int>& vec);
int fibonacciGold(int k);
double stopwatch(void);

#endif /* SRC_CHAPTEREIGHTPROBLEMS_HPP_ */
