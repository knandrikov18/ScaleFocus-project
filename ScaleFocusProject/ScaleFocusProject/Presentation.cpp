#include <iostream>
#include <fstream>
#include "Presentation.h"
#include "Data.h"

using namespace std;

void MainMenu()
{
	int choice{};

	system("cls");

	cout << endl;
	cout << "                                        +---------------------------------+                                       " << endl;
	cout << "                                        |                                 |                                       " << endl;
	cout << "                  *                     |   Welcome to the Battlefield!   |                        *              " << endl;
	cout << "                * *                     |                                 |                      * *              " << endl;
	cout << "              *   *                     +---------------------------------+                    *   *              " << endl;
	cout << "            *     *                                                                          *     *              " << endl;
	cout << "          *       *                        +---------------------------+                   *       *              " << endl;
	cout << "        * * * * * *                        |     ENTER TO YOUR ACC     |                 * * * * * *              " << endl;
	cout << "                  *                        +---------------------------+                           *              " << endl;
	cout << "                  *                                                                                *              " << endl;
	cout << "  * * * * * * * * * * * * * * * *       +---------------------------------+        * * * * * * * * * * * * * * * *" << endl;
	cout << "   *                           *        |            1. Login             |         *                           * " << endl;
	cout << "    *                         *         |            2. Register          |          *                         *  " << endl;
	cout << "     *                       *          |            9. Exit              |           *                       *   " << endl;
	cout << "      * * * * * * * * * * * *           +---------------------------------+            * * * * * * * * * * * *    " << endl << endl;

	cout << "                                               Choose an option: ";
	while (!(cin >> choice))
	{
		cout << "\n                                  Not an integer, please try again: "; cin >> choice;
		cin.clear();
		cin.ignore(123, '\n');
	}

	while (choice != 1 && choice != 2 && choice != 9)
	{
		cout << endl;
		cout << "\n                              Invalid option, please try again: "; cin >> choice;
		cout << endl;
	}

	switch (choice)
	{
	case 1:
		login();
		break;
	case 2:
		Register();
		break;
	case 9:
		break;
	}
}

void login()
{
	string username, password;
	string result = "invalidAccount";

	system("cls");

	while (result == "invalidAccount")
	{

		cout << "                                      +------------------------------------+" << endl;
		cout << "                                      |               Login                |\n";
		cout << "                                      +------------------------------------+\n" << endl;
		cout << "                                               Username: "; cin >> username;
		cout << "                                               Password: "; cin >> password;
		result = checkAcc(username, password);
	}

	if (checkAcc(username, password) == "Please try to login again!")
	{
		login();
	}
	else
	{
		askingUser();
	}

	cout << endl;
}

void Register()
{
	string username, password, c_password;
	ofstream myfile("acc.txt", ios::app | ios::ate);

	system("cls");

	cout << endl;
	cout << "                                       +------------------------------------+" << endl;
	cout << "                                       |              Register              |" << endl;
	cout << "                                       +------------------------------------+\n" << endl;
	cout << "                             !!!The username and password MUST not be over 10 letters!!!" << endl << endl;;
	cout << "                                                 Username: "; cin >> username;
	cout << "                                                 Password: "; cin >> password;
	cout << "                                                 Confirm password: "; cin >> c_password;
	cout << endl;

	while (username.length() > 10 || password.length() > 10)
	{
		myfile.clear();
		cout << "\n                        The username or password is over the limit, please try again!!!\n" << endl;
		cout << "                                                 Username: "; cin >> username;
		cout << "                                                 Password: "; cin >> password;
		cout << "                                                 Confirm password: "; cin >> c_password;
	}

	while (c_password != password)
	{
		cout << "\n                              Invalid confirm password, please try again: "; cin >> c_password;
	}

	cout << endl;
	myfile << username << "," << password << ",\n";
	myfile.close();
	askingUser();
}