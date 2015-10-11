/*
 * Scanner.hpp
 *
 *  Created on: Oct 11, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_SCANNER_HPP_
#define SRC_SCANNER_HPP_

// Include C++ libraries:
#include <iostream>
#include <string>
#include "../StanfordCPPLib/error.h"
#include <cctype>

class Scanner {
public:
	Scanner();
	Scanner(std::string line);
	Scanner(const Scanner& other);
	virtual ~Scanner();

	void setInput(std::string line);
	std::string nextToken(void);
	bool hasMoreToken(void);
	void ignoreSpaces(void);

private:
	void skipSpaces(void);
	void create(std::string buffer, int length, int index, bool skipSpaceFlag);
	void clone(const Scanner& other);
	int scanToEndOfIdentifier(void);

private:
	std::string buffer;
	int length;
	int index;
	bool skipSpaceFlag;
};

#endif /* SRC_SCANNER_HPP_ */













