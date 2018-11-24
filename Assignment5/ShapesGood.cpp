FilledTextSquare::FilledTextSquare(int len, int wid, string colour, string fill, string text) : Shape(len, wid), Fillable(colour), Text(text) {}
void FilledTextSquare::draw() {
	cout << "\nDrawing a " + getOutlineColour() + " square.";
    cout << " With " + getFillColour() + " fill";
    cout << " Containing the text: \"" << getText() << "\".";
}

// With gray fill. Containing the text: "Hello!"