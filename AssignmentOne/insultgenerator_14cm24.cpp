#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <time.h>
#include "insultgenerator_14cm24.h"
using namespace std;

string InsultGenerator::getRandomWord(const vector<string>& words) {
	return words[rand() % words.size()];
}

void InsultGenerator::initialize() {
	ifstream inputFile("InsultsSource.txt");
	if (!inputFile.is_open()) {
		throw FileException("File could not be read. Please try again.");
	}
	string oneLine;
	while ( getline(inputFile, oneLine, '\n') ) {
		vector <string> currentLineWords;
		stringstream ss(oneLine);
		string word;
		while (getline(ss, word, '\t')) {
			currentLineWords.push_back(word);
		}
		firstColumnWords.push_back(currentLineWords[0]);
		secondColumnWords.push_back(currentLineWords[1]);
		thirdColumnWords.push_back(currentLineWords[2]);
	}
}

string InsultGenerator::talkToMe() {
	return getRandomWord(firstColumnWords) + " " + getRandomWord(secondColumnWords) + " " + getRandomWord(thirdColumnWords);
}

vector <string> InsultGenerator::generate(const int& numInsults) {
	vector<string> allInsults;
	set<string> mySet;
	string insult;
	pair<set<string>::iterator, bool> ret;
	if (numInsults > 10000) {
		throw NumInsultsOutOfBounds("Number of insults requested is out of bounds. \nPlease try a number within the range 1 - 10000.\n");
	}
	srand(time(NULL));
	for (int i = 0; i < numInsults; i++) {
		insult = talkToMe();
		ret = mySet.insert(insult);
		bool isUnique(ret.second);
		while (!isUnique) {
			insult = talkToMe();
			ret = mySet.insert(insult);
			isUnique = ret.second;
		}
	}
	allInsults.assign(mySet.begin(), mySet.end());
	return allInsults;
}

void InsultGenerator::generateAndSave(const string& fileName, const int& numInsults) {
	vector<string> allInsults = generate(numInsults);
	ofstream outFile(fileName);
	if (!outFile.is_open()) { // try catch?
		throw FileException("File could not be read. Please try again.");
	}
	for (auto insult : allInsults) {
		outFile << insult << endl;
	}
}

FileException::FileException(const string& message) : message(message) {}
string& FileException::what() { return message; }

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message) {}
string& NumInsultsOutOfBounds::what() { return message; }
