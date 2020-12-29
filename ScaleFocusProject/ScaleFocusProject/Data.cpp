#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include "Data.h"
#include "Presentation.h"

using namespace std;

string checkAcc(string username, string password)
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

int generateSecretNumber(int secret_number[])
{
	srand(time(0));
	for (int i = 0; i < 4; i++)
	{
		secret_number[i] = rand() % 7 + 0;
	}
	return *secret_number;
}

int getUserInput(int guess[])
{
	for (int i = 0; i < 4; i++)
	{
		cin >> guess[i];
	}

	return *guess;
}

int guessedNumbersAndPositions(int* secret_num, int* guess_num, bool secret_digit_used[], bool guess_digit_used[])
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

int guessedNumbers(int* secret_num, int* guess_num, bool secret_digit_used[], bool guess_digit_used[])
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

int repetitiveNumbers(int arr[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j <= 4; j++)
		{
			if (arr[i] == arr[j])
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

int inRange(int arr[])
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