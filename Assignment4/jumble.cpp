///*
// * jumble.cpp
// *
// *  Created on: Nov 4, 2018
// *      Author: Chris Maltais
// */
//
//
#include "jumble.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

BadJumbleException::BadJumbleException(const string& m) : message(m) {}
string& BadJumbleException::what() { return message; }

JumblePuzzle::JumblePuzzle(const string& hiddenWord, const string& difficulty) {
    bool isValidDifficulty = difficulty == "easy" || difficulty == "medium" || difficulty == "hard";
    bool isValidHiddenWord = hiddenWord.length() > 0;
    if (isValidDifficulty && isValidHiddenWord) {
        this->hiddenWord = hiddenWord;
        this->difficulty = difficulty;
        // Get size of puzzle to be created
        this->puzzleSize = setSize();
        // Create puzzle of length size with random letters
        this->puzzle = initializePuzzle();
    } else if (!isValidDifficulty) {
        throw BadJumbleException("Invalid difficulty - please enter 'easy', 'medium' or 'hard' (case sensitive)");
    } else if (!isValidHiddenWord) {
        throw BadJumbleException("Invalid word to hide - please enter another word.");
    }
}

const int& JumblePuzzle::setSize() {
    if (this->difficulty == "easy") {
        return this->hiddenWord.length() * 2;
    } else if (this->difficulty == "medium") {
        return this->hiddenWord.length() * 3;
    } else if (this->difficulty == "hard") {
        return this->hiddenWord.length() * 4;
    }
    return -1;
}

charArrayPtr* JumblePuzzle::initializePuzzle() {
    charArrayPtr* completePuzzle = initializeRandomPuzzle(this->puzzleSize);
    bool wordPlaced = false;
    int row;
    int col;
    int hiddenWordIdx;
    while (!wordPlaced) {
        this->direction = this->directionArr[rand() % 4];
        this->rowPos = rand() % (this->puzzleSize);
        this->colPos = rand() % (this->puzzleSize);
        row = this->rowPos;
        col = this->colPos;
        hiddenWordIdx = 0;
        if (direction == 'n') { // randomPuzzle[row--][col]
            while (row >= 0 && hiddenWordIdx < this->hiddenWord.length()) {
                completePuzzle[row--][col] = this->hiddenWord[hiddenWordIdx++];
                cout << "Hidden word index is: " << hiddenWordIdx << endl;
                cout << "Column is: " << row << endl;
            }
            if (hiddenWordIdx == this->hiddenWord.length()) {
                wordPlaced = true;
            }
        } else if (direction == 'e') {  // randomPuzzle[row][col++]
            while (col < this->puzzleSize && hiddenWordIdx < this->hiddenWord.length()) {
                completePuzzle[row][col++] = this->hiddenWord[hiddenWordIdx++];
            }
            if (hiddenWordIdx == this->hiddenWord.length()) {
                wordPlaced = true;
            }
        } else if (direction == 's') { // randomPuzzle[row++][col]
            while (row < this->puzzleSize && hiddenWordIdx < this->hiddenWord.length()) {
                completePuzzle[row++][col] = this->hiddenWord[hiddenWordIdx++];
            }
            if (hiddenWordIdx == this->hiddenWord.length()) {
                wordPlaced = true;
            }
        } else if (direction == 'w') { // randomPuzzle[row][col--]
            while (col >= 0 && hiddenWordIdx < this->hiddenWord.length()) {
                completePuzzle[row][col--] = this->hiddenWord[hiddenWordIdx++];
            }
            if (hiddenWordIdx == this->hiddenWord.length()) {
                wordPlaced = true;
            }
        }
    }
    return completePuzzle;
}

charArrayPtr* JumblePuzzle::initializeRandomPuzzle(const int& size) {
    charArrayPtr* randomPuzzle = new charArrayPtr[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        randomPuzzle[i] = new char[size];
        for (int j = 0; j < size; j++) {
            randomPuzzle[i][j] = 'a' + rand() % 26; // Select random letter using ASCII
        }
    }
    return randomPuzzle;
}

// Destructor
JumblePuzzle::~JumblePuzzle() {
    for (int i = 0; i < this->puzzleSize; i++) {
        delete[] puzzle[i];
    }
    delete[] puzzle;
    puzzle = nullptr;
}

// Copy constructor
JumblePuzzle::JumblePuzzle(const JumblePuzzle& jp) {
    this->puzzleSize = jp.getSize();
    this->rowPos = jp.getRowPos();
    this->colPos = jp.getColPos();
    this->direction = jp.getDirection();

    charArrayPtr* existingPuzzle = jp.getJumble();
    charArrayPtr* newPuzzle = new charArrayPtr[this->puzzleSize];

    for (int i = 0; i < this->puzzleSize; i++) {
        newPuzzle[i] = new char[this->puzzleSize];
        for (int j = 0; j < this->puzzleSize; j++) {
            newPuzzle[i][j] = existingPuzzle[i][j];
        }
    }
    this->puzzle = newPuzzle;
    
}

// Assignment Operator
JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < puzzleSize; i++) {
            delete[] puzzle[i];
        }
        delete[] puzzle;
        this->puzzleSize = rhs.getSize();
        this->rowPos = rhs.getRowPos();
        this->colPos = rhs.getColPos();
        this->direction = rhs.getDirection();

        charArrayPtr* existingPuzzle = rhs.getJumble();
        charArrayPtr* newPuzzle = new charArrayPtr[this->puzzleSize];

        for (int i = 0; i < this->puzzleSize; i++) {
            newPuzzle[i] = new char[this->puzzleSize];
            for (int j = 0; j < this->puzzleSize; j++) {
                newPuzzle[i][j] = existingPuzzle[i][j];
            }
        }
        this->puzzle = newPuzzle;
    }
    return *this;
}

int JumblePuzzle::getSize() const {
    return this->puzzleSize;
}

int JumblePuzzle::getRowPos() const {
    return this->rowPos;
}

int JumblePuzzle::getColPos() const {
    return this->colPos;
}

char JumblePuzzle::getDirection() const {
    return this->direction;
}

charArrayPtr* JumblePuzzle::getJumble() const {
    return this->puzzle;
}

