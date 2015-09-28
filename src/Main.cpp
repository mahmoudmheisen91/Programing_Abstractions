/*
 * Main.cpp
 *
 *  Created on: Sep 28, 2015
 *      Author: Mahmoud Mheisen
 */

#include <iostream>
using namespace std;

#include "../StanfordCPPLib/vector.h"

int main(void) {

	Vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);

	cout << "vec = " << vec.toString() << endl;

	return 0;
}

