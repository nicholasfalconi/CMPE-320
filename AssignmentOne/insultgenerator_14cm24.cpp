#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class InsultGenerator {
	private:
		vector <string> firstColumnWords;
		vector <string> secondColumnWords;
		vector <string> thirdColumnWords;
		string getRandomWord(vector<string> words) {
			srand(time(0));
			return words[rand() % words.size()];
		}

	public:
		void initialize() {
			ifstream inputFile("InsultsSource.txt");
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

		string talkToMe() {
			return getRandomWord(firstColumnWords) + " " + getRandomWord(secondColumnWords) + " " + getRandomWord(thirdColumnWords);
		}


};
int main() {
	InsultGenerator ig;
	ig.initialize();
	cout << ig.talkToMe() << endl;
	return 0;
}
