/*
 * chapterSixProblems.cpp
 *
 *  Created on: Oct 4, 2015
 *      Author: Mahmoud Mheisen
 */

/*
* File: chapterSixProblems.cpp
* ------------------
* This file contain chapter six problems from
* Programming Abstractions in C++, Eric S. Roberts and Julie Zelenski
*/
#include "chapterSixProblems.hpp"

/* Constants */
const double MIN_AREA = 2500;
const double MIN_EDGE = 0.15;

void moveSingleDisk(char start, char finish) {
	cout << start << " -> " << finish << endl;
}

void moveTower(int n, char start, char finish, char temp) {
	if(n==1)
		moveSingleDisk(start, finish);
	else {
		moveTower(n-1, start, temp, finish);
		moveSingleDisk(start, finish);
		moveTower(n-1, temp, finish, start);
	}
}

void listPermutations(std::string word) {
	generatePermutations("", word);
}

// TODO: hard:
void generatePermutations(std::string prefix, std::string word) {
	if(word == "")
		cout << prefix << endl;
	else {
		for(unsigned int i = 0; i < word.length(); i++) {
			std::string newPrefix = prefix + word[i];
			std::string newWord = word.substr(0, i) + word.substr(i+1);
			generatePermutations(newPrefix, newWord);
		}
	}
}

void mondrianPaint(void) {
	GWindow app(600, 400);
	app.center();
	divide(app, 0, 0, app.getWidth(), app.getHeight());
}

void divide(GWindow& app, int x, int y, int width, int height) {
	if (width * height >= MIN_AREA) {
		if (width > height) {
			// Draw vertical line:
			double mid = width * randomReal(MIN_EDGE, 1 - MIN_EDGE);
			GLine line(x + mid, y, x + mid, y+height);
			line.setColor("blue");
			line.setLineWidth(2);
			app.draw(line);
			divide(app, x, y, mid, height);
			divide(app, x + mid, y, width - mid, height);
		} else {
			// Draw horizontal line:
			double mid = height * randomReal(MIN_EDGE, 1 - MIN_EDGE);
			GLine line(x, y + mid, x+width, y + mid);
			line.setColor("red");
			line.setLineWidth(2);
			app.draw(line);
			divide(app, x, y, width, mid);
			divide(app, x, y + mid, width, height - mid);
		}
	}
}

void KochFractal(double size, int order) {
	GWindow app(400, 400);
	app.center();
	double x = app.getWidth() / 2 - size / 2;
	double y = app.getHeight() / 2 - sqrt(3) * size / 6;
	drawFractalLine(app, x, y, size, 0, order);
	drawFractalLine(app, x, y, size, -120, order);
	drawFractalLine(app, x, y, size, -240, order);
}

void drawFractalLine(GWindow& app, double& x, double& y, double len, double theta, int order) {
	if (order == 0) {
		GPoint p = app.drawPolarLine(x, y, len, theta);
		x = p.getX();
		y = p.getY();
	} else {
		drawFractalLine(app, x, y, len/3, theta, order - 1);
		drawFractalLine(app, x, y, len/3, theta + 60, order - 1);
		drawFractalLine(app, x, y, len/3, theta - 60, order - 1);
		drawFractalLine(app, x, y, len/3, theta, order - 1);
	}
}

int numberOfHanoiMoves(int disks) {
	int count = 0;
	countNumber(disks, count);
	return count;
}

void countNumber(int disks, int& count) {
	if(disks == 1)
		count++;
	else {
		countNumber(disks-1, count);
		count++;
		countNumber(disks-1, count);
	}
}

void moveTower2(int n, char start, char finish, char temp) {
	if(n == 0);// {}
		//return;
	else {
		moveTower(n-1, start, temp, finish);
		moveSingleDisk(start, finish);
		moveTower(n-1, temp, finish, start);
	}
}

void generateBinaryCode(int nbits) {
	toBinary("", nbits);
}

void toBinary(std::string word, int nbits) {
	if(nbits == 0)
		cout << word << endl;
	else {
		toBinary(word + "0", nbits-1);
		toBinary(word + "1", nbits-1);
	}
}

void generateGrayCode(int nbits) {
	toGray("", nbits);
}

void toGray(std::string word, int nbits) {
	if(nbits == 0)
		cout << word << endl;
	else {
		toGray(word + "0", nbits-1);
		toGray(word + "1", nbits-1);
	}
}

int numberOfPartitions(int array[], int length, int target) {
	int count = 0;
	countPartitions(array, length, target, 0, count);
	return count;
}

void countPartitions(int array[], int length, int target, int element, int& count) {
	if(element == length)
		return;
	else {
		int sum = 0;
		for(int i = element; i < length; i++) {
			sum += array[i];
			if(sum == target) count++;
		}
		countPartitions(array, length, target, element+1, count);
	}
}

/*
* Function: drawCoastline
* Usage: drawCoastline(length, theta, order);
* -------------------------------------------
* The DrawCoastline function starts at the current (x, y)
* position and draws a fractal coastline of the specified
* length moving in the direction given by the angle theta
* (as defined in the definition of DrawPolarLine in the
* preceding problem); order gives the number of recursive
* subdivisions into which each segment will be divided.
*/
void drawCoastline(double length, double theta, int order) {
	GWindow app(600, 400);
	app.center();
	app.setColor("gray");
	double x = app.getWidth() / 2 - length / 2;
	double y = app.getHeight() / 2 - .5 * length / 6;
	drawFractalCoast(app, x, y, length, theta, order);
}

void drawFractalCoast(GWindow& app, double& x, double& y, double length, double theta, int order) {
	if(order == 0) {
		GPoint end = app.drawPolarLine(x, y, length, theta);
		x = end.getX();
		y = end.getY();
	} else {
		drawFractalCoast(app, x, y, length/3, theta, order-1);
		if(randomBool()) {
			drawFractalCoast(app, x, y, length/3, theta + 60, order-1);
			drawFractalCoast(app, x, y, length/3, theta - 60, order-1);
		} else {
			drawFractalCoast(app, x, y, length/3, theta - 60, order-1);
			drawFractalCoast(app, x, y, length/3, theta + 60, order-1);
		}
		drawFractalCoast(app, x, y, length/3, theta, order-1);
	}
}

void drawTree(void) {
	GWindow app(600, 600);
	app.center();

	double length = 80;
	double x = app.getWidth() / 2;
	double y = app.getHeight() - 50;

	GPoint end = app.drawPolarLine(x, y, length, 90);
	x = end.getX();
	y = end.getY();

	drawFractalTree(app, x, y, length, 7, 60);
}

void drawFractalTree(GWindow& app, double& x, double& y, double length, int length2, double theta) {
	double tx = x;
	double ty = y;
	length = length * .85;
	if(length2 > 0) {
		//if(randomChance(length/81)) {
			GPoint end = app.drawPolarLine(x, y, length, theta);
			x = end.getX();
			y = end.getY();
			drawFractalTree(app, x, y, length, length2-1, theta-30);
			x=tx;
			y=ty;
		//}
		//if(randomChance(length/81)) {
			end = app.drawPolarLine(x, y, length, theta+60);
			x = end.getX();
			y = end.getY();
			drawFractalTree(app, x, y, length, length2-1, theta+30);
		//}
	}
}

















































