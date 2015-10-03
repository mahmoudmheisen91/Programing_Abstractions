/*
 * chapterFourProblems.cpp
 *
 *  Created on: Oct 2, 2015
 *      Author: Mahmoud Mheisen
 */

/*
* File: chapterFourProblems.cpp
* ------------------
* This file contain chapter four problems from
* Programming Abstractions in C++, Eric S. Roberts and Julie Zelenski
*/
#include "chapterFourProblems.hpp"

/*
* Opens a text file whose name is entered by the user. If the file
* does not exist, the user is given additional chances to enter a
* valid file. The prompt string is used to tell the user what kind
* of file is required.
*/
void askUserForInputFile(std::string prompt, std::ifstream & infile) {
	while (true) {
		cout << prompt;
		string filename = getLine();
		infile.open(filename.c_str());
		if (!infile.fail()) break;
		cout << "Unable to open " << filename << endl;
		infile.clear();
	}
}

/*
* Checks to see whether the specified player identified by mark
* ('X' or 'O') has won the game. To reduce the number of special
* cases, this implementation uses the helper function CheckLine.
*/
bool checkForWin(Grid<char> & board, char mark) {
	for (int i = 0; i < 3; i++) {
		if (checkLine(board, mark, i, 0, 0, 1)) return true;
		if (checkLine(board, mark, 0, i, 1, 0)) return true;
	}
	if (checkLine(board, mark, 0, 0, 1, 1)) return true;
	return checkLine(board, mark, 2, 0, -1, 1);
}

/*
* Checks a line extending across the board in some direction. The
* starting coordinates are given by the row and col parameters.
* The direction of motion is specified by dRow and dCol, which
* show how to adjust the row and col values on each cycle. For
* rows, dRow is always 0; for columns, dCol is 0. For diagonals,
* these values will be +1 or -1 depending on the direction.
*/
bool checkLine(Grid<char> & board, char mark, int row, int col, int dRow, int dCol) {
	for (int i = 0; i < 3; i++) {
		if (board[row][col] != mark)
			return false;
		row += dRow;
		col += dCol;
	}
	return true;
}

/*
* File: checkout.cpp
* ------------------
* This program simulates a checkout line, such as one you
* might encounter in a grocery store. Customers arrive at
* the checkout stand and get in line. Those customers wait
* in the line until the cashier is free, at which point
* they are served and occupy the cashier for a randomly
* chosed period of time. After the service time is complete,
* the cashier is free to serve the next customer in the line.
*
* The waiting line is represented by a Queue<int> in which the
* integer value stored in the queue is the time unit in which
* that customer arrived. Storing this time makes it possible
* to determine the average waiting time for each customer.
*
* In each unit of time, up to the parameter SIMULATION_TIME,
* the following operations are performed:
*
* 1. Determine whether a new customer has arrived.
*
 New customers arrive randomly, with a probability
*
 determined by the parameter ARRIVAL_PROBABILITY.
*
* 2. If the cashier is busy, note that the cashier has
*
 spent another minute with that customer. Eventually,
*
 the customer's time request is satisfied, which frees
*
 the cashier.
*
* 3. If the cashier is free, serve the next customer in line.
*
 The service time is taken to be a random period between
*
 MIN_SERVICE_TIME and MAX_SERVICE_TIME.
*
* At the end of the simulation, the program displays the
* parameters and the following computed results:
*
* o The number of customers served
* o The average time spent in line
* o The average number of customers in the line
*/

/* Simulation parameters */
const int SIMULATION_TIME = 2000;
const double ARRIVAL_PROBABILITY = 0.05;
const int MIN_SERVICE_TIME = 5;
const int MAX_SERVICE_TIME = 15;

/*
* Function: RunSimulation
* Usage: RunSimulation();
* -----------------------
* This function runs the actual simulation. In each time unit,
* the program first checks to see whether a new customer arrives.
* Then, if the cashier is busy (indicated by a nonzero value for
* serviceTimeRemaining), the program decrements that variable to
* indicate that one more time unit has passed. Finally, if the
* cashier is free, the simulation serves another customer from
* the queue after recording the waiting time for that customer.
*/
void runSimulation() {
	Queue<int> queue;
	int serviceTimeRemaining = 0;
	int nServed = 0;
	long totalWait = 0;
	long totalLength = 0;
	for (int t = 0; t < SIMULATION_TIME; t++) {
		if (randomChance(ARRIVAL_PROBABILITY)) {
			queue.enqueue(t);
		}

		if (serviceTimeRemaining > 0) {
			serviceTimeRemaining--;
			if (serviceTimeRemaining == 0) nServed++;
		} else if (!queue.isEmpty()) {
			totalWait += t - queue.dequeue();
			serviceTimeRemaining = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
		}

		totalLength += queue.size();
	}
	reportResults(nServed, totalWait, totalLength);
}

