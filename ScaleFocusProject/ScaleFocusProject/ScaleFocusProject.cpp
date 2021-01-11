#include <iostream>
#include <windows.h>  
#include "Presentation.h"

using namespace std;

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // add color to the console
	MainMenu();
}