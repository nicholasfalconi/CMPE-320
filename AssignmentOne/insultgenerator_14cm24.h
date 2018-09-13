/*
 * insultgenerator_14cm24.h
 *
 *  Created on: Sep 11, 2018
 *      Author: chrismaltais
 */

// Include Guards
#ifndef INSULTGENERATOR_14CM24_H_
#define INSULTGENERATOR_14CM24_H_

// Dependencies
#include <vector>
#include <exception>

class InsultGenerator {
	private:
		std::vector<std::string> firstColumnWords;
		std::vector<std::string> secondColumnWords;
		std::vector<std::string> thirdColumnWords;
		std::string getRandomWord(std::vector<std::string> words);
	public:
		InsultGenerator();
		void initialize();
		std::string talkToMe();
		std::vector<std::string> generate(int numInsults);
		void generateAndSave(std::string fileName, int numInsults);
};

class FileException : public exception {

};

#endif /* INSULTGENERATOR_14CM24_H_ */
