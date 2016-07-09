/*
 * Main.cpp
 *
 *  Created on: Sep 28, 2015
 *      Author: Mahmoud Mheisen
 */

#include "chapterOneCodes.hpp"
#include "numToEnglishTextApp.hpp"
#include "chapterOneProblems.hpp"
#include "chapterTwoProblems.hpp"
#include "chapterThreeProblems.hpp"
#include "chapterFourProblems.hpp"
#include "chapterFiveProblems.hpp"
#include "chapterSixProblems.hpp"
#include "chapterEightProblems.hpp"
#include "StopWatch.hpp"
#include "Scanner.hpp"

/* main for all code */
int main(void) {

	//runSimulation();
	//checkSpelling();
	//countWordFrequency();
	//interpreter();
	//moveTower(3, 'A', 'B', 'C');
	//listPermutations("ABC");

	//mondrianPaint();
	//KochFractal(250, 9);
	//drawCoastline(650, -10, 9);
	//generateGrayCode(3);
	//drawTree();

	Vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);

	Scanner scanner("this is a , f45 2 3 3; test:");
	//scanner.ignoreSpaces();

	while(scanner.hasMoreToken()) {
		std::string token = scanner.nextToken();
		cout << token << endl;
	}
	return 0;
}






















