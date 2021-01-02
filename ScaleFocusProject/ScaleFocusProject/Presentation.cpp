#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>  
#include <stdlib.h>
#include <time.h>
#include "Presentation.h"
#include "Data.h"

using namespace std;

void points1()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf(R"(**)");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}

void points2()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf(R"(**)");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}

void difficultyForPlayer()
{
	int choice;

	system("cls");

	cout << endl;
	cout << "                                      +--------------------------+" << endl;
	cout << "                                      |        Difficulty:       |" << endl;
	cout << "                                      +--------------------------+" << endl << endl;
	cout << "                                             1. Normal" << endl;
	cout << "                                             2. Hard  " << endl;
	cout << "                                             3. Back  " << endl << endl;

	cout << "                                            Choose: "; 
	while (!(cin >> choice))
	{
		cout << "\n                                  Not an integer, please try again: "; cin >> choice;
		cin.clear();
		cin.ignore(123, '\n');
	}

	while (choice != 1 && choice != 2 && choice != 3)
	{
		cout << "                          Invalid input, please try again: "; cin >> choice;
	}

	switch (choice)
	{
	case 1: battleVsPlayerNormal();
		break;
	case 2: battleVsPlayerHard();
		break;
	case 3: askingUser();
		break;
	}
}

void difficultyForComputer()
{
	int choice;

	system("cls");

	cout << endl;
	cout << "                                      +--------------------------+" << endl;
	cout << "                                      |        Difficulty:       |" << endl;
	cout << "                                      +--------------------------+" << endl << endl;
	cout << "                                             1. Normal" << endl;
	cout << "                                             2. Hard  " << endl;
	cout << "                                             3. Back  " << endl << endl;

	cout << "                                            Choose: "; 
	while (!(cin >> choice))
	{
		cout << "\n                                  Not an integer, please try again: "; cin >> choice;
		cin.clear();
		cin.ignore(123, '\n');
	}

	while (choice != 1 && choice != 2 && choice != 3)
	{
		cout << "                          Invalid input, please try again: "; cin >> choice;
	}

	switch (choice)
	{
	case 1: battleVsComputerNormal();
		break;
	case 2: battleVsComputerHard();
		break;
	case 3: askingUser();
		break;
	}
}

void rules()
{
	int choice;

	system("cls");

	cout << endl;
	cout << "                                       +--------------------+" << endl;
	cout << "                                       |        Rules       |" << endl;
	cout << "                                       +--------------------+" << endl << endl;
	cout << "         +----------------------------+                      +----------------------------+" << endl;
	cout << "         |         Normal mode        |                      |          Hard mode         |" << endl;
	cout << "         +----------------------------+                      +----------------------------+" << endl;
	cout << "         |1. First enter 4 numbers    |                      |1. First enter 4 numbers    |" << endl;
	cout << "         |     for coordinates:       |                      |      for coordinates       |" << endl;
	cout << "         | WITHOUT REPETITVE NUMBERS! |                      |   WITH REPETITVE NUMBERS!  |" << endl;
	cout << "         |                            |                      |                            |" << endl;
	cout << "         |2. Points for guessing      |                      |2. Points for guessing      |" << endl;
	cout << "         |   - only the number: "; points1(); cout << "    |                      |   - only the number: "; points1(); cout << "    |" << endl;
	cout << "         |   - the number and the     |                      |   - the number and the     |" << endl;
	cout << "         |     position: "; points2(); cout << "           |                      |     position: "; points2(); cout << "           |" << endl;
	cout << "         |                            |                      |                            |" << endl;
	cout << "         |3. You have only 13 tries   |                      |3. You have only 13 tries   |" << endl;
	cout << "         |   to guess the positions   |                      |   to guess the positions   |" << endl;
	cout << "         |   of the 4 numbers or you  |                      |   of the 4 numbers or you  |" << endl;
	cout << "         |           LOSE             |                      |           LOSE             |" << endl;
	cout << "         |                            |                      |                            |" << endl;
	cout << "         |4. To win you should to     |                      |4. To win you should to     |" << endl;
	cout << "         |   collect 4 of these: "; points2(); cout << "   |                      |   collect 4 of these: "; points2(); cout << "   |" << endl;
	cout << "         |                            |                      |                            |" << endl;
	cout << "         |5. If you choose to play    |                      |5. If you choose to play    |" << endl;
	cout << "         |   against the computer,    |                      |   against the computer,    |" << endl;
	cout << "         |   the computer generate    |                      |   the computer generate    |" << endl;
	cout << "         |       the numbers!         |                      |       the numbers!         |" << endl;
	cout << "         +----------------------------+                      +----------------------------+" << endl << endl;
	cout << "                                           Type 1 to back: "; 
	
	while (!(cin >> choice))
	{
		cout << "\n                                  Not an integer, please try again: "; cin >> choice;
		cin.clear();
		cin.ignore(123, '\n');
	}

	while (choice != 1)
	{
		cout << "                          Invalid input, please try again: "; cin >> choice;
	}

	switch (choice)
	{
	case 1: askingUser();
		break;
	}
}

