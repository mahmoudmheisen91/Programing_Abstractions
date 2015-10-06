/*
 * chapterSixProblems.hpp
 *
 *  Created on: Oct 4, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_CHAPTERSIXPROBLEMS_HPP_
#define SRC_CHAPTERSIXPROBLEMS_HPP_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <cctype>

#include "StanfordCPPLib.hpp"
using namespace std;

/* functions prototypes */
void moveSingleDisk(char start, char finish);
void moveTower(int n, char start, char finish, char temp);
void listPermutations(std::string word);
void generatePermutations(std::string prefix, std::string word);
void mondrianPaint(void);
void divide(GWindow& app, int x, int y, int width, int height);
void KochFractal(double size, int order);
void drawFractalLine(GWindow& app, double& x, double& y, double len, double theta, int order);
int numberOfHanoiMoves(int disks);
void countNumber(int disks, int& count);
void moveTower2(int n, char start, char finish, char temp);
void generateBinaryCode(int nbits);
void toBinary(std::string word, int nbits);
void generateGrayCode(int nbits);
void toGray(vector<std::string>& vec, int nbits);
int numberOfPartitions(int array[], int length, int target);
void countPartitions(int array[], int length, int target, int element, int& count);
void drawCoastline(double length, double theta, int order);
void drawFractalCoast(GWindow& app, double& x, double& y, double length, double theta, int order);
void drawTree(void);
void drawFractalTree(GWindow& app, double& x, double& y, double length, int length2, double theta);


#endif /* SRC_CHAPTERSIXPROBLEMS_HPP_ */















