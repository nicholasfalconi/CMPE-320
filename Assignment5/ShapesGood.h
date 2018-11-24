/*
 * Some good ol' shapes.
 * Written by: Chris Maltais
 *
 * For CISC/CMPE 320, Assignment 5
 */
#pragma once

#include <string>
using namespace std;

class Shape {
public:
	Shape(int, int);
	virtual ~Shape();
	int getLength();
	int getWidth();
private:
	int length, width;
};

class Fillable {
public:
    Fillable(string);
    virtual ~Fillable();
    string getFillColour();
private:
    string fillColour;
}

class Text {
    
}
class Square : public Shape {
public:
	Square(const int&, const int&, const string&);
	void draw();
    const string& getOutlineColour();
private:
    const string& outlineColour;
};

class FilledSquare : public Shape, public Fillable {
public:
	FilledSquare(int, int);
	void drawOutside(string);
	void fill(string);
};

class FilledTextSquare : public Shape {
public:
	FilledTextSquare(int, int);
	void drawOutside(string);
	void fill(string);
	void drawText(string);
};