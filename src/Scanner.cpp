/*
 * Scanner.cpp
 *
 *  Created on: Oct 11, 2015
 *      Author: Mahmoud Mheisen
 */

#include "Scanner.hpp"

Scanner::Scanner() {
	create("", 0, -1, false);
}

Scanner::Scanner(std::string line) {
	create(line, line.length(), 0, false);
}

Scanner::Scanner(const Scanner& other) {
	clone(other);
}

Scanner::~Scanner() {
	// Nothing
}

void Scanner::setInput(std::string line) {
	create(line, line.length(), 0, false);
}

std::string Scanner::nextToken(void) {
	if (index == -1)
		error("setInput has not been called");

	if (skipSpaceFlag) skipSpaces();

	int start = index;
	if (start >= length)
		return "";

	if (isalnum(buffer[index])) {
		int finish = scanToEndOfIdentifier();
		return buffer.substr(start, finish - start + 1);
	}

	index++;
	return buffer.substr(start, 1);
}

bool Scanner::hasMoreToken(void) {
	if (index == -1)
		error("setInput has not been called");

	if (skipSpaceFlag) skipSpaces();

	return (index < length);
}

void Scanner::ignoreSpaces(void) {
	this->skipSpaceFlag = true;
}

void Scanner::skipSpaces(void) {
	while (index < length && isspace(buffer[index]))
		index++;
}

int Scanner::scanToEndOfIdentifier(void) {
	while (index < length && isalnum(buffer[index]))
		index++;

	return index - 1;
}

void Scanner::create(std::string buffer, int length, int index, bool skipSpaceFlag) {
	this->buffer = buffer;
	this->length = length;
	this->index = index;
	this->skipSpaceFlag = skipSpaceFlag;
}

void Scanner::clone(const Scanner& other) {
	this->buffer = other.buffer;
	this->index = other.index;
	this->length = other.length;
	this->skipSpaceFlag = other.skipSpaceFlag;
}











