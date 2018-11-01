#include "GUI.h"
using namespace GUIPart;
int main(int argc, char**) {
	int dummyVar;
	int* frac = addFrac(3, 1, 9, 9);
	cout << frac[0] << "/" << frac[1] << endl;
	cin >> dummyVar;
	return 0;
}

