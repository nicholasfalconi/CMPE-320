/*
 * fraction_14cm24.cpp
 *
 *  Created on: Sep 22, 2018
 *      Author: chrismaltais
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>
#include "fraction_14cm24.h"
using namespace std;

Fraction::Fraction(int num, int denom) {
	if (denom == 0) {
		throw FractionException("Denominator cannot equal 0!");
	}
	numerator_ = num != 0 || denom != 1 ? num/GCD(num, denom) : num;
	denominator_ = num != 0 || denom != 1 ? denom/GCD(num, denom) : denom;
	if (numerator_ < 0 && denominator_ < 0) {
		numerator_ = -numerator_;
		denominator_ = -denominator_;
	} else if (denominator_ < 0 && numerator_ > 0) {
		numerator_ = -numerator_;
		denominator_ = -denominator_;
	}
}

int Fraction::GCD(const int& n, const int& m) {
	if (m == 0 || n == 0) return 1;
	int m_abs = abs(m);
	int n_abs = abs(n);
	if (m_abs <= n_abs && n_abs % m_abs == 0) {
		return m_abs;
	} else if (n_abs < m_abs) {
		return GCD(m_abs, n_abs);
	} else {
		return GCD(m_abs, n_abs % m_abs);
	}
}

const int& Fraction::numerator() const {
	return numerator_;
}

const int& Fraction::denominator() const{
	return denominator_;
}

ostream& operator<<(ostream& out, const Fraction& fraction) {
	out << fraction.numerator_ << "/" << fraction.denominator_;
	return out;
}

// Use string stream to split input by '/' and store values in vector (container)
// If '/' is not in input, container will be of size 1 containing int
// container[0] should be numerator
// container[1] should be denominator
// Convert string values to int using stoi
istream& operator>>(istream& in, Fraction& fraction) {
	string input;
	in >> input;
	stringstream ss(input);
	string number;
	vector<string> container;
	while(getline(ss, number, '/')) {
		container.push_back(number);
	}
	if (container.size() < 2) {
		fraction.numerator_ = stoi(input);
		fraction.denominator_ = 1;
	} else if (stoi(container[1]) == 0) {
		throw FractionException("Denominator is equal to 0, invalid fraction.");
	} else {
		fraction.numerator_ = stoi(container[0]);
		fraction.denominator_ = stoi(container[1]);
	}
	return in;
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
	int num = (lhs.numerator() * rhs.denominator()) + (rhs.numerator() * lhs.denominator());
	int denom = lhs.denominator() * rhs.denominator();
	return Fraction(num, denom);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
	int num = (lhs.numerator() * rhs.denominator()) - (rhs.numerator() * lhs.denominator());
	int denom = lhs.denominator() * rhs.denominator();
	return Fraction(num, denom);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
	int num = lhs.numerator() * rhs.numerator();
	int denom = lhs.denominator() * rhs.denominator();
	return Fraction(num, denom);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
	int num = lhs.numerator() * rhs.denominator();
	int denom = lhs.denominator() * rhs.numerator();
	return Fraction(num, denom);
}

Fraction& Fraction::operator-() {
	numerator_ = -numerator_;
	return *this;
}

Fraction Fraction::operator++(int unused) {
	Fraction frac;
	frac.numerator_ = numerator_;
	frac.denominator_ = denominator_;
	numerator_ += denominator_;
	return frac;
}

Fraction& Fraction::operator++() {
	numerator_ = numerator_ + denominator_;
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& right) {
	numerator_ = (numerator_ * right.denominator_) + (right.numerator_ * denominator_);
	denominator_ = denominator_ * right.denominator_;
	int divisor = GCD(numerator_, denominator_);
	numerator_ /= divisor;
	denominator_ /= divisor;
	return *this;
}

bool operator==(const Fraction& lhs, const Fraction& rhs) {
	if (lhs.numerator() *rhs.denominator() == lhs.denominator() * rhs.numerator()) {
		return true;
	} else {
		return false;
	}
}

bool operator<(const Fraction& lhs, const Fraction& rhs) {
	if (lhs.numerator() *rhs.denominator() < lhs.denominator() * rhs.numerator()) {
		return true;
	} else {
		return false;
	}
}

bool operator>(const Fraction& lhs, const Fraction& rhs) {
	if (lhs.numerator() *rhs.denominator() > lhs.denominator() * rhs.numerator()) {
		return true;
	} else {
		return false;
	}
}

bool operator<=(const Fraction& lhs, const Fraction& rhs) {
	if (lhs.numerator() *rhs.denominator() <= lhs.denominator() * rhs.numerator()) {
		return true;
	} else {
		return false;
	}
}

bool operator>=(const Fraction& lhs, const Fraction& rhs) {
	if (lhs.numerator() *rhs.denominator() >= lhs.denominator() * rhs.numerator()) {
		return true;
	} else {
		return false;
	}
}

bool operator!=(const Fraction& lhs, const Fraction& rhs) {
	if (lhs.numerator() * rhs.denominator() != lhs.denominator() * rhs.numerator()) {
		return true;
	} else {
		return false;
	}
}

FractionException::FractionException(const string& message) : message(message) {}
string& FractionException::what() { return message; }