/*
* Function: ReportResults
* Usage: ReportResults(nServed, totalWait, totalLength);
* ------------------------------------------------------
* This function reports the results of the simulation.
*/
void reportResults(int nServed, long totalWait, long totalLength) {
	cout << "Simulation results given the following parameters:" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << fixed << setprecision(2);

	cout << "  SIMULATION_TIME:" << setw(4) << SIMULATION_TIME << endl;
	cout << "  ARRIVAL_PROBABILITY: " << setw(7) << ARRIVAL_PROBABILITY << endl;
	cout << "  MIN_SERVICE_TIME:" << setw(4) << MIN_SERVICE_TIME << endl;
	cout << "  MAX_SERVICE_TIME:" << setw(4) << MAX_SERVICE_TIME << endl;
	cout << endl;

	cout << "  Customers served:" << setw(4) << nServed << endl;
	cout << "  Average waiting time: " << setw(7) << double(totalWait) / nServed << endl;
	cout << "  Average queue length: " << setw(7) << double(totalLength) / SIMULATION_TIME << endl;
}

/* Returns true if a string contains only alphabetic characters. */
bool isAllAlpha(string & str) {
	for (unsigned int i = 0; i < str.length(); i++) {
		if (!isalpha(str[i])) return false;
	}
	return true;
}

void twoLetters(void) {
	std::string word = "  ";
	Lexicon dictionary("Resources/dictionary2.txt");
	for(char i = 'a'; i < 'z'; i++) {
		word[0] = i;
		for(char j = 'a'; j < 'z'; j++) {
			word[1] = j;
			if(!dictionary.contains(word)) {
				cout << word << " is not a two letter word" << endl;
			}
		}
	}

}

/*
* Function: checkSpelling
* --------------------
* This program checks the spelling of words in an input file.
*/
void checkSpelling(void) {
	std::ifstream infile;
	askUserForInputFile("Enter file name: ", infile);

	Lexicon dictionary("Resources/dictionary2.txt");
	TokenScanner scanner(infile);

	while(scanner.hasMoreTokens()) {
		std::string word = scanner.nextToken();
		if (isAllAlpha(word) && !dictionary.contains(word)) {
			cout << word << ": is not in the dictionary" << endl;
		}
	}

	infile.close();
}

void countWordFrequency(void) {
	std::ifstream infile;
	askUserForInputFile("Enter file name: ", infile);

	Map<std::string, int> wordCounts;
	TokenScanner scanner(infile);

	while(scanner.hasMoreTokens()) {
		std::string word = toLowerCase(scanner.nextToken());
		if(isAllAlpha(word)) {
			if(wordCounts.containsKey(word))
				wordCounts[word]++;
			else
				wordCounts[word] = 1;
		}
	}

	for(std::string word : wordCounts) {
		cout << setw(10) << left << word << setw(3) << wordCounts[word] << endl;
	}
}

bool isPalindrome(std::string word) {
	if(word.length() < 1)
		error("The word length is zero");
	if(!isAllAlpha(word))
		error("The word is not valid");

	if(word.length() == 1)
		return true;

	int last = word.length() - 1;

	for(unsigned int i = 0; i < word.length(); i++) {
		if(!(word[i] == word[last]))
			return false;
		last--;
	}
	return true;
}

void morseCode(void) {
	std::string line = getLine("Enter a message: ");

	Map<std::string, std::string> symbolTable;
	constructSymbolTable(symbolTable);

	if(isalpha(line[0]))
		toMorse(line, symbolTable);
	else
		toAlpha(line, symbolTable);
}

void constructSymbolTable(Map<std::string, std::string>& symbolTable) {
	std::ifstream morseFile;

	morseFile.open("Resources/morse.txt");
	if(morseFile.fail())
		error("Unable to open file");

	std::string line;
	while(true) {
		getline(morseFile, line);
		if(morseFile.fail()) break;
		symbolTable.add(line.substr(0, 1), line.substr(1));
		symbolTable.add(line.substr(1), line.substr(0, 1));
	}

	morseFile.close();
}

void toMorse(std::string word, Map<std::string, std::string>& symbolTable) {
	for(unsigned int i = 0; i < word.length(); i++) {
		std::string letter = toUpperCase(charToString(word[i]));

		if(symbolTable.containsKey(letter))
			cout << symbolTable.get(letter) << " / ";
		else
			cout << "N";
	}
	cout << endl;
}

void toAlpha(std::string word, Map<std::string, std::string>& symbolTable) {
	TokenScanner scanner;
	scanner.ignoreWhitespace();

	for(char i = 'A'; i < 'Z'; i++)
		scanner.addWordCharacters(symbolTable.get(charToString(i)));

	scanner.setInput(word);

	while(scanner.hasMoreTokens()) {
		std::string symbol = scanner.nextToken();
		cout << symbolTable.get(symbol);
	}
	cout << endl;
}












































