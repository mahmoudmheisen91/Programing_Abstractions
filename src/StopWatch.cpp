/*
 * StopWatch.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: Mahmoud Mheisen
 */

#include "StopWatch.hpp"

StopWatch::StopWatch(bool autoStart) {
	this->isStarted = false;
	this->elapsedTime = 0.0;
	this->startTime = 0.0;
	this->stopTime = 0.0;
	this->option = S;

	if(autoStart) start();
}

StopWatch::StopWatch(Option option, bool autoStart) {
	this->isStarted = false;
	this->elapsedTime = 0.0;
	this->startTime = 0.0;
	this->stopTime = 0.0;
	this->option = option;
	if(autoStart) start();
}

StopWatch::~StopWatch() {
	// nothing to do
}

void StopWatch::start(void) {
	this->startTime = getCurrentTime();
	this->isStarted = true;
}

void StopWatch::stop(void) {
	this->stopTime = getCurrentTime();
	if(!isStarted) this->startTime = this->stopTime;
	this->isStarted = false;
}

std::string StopWatch::elapsed(void) {
	std::ostringstream oss;
	oss << "Elapsed Time: " << (this->stopTime - this->startTime) << " ";

	switch(this->option) {
		case S:
			oss << "seconds";
			break;
		case MS:
			oss << "ms";
			break;
		case US:
			oss << "us";
			break;
	}

	return oss.str();
}

double StopWatch::getCurrentTime(void) {
	timeval timeNow;
	gettimeofday(&timeNow, NULL);
	double current = ((double) timeNow.tv_sec  + 1.0e-6 * (double) timeNow.tv_usec);

	switch(this->option) {
		case S:
			return current;
		case MS:
			return current * 1000;
		case US:
			return current * 1000000;
		default:
			return current;
	}
}












