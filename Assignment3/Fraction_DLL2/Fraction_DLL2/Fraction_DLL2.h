/*
* fraction_14cm24.h
*
*  Created on: Sep 22, 2018
*      Author: chrismaltais
*/

#pragma once
#ifdef FRACDLL_EXPORTS
#define FRACDLL __declspec(dllexport)
#else
#define FRACDLL __declspec(dllimport)
#endif

using namespace std;
#include <iostream>

FRACDLL int* addFrac(int num1, int denom1, int num2, int denom2);
FRACDLL int* subFrac(int num1, int denom1, int num2, int denom2);
FRACDLL int* multFrac(int num1, int denom1, int num2, int denom2);
FRACDLL int* divFrac(int num1, int denom1, int num2, int denom2);

// An exception that is thrown if an attempt is made to create a
// Fraction with a zero value denominator.
class FractionException {
public:
	FractionException(const string&);
	string& what();
private:
	string message;
};

class Fraction {
public:
	// Constructs a fraction with numerator 0 and denominator 1.
	Fraction();

	// Constructs a fraction with numerator t and denominator 1.
	Fraction(int t);

	// Constructs a fraction with given numerator and denominator.
	Fraction(int t, int b);

	// Returns the numerator.
	int numerator() const;

	// Returns the denominator.
	int denominator() const;

	// Updates a fraction by adding in another fraction value.
	Fraction& operator+=(const Fraction& right);

	// Increment fraction by 1.
	Fraction& operator++(); 			// Preincrement form
	Fraction operator++(int unused); // Postincrement form

									 // Compare one fraction value to another.
									 // Result is negative if less than right, zero if equal, and
									 // positive if greater than right.
	int compare(const Fraction& right) const;

private:
	// Place the fraction in lowest common denominator form.
	void normalize();

	// Compute the greatest common denominator of two integer values.
	int gcd(int n, int m);

	int top;			// numerator
	int bottom;		// denominator
};

// Non-member overloaded arithmetic operators
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& value);





