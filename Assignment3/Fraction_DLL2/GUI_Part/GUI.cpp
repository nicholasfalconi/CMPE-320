#include "GUI.h"
using namespace GUIPart;
int main(int argc, char**) {
	GUI^ g = gcnew GUI();
	Application::Run(g);
	return 0;
}

