/*
 * fraction_14cm24.h
 *
 *  Created on: Sep 22, 2018
 *      Author: chrismaltais
 */

#pragma once

using namespace std;
#include <iostream>


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
		Fraction operator++(int);
		Fraction& operator++();
		Fraction& operator+=(const Fraction& right);

	// I/O Operators
	friend ostream& operator<<(ostream& out, const Fraction& fraction);

	// Binary Operators
	friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

	// Unary Operators
	friend Fraction operator-(const Fraction& frac);

};



