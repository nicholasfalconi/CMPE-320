/*
 * Shapes doing things.
 * Written by: Chris Maltais
 *
 * For CISC/CMPE 320, Assignment 5
 */
#include <iostream>
#include <string>
#include "ShapesGood.h"

using namespace std;

// BEGIN SHAPE DEFINITIONS
Shape::Shape(int len, int wid) {
    this->length = len;
    this->width = wid;
}

Shape::~Shape() {}

void Shape::draw() {
    cout << "Base class draw. This function would not draw a shape." << endl;
}
int Shape::getLength() {
    return this->length;
}

int Shape::getWidth() {
    return this->width;
}

// END SHAPE DEFINITIONS

// BEGIN FILLABLE DEFINITONS
Fillable::Fillable(string colour) {
    this->fillColour = colour;
}

Fillable::~Fillable() {}

string Fillable::getFillColour() {
    return this->fillColour;
}
// END FILLABLE DEFINITIONS

// BEGIN TEXT DEFINITIONS 
Text::Text(string message) {
    this->text = message;
}

Text::~Text() {}

string Text::getText() {
    return this->text;
}
// END TEXT DEFINITIONS

// BEGIN SQUARE DEFINITIONS
Square::Square(int len, int wid, string colour) : Shape(len, wid) {
    outlineColour = colour;
}

string Square::getOutlineColour() {
    return this->outlineColour;
}

void Square::draw() {
    cout << "\nDrawing a " + getOutlineColour() + " square.";
}
// END SQUARE DEFINITIONS

// BEGIN FILLED SQUARE DEFINITIONS
FilledSquare::FilledSquare(int len, int wid, string outlineColour, string fillColour) : Square(len, wid, outlineColour), Fillable(fillColour) {}
void FilledSquare::draw() {
    cout << "\nDrawing a " + getOutlineColour() + " square.";
    cout << " With " + getFillColour() + " fill";
}
// END FILLED SQUARE DEFINITIONS

// BEGIN FILLED TEXT SQUARE DEFINITIONS
FilledTextSquare::FilledTextSquare(int len, int wid, string colour, string fill, string text) : Square(len, wid, colour), Fillable(colour), Text(text) {}
void FilledTextSquare::draw() {
	cout << "\nDrawing a " + getOutlineColour() + " square.";
    cout << " With " + getFillColour() + " fill";
    cout << " Containing the text: \"" << getText() << "\".";
}
// END FILL TEXT SQUARE DEFINITIONS
