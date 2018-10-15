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

const int Fraction::numerator() { // @suppress("Ambiguous problem")
	return numerator_;
}

const int Fraction::denominator() { // @suppress("Ambiguous problem")
	return denominator_;
}

ostream& operator<<(ostream& out, const Fraction& fraction) {
	out << fraction.numerator_ << "/" << fraction.denominator_;
	return out;
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
	int num = (lhs.numerator_ * rhs.denominator_) + (rhs.numerator_ * lhs.denominator_);
	int denom = lhs.denominator_ * rhs.denominator_;
	return Fraction(num, denom);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
	int num = (lhs.numerator_ * rhs.denominator_) - (rhs.numerator_ * lhs.denominator_);
	int denom = lhs.denominator_ * rhs.denominator_;
	return Fraction(num, denom);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
	int num = lhs.numerator_ * rhs.numerator_;
	int denom = lhs.denominator_ * rhs.denominator_;
	return Fraction(num, denom);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
	int num = lhs.numerator_ * rhs.denominator_;
	int denom = lhs.denominator_ * rhs.numerator_;
	return Fraction(num, denom);
}

Fraction operator-(const Fraction& frac) {
	return Fraction (-frac.numerator_, frac.denominator_);
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