void customizeView(int arr[])
{
	int turns = 1, choice;

	while (true)
	{
		int guess_number[4];
		bool secret_digit_used[4] = { false, false, false, false };
		bool guess_digit_used[4] = { false, false, false, false };

		cout << "                                       " << turns << ". Guess the number: "; getUserInput(guess_number); turns++;

		cout << endl;
		cout << endl;

		int num1 = guessedNumbersAndPositions(arr, guess_number, secret_digit_used, guess_digit_used);
		int num2 = guessedNumbers(arr, guess_number, secret_digit_used, guess_digit_used);

		if (num1 == 0 && num2 == 0)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |                       |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |                       | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 0 && num2 == 1)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |                       |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |   "; points1(); cout << "                  | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 4 && num2 == 0)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |   "; points2(); cout << "   "; points2(); cout << "   "; points2(); cout << "   "; points2(); cout << "   |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |                       | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
			cout << "                                        Congratulations, you win! " << endl << endl;
			cout << "                                        Enter 1 to back:  "; cin >> choice;

			while (choice != 1)
			{
				cout << "                                   Invalid input,, try again: "; cin >> choice;
			}

			switch (choice)
			{
				case 1: askingUser();
					break;
			}
		}
		if (num1 == 0 && num2 == 4)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |                       |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |   "; points1(); cout << "   "; points1(); cout << "   "; points1(); cout << "   "; points1(); cout << "   "; cout << "| " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 2 && num2 == 2)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |   "; points2(); cout << "   "; points2(); cout << "             |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |   "; points1(); cout << "   "; points1(); cout << "             | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 1 && num2 == 1)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |   "; points2(); cout << "                  |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |   "; points1(); cout << "                  | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 3 && num2 == 0)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |   "; points2(); cout << "   "; points2(); cout << "   "; points2(); cout << "        |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |                       | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 3 && num2 == 1)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |   "; points2(); cout << "   "; points2(); cout << "   "; points2(); cout << "        |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |   "; points1(); cout << "                  | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 1 && num2 == 3)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |   "; points2(); cout << "                  |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |   "; points1(); cout << "   "; points1(); cout << "   "; points1(); cout << "        | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 2 && num2 == 0)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |   "; points2(); cout << "   "; points2();  cout << "             |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |                       | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 1 && num2 == 2)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |   "; points2(); cout << "                  |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |   "; points1(); cout << "   "; points1(); cout << "             | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 1 && num2 == 0)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |   "; points2(); cout << "                  |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |                       | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 0 && num2 == 3)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |                       |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |   "; points1(); cout << "   "; points1(); cout << "   "; points1(); cout << "        | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 0 && num2 == 2)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |                       |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |   "; points1(); cout << "   "; points1(); cout << "             | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (num1 == 2 && num2 == 1)
		{
			cout << " Guessed numbers and positions              Player's guesses                    Guessed numbers       " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << "  |   "; points2(); cout << "   "; points2();  cout << "             |             |  " << guess_number[0] << "  |  " << guess_number[1] << "  |  " << guess_number[2] << "  |  " << guess_number[3] << "  |           |   "; points1(); cout << "                  | " << endl;
			cout << "  +-----------------------+             +-----------------------+           +-----------------------+ " << endl;
			cout << endl << endl;
		}
		if (turns > 13)
		{
			cout << "\n                                    You loose, better next time!" << endl << endl;
			cout << "                                        Enter 1 to back:  "; cin >> choice;

			while (choice != 1)
			{
				cout << "                                 Invalid input,, try again: "; cin >> choice;
			}

			switch (choice)
			{
			case 1: askingUser();
				break;
			}
		}
	}
}

