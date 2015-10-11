/*
 * StopWatch.hpp
 *
 *  Created on: Oct 7, 2015
 *      Author: Mahmoud Mheisen
 */

/*
 * StopWatch Class:
 * ----------------
 * An object oriented design of C-Style timer
 * Usage:
 * 		StopWatch timer1;
 * 		timer1.start();
 *
 * 		// .........
 * 		// code to measure
 * 		//..........
 *
 * 		timer1.stop();
 * 		cout << timer1.elapsed();
 */

#ifndef SRC_STOPWATCH_HPP_
#define SRC_STOPWATCH_HPP_

// Include libraries:
#include <iostream>
#include <string>
#include <sstream>
#include <sys/time.h>
#include </usr/include/i386-linux-gnu/sys/time.h>

// Display options:
enum Option {US, MS, S};

class StopWatch {
public:
	StopWatch(bool autoStart = false);
	StopWatch(Option option, bool autoStart = false);
	~StopWatch();
	void start(void);
	void stop(void);
	std::string elapsed(void);

private:
	double getCurrentTime(void);

private:
	double startTime;
	double stopTime;
	double elapsedTime;
	bool isStarted;
	Option option;
};

#endif /* SRC_STOPWATCH_HPP_ */











