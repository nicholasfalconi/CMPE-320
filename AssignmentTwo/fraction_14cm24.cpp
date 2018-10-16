/*
 * fraction_14cm24.cpp
 *
 *  Created on: Sep 22, 2018
 *      Author: chrismaltais
 */
#include <iostream>
#include <cmath>
#include "fraction_14cm24.h"
using namespace std;

Fraction Fraction::reduce(Fraction& frac) {
	frac.numerator_ = frac.numerator_/GCD(frac.numerator_, frac.denominator_);
	frac.denominator_ = frac.denominator_/GCD(frac.numerator_, frac.denominator_);
	return frac;
}

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

const int& Fraction::numerator() const { // @suppress("Ambiguous problem")
	return numerator_;
}

const int& Fraction::denominator() const{ // @suppress("Ambiguous problem")
	return denominator_;
}

ostream& operator<<(ostream& out, const Fraction& fraction) {
	out << fraction.numerator_ << "/" << fraction.denominator_;
	return out;
}

istream& operator>>(istream& in, const Fraction& fraction) {
	in >> fraction.numerator_ >> fraction.denominator_;
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