void battleVsPlayerNormal()
{
	int arr[4];

	system("cls");

	cout << endl;
	cout << "                                      +---------------------------+" << endl;
	cout << "                                      |                           |" << endl;
	cout << "                                      |        LET'S PLAY         |" << endl;
	cout << "                                      |                           |" << endl;
	cout << "                                      +---------------------------+" << endl << endl;
	cout << endl;

	cout << "                                       Enter the coordinates: ";
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}

	inRange(arr);
	repetitiveNumbers(arr);

	cout << endl;
	cout << "                                         Battleship's coordinate " << endl;
	cout << "                                        +-----------------------+" << endl;
	cout << "                                        |  ?  |  ?  |  ?  |  ?  |" << endl;
	cout << "                                        +-----------------------+" << endl << endl;

	customizeView(arr);
}

void battleVsPlayerHard()
{
	int arr[4];

	system("cls");

	cout << endl;
	cout << "                                      +---------------------------+" << endl;
	cout << "                                      |                           |" << endl;
	cout << "                                      |        LET'S PLAY         |" << endl;
	cout << "                                      |                           |" << endl;
	cout << "                                      +---------------------------+" << endl << endl;
	cout << endl;

	cout << "                                      Enter the coordinates: ";
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];

	}

	inRange(arr);

	cout << endl;
	cout << "                                         Battleship's coordinate " << endl;
	cout << "                                        +-----------------------+" << endl;
	cout << "                                        |  ?  |  ?  |  ?  |  ?  |" << endl;
	cout << "                                        +-----------------------+" << endl << endl;

	customizeView(arr);
}

void battleVsComputerNormal()
{
	int arr[4];

	system("cls");

	cout << endl;
	cout << "                                      +---------------------------+" << endl;
	cout << "                                      |                           |" << endl;
	cout << "                                      |        LET'S PLAY         |" << endl;
	cout << "                                      |                           |" << endl;
	cout << "                                      +---------------------------+" << endl << endl;
	cout << endl;

	cout << "                                   The computer generate the coordinates! "; generateSecretNumber(arr); 
	
	repetitiveNumbers(arr);

	// for debugging
	for (int i = 0; i < 4; i++) 
	{
		cout << arr[i] << " ";
	}
	
	cout << endl << endl;
	cout << "                                         Battleship's coordinate " << endl;
	cout << "                                        +-----------------------+" << endl;
	cout << "                                        |  ?  |  ?  |  ?  |  ?  |" << endl;
	cout << "                                        +-----------------------+" << endl << endl;

	customizeView(arr);
}

void battleVsComputerHard()
{
	int arr[4];

	system("cls");

	cout << endl;
	cout << "                                      +---------------------------+" << endl;
	cout << "                                      |                           |" << endl;
	cout << "                                      |        LET'S PLAY         |" << endl;
	cout << "                                      |                           |" << endl;
	cout << "                                      +---------------------------+" << endl << endl;
	cout << endl;

	cout << "                                   The computer generate the coordinates! "; generateSecretNumber(arr);

	// for debugging
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	cout << endl;
	cout << "                                         Battleship's coordinate " << endl;
	cout << "                                        +-----------------------+" << endl;
	cout << "                                        |  ?  |  ?  |  ?  |  ?  |" << endl;
	cout << "                                        +-----------------------+" << endl << endl;

	customizeView(arr);
}

void askingUser()
{
	int number;

	system("cls");

	cout << endl;
	cout << "                                     +------------------------------------+" << endl;
	cout << "                                     |              Welcome               |" << endl;
	cout << "                                     |                                    |" << endl;
	cout << "                                     |                                    |" << endl;
	cout << "                                     |         Choose an option:          |" << endl;
	cout << "                                     +------------------------------------+\n" << endl;

	cout << "                               +----------------------+        +------------------+" << endl;
	cout << "                               |   1. VS 2-nd player  |        |  2. VS computer  |" << endl;
	cout << "                               +----------------------+        +------------------+\n" << endl;
	cout << "                               +------------+                  +-----------+" << endl;
	cout << "                               |  3. Rules  |                  |  4. Back  |" << endl;;
	cout << "                               +------------+                  +-----------+" << endl;
	cout << "                                               Choose an option: "; 

	while (!(cin >> number))
	{
		cout << "\n                                  Not an integer, please try again: "; cin >> number;
		cin.clear();
		cin.ignore(123, '\n');
	}

	while (number != 1 && number != 2 && number != 3 && number != 4)
	{
		cout << "\n                                 Invalid input, please try again: "; cin >> number;
	}

	switch (number)
	{
	case 1:
		difficultyForPlayer();
		break;
	case 2:
		difficultyForComputer();
		break;
	case 3:
		rules();
		break;
	case 4:
		MainMenu();
		break;
	}
	
}

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