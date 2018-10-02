/*
 * insultgenerator_14cm24.h
 *
 *  Created on: Sep 11, 2018
 *      Author: chrismaltais
 */

// Include Guards
#pragma once

// Dependencies
#include <vector>
#include <exception>
using namespace std;

class InsultGenerator {
	private:
		vector<string> firstColumnWords;
		vector<string> secondColumnWords;
		vector<string> thirdColumnWords;
		string getRandomWord(const vector<string>& words);
	public:
		void initialize();
		string talkToMe();
		vector<string> generate(const int& numInsults);
		void generateAndSave(const string& fileName, const int& numInsults);
};

class NumInsultsOutOfBounds : public exception {
	public:
		NumInsultsOutOfBounds(const string& message);
		string& what();
	private:
		string message;
};

class FileException : public exception {
	public:
		FileException(const string& message);
		string& what();
	private:
		string message;
};
