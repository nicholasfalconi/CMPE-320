#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <time.h>
#include "insultgenerator_14cm24.h"
using namespace std;

InsultGenerator::InsultGenerator() {
	cout << "InsultGenerator class instantiated." << endl;
};

string InsultGenerator::getRandomWord(vector<string> words) {
	return words[rand() % words.size()];
}


void InsultGenerator::initialize() {
	ifstream inputFile("InsultsSource.txt");
	string oneLine;
	while ( getline(inputFile, oneLine, '\n') ) {
		vector <string> currentLineWords;
		stringstream ss(oneLine);
		string word;
		while (getline(ss, word, '\t')) {
			currentLineWords.push_back(word);
		}
		this->firstColumnWords.push_back(currentLineWords[0]);
		this->secondColumnWords.push_back(currentLineWords[1]);
		this->thirdColumnWords.push_back(currentLineWords[2]);
	}
}

// O(1)
string InsultGenerator::talkToMe() {
	return getRandomWord(firstColumnWords) + " " + getRandomWord(secondColumnWords) + " " + getRandomWord(thirdColumnWords);
}

// O(numInsults * nlogn)
vector <string> InsultGenerator::generate(int numInsults) {
	vector<string> allInsults;
	set<string> mySet;
	string insult;
	pair<set<string>::iterator, bool> ret;
	srand(time(NULL));
	for (int i = 0; i < numInsults; i++) {
		insult = talkToMe();
		ret = mySet.insert(insult); // O(logn)
		bool isUnique(ret.second); // O(1)
		while (!isUnique) {
			insult = talkToMe();
			ret = mySet.insert(insult);
			isUnique = ret.second;
		}
	}
	allInsults.assign(mySet.begin(), mySet.end()); // O(n)
	return allInsults;
}

void InsultGenerator::generateAndSave(string fileName, int numInsults) {
	vector<string> allInsults = generate(numInsults);
	ofstream outFile(fileName);
	for (auto insult : allInsults) {
		outFile << insult << endl;
	}
}

int main() {
	InsultGenerator ig;
	ig.initialize();
	vector<string> insults;
	double start, finish;
	start = clock();
	insults = ig.generate(10000);
	finish = clock();
	ig.generateAndSave("test.txt", 100);
	cout << (finish - start) << " ms to generate insults" << endl;
	return 0;
}
