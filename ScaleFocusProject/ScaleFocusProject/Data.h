#include <iostream>

using namespace std;

#pragma once

//**************************DATA-LAYER***********************************//

string checkAcc(string username, string password);
int generateSecretRepetitiveNumber(int secret_number[]);
int generateSecretRepetitiveNumber(int secret_number[]);
int getUserInput(int guess[]);
int guessedNumbersAndPositions(int* secret_num, int* guess_num, bool secret_digit_used[], bool guess_digit_used[]);
int guessedNumbers(int* secret_num, int* guess_num, bool secret_digit_used[], bool guess_digit_used[]);
int repetitiveNumbers(int arr[]);
int inRange(int arr[]);
int checkInt(int arr[]);

//**************************DATA-LAYER***********************************//