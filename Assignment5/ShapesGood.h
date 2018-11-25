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
	Shape(int len, int wid);
	virtual ~Shape();
    virtual void draw();
	int getLength();
	int getWidth();
private:
	int length, width;
};

class Fillable {
public:
    Fillable(string fillColour);
    virtual ~Fillable();
    string getFillColour();
private:
    string fillColour;
};

class Text {
public:
    Text(string message);
    virtual ~Text();
    string getText();
private:
    string text;
};

class Square : public Shape {
public:
	Square(int len, int wid, string outlineColour);
	virtual void draw();
    string getOutlineColour();
private:
    string outlineColour;
};

class FilledSquare : public Square, public Fillable {
public:
	FilledSquare(int len, int wid, string outlineColour, string fillColour);
    virtual void draw();
};

class FilledTextSquare : public Square, public Fillable, public Text {
public:
	FilledTextSquare(int len, int wid, string outlineColour, string fillColour, string message);
    virtual void draw();
};

class Circle : public Shape {
public:
    Circle(int len, int wid, string outlineColour);
    virtual void draw();
    string getOutlineColour();
private:
    string outlineColour;
};

class FilledCircle : public Circle, public Fillable {
public:
    FilledCircle(int len, int wid, string outlineColour, string fillColour);
    virtual void draw();
private:
    string fillColour;
};

class Arc : public Shape {
public:
    Arc(int len, int wid, string outlineColour);
    virtual void draw();
    string getOutlineColour();
private:
    string outlineColour;
};