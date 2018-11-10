/*
 * jumble.h
 *
 *  Created on: Nov 3, 2018
 *      Author: chrismaltais
 */

// Include Guards
#pragma once

// Dependencies
#include <vector>
#include <string>
#include <exception>
using namespace std;
typedef char* charArrayPtr;

class JumblePuzzle {
    private:
        // Grid Vars
        int puzzleSize;
        string difficulty;
        string hiddenWord;
        // Location Vars
        char directionArr[4] = {'n', 'e', 's', 'w'};
        char direction;
        int rowPos;
        int colPos;
        charArrayPtr* puzzle = nullptr;

        charArrayPtr* initializeRandomPuzzle(const int& size);
        charArrayPtr* initializePuzzle();
        const int& setSize();

    public:
        JumblePuzzle(); // default constructor
        JumblePuzzle(const string& toHide, const string& difficulty); // parametrized constructor
        JumblePuzzle(const JumblePuzzle&); // copy constructor
        ~JumblePuzzle(); // Destructor
        JumblePuzzle& operator=(const JumblePuzzle&);
        charArrayPtr* getJumble() const;
        int getSize() const;
        int getRowPos() const;
        int getColPos() const;
        char getDirection() const;
};

class BadJumbleException {
	public:
		BadJumbleException(const string& message);
		string& what();
	private:
		string message;
};


