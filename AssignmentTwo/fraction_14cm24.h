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
		// Accessors
		const int& numerator() const;
		const int& denominator() const;
		// Member Unary operators (no mixed type expressions)
		Fraction operator++(int);
		Fraction& operator++();
		Fraction& operator-();
		// Member Binary Operator (potential mixed type expression)
		Fraction& operator+=(const Fraction& right);

	// I/O Operators
	friend ostream& operator<<(ostream& out, const Fraction& fraction);
	friend istream& operator>>(istream& in, const Fraction& fraction);

};

class FractionException {
	public:
		FractionException(const string& message);
		string& what();
	private:
		string message;
};

// Non-member Binary Operators
Fraction operator+(const Fraction& lhs, const Fraction& rhs);
Fraction operator-(const Fraction& lhs, const Fraction& rhs);
Fraction operator*(const Fraction& lhs, const Fraction& rhs);
Fraction operator/(const Fraction& lhs, const Fraction& rhs);

// Non-member Comparative Operators (better for mixed type expressions)
// Could compare a fraction with an int
bool operator==(const Fraction& rhs, const Fraction& lhs);
bool operator>(const Fraction& lhs, const Fraction& rhs);
bool operator>=(const Fraction& lhs, const Fraction& rhs);
bool operator<(const Fraction& lhs, const Fraction& rhs);
bool operator<=(const Fraction& lhs, const Fraction& rhs);
bool operator!=(const Fraction& lhs, const Fraction& rhs);





