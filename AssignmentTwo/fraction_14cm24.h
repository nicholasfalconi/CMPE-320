/*
 * fraction_14cm24.h
 *
 *  Created on: Sep 22, 2018
 *      Author: chrismaltais
 */

#ifndef FRACTION_14CM24_H_
#define FRACTION_14CM24_H_

#include <iostream>;

class Fraction {
	private:
		int numerator_;
		int denominator_;
		int GCD(const int& n, const int& m);
		Fraction reduce(Fraction& fraction);
	public:
		Fraction(int numerator = 0, int denominator = 1);
		const int numerator();
		const int denominator();

	// I/O Operators
	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

	// Binary Operators
	friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

	// Unary Operators
	friend Fraction operator-(const Fraction& frac);
	friend Fraction operator++(const Fraction& frac);
};




#endif /* FRACTION_14CM24_H_ */
