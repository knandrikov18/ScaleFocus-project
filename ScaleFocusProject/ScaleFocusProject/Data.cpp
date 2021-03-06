#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include "Data.h"
#include "Presentation.h"

using namespace std;

//*******************************DATA-LAYER***************************************//

string checkAcc(string username, string password) // check if the username and the password are the same as the user's input
{
	ifstream myfile("acc.txt");
	string line[20];

	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, line[0], ',');
			if (line[0] == username)
			{
				getline(myfile, line[1], ',');
				if (line[1] == password)
				{
					getline(myfile, line[2], ',');

					return line[2];
				}
				else
				{
					cout << "\n                                         Invalid password or username!" << endl;
				}
			}
			else
			{
				getline(myfile, line[3]);
			}
		}
		myfile.close();
	}
	cout << "\n                                         Please try to login again!\n" << endl;
	return "invalidAccount";
}

int generateWithoutRepetitveNumbers(int secret_number[]) // generate 4 numbers between 0 and 7
{
	srand(time(0));
	for (int i = 0; i < 4; i++)
	{
		secret_number[i] = rand() % 7 + 0;
	}

	for (int i = 0; i < 4; i++) // check for repetitive numbers
	{
		for (int j = i + 1; j < 4; j++)
		{
			while (secret_number[i] == secret_number[j])
			{
				srand(time(0));
				for (int i = 0; i < 4; i++)
				{
					secret_number[i] = rand() % 7 + 0;
				}
			}
		}
	}

	return *secret_number;
}

int generateRepetitiveNumber(int secret_number[]) // generate 4 numbers between 0 and 7
{
	srand(time(0));
	for (int i = 0; i < 4; i++)
	{
		secret_number[i] = rand() % 7 + 0;
	}
	return *secret_number;
}

int getUserInput(int guess[]) // get the user's input
{
	for (int i = 0; i < 4; i++)
	{
		while (!(cin >> guess[i])) // check for integer numbers
		{
			cout << "\n                                  Not an integer, please try again: "; cin >> guess[i];
			cin.clear();
			cin.ignore(123, '\n');
		}
	}

	inRange(guess); // check for input numbers, if they are in range between 0 and 7

	return *guess;
}

int guessedNumbersAndPositions(int* secret_num, int* guess_num, bool secret_digit_used[], bool guess_digit_used[]) // count numbers and position
{
	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		if (secret_num[i] == guess_num[i])
		{
			count++;
			secret_digit_used[i] = true;
			guess_digit_used[i] = true;
		}
	}
	return count;
}

int guessedNumbers(int* secret_num, int* guess_num, bool secret_digit_used[], bool guess_digit_used[]) // count only the numbers without position
{
	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (secret_digit_used[i] || guess_digit_used[j])
				continue;

			if (secret_num[i] == guess_num[j])
			{
				count++;
				secret_digit_used[i] = true;
				guess_digit_used[j] = true;
			}
		}
	}
	return count;
}

int repetitiveNumbers(int arr[]) // check for repetitive nunbers
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			while (arr[i] == arr[j])
			{
				cout << "\n                                  Try without repetitive numbers: ";
				for (int i = 0; i < 4; i++)
				{
					cin >> arr[i];
				}
			}
		}
	}
	return *arr;
}

int inRange(int arr[]) // check for numbers in range between 0 and 7
{
	for (int i = 0; i < 4; i++)
	{
		while (arr[i] < 0 || arr[i] > 7)
		{
			cout << "\n                                      Not in range, try again: ";
			for (int i = 0; i < 4; i++)
			{
				cin >> arr[i];
			}
		}
	}
	return *arr;
}

int checkInt(int arr[]) // check for integer numbers
{
	for (int i = 0; i < 4; i++)
	{
		while (!(cin >> arr[i]))
		{
			cout << "\n                                  Not an integer, please try again: "; cin >> arr[i];
			cin.clear();
			cin.ignore(123, '\n');
		}
	}
	return *arr;
}

//*******************************DATA-LAYER***************************************//