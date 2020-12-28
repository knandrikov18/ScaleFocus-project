#include <iostream>

using namespace std;

#pragma once

//**************************DATA-LAYER***********************************//

string checkAcc(string username, string password);
int generateSecretNumber(int secret_number[]);
int getUserInput(int guess[]);
int guessedNumbersAndPositions(int* secret_num, int* guess_num, bool secret_digit_used[], bool guess_digit_used[]);
int guessedNumbers(int* secret_num, int* guess_num, bool secret_digit_used[], bool guess_digit_used[]);

//**************************DATA-LAYER***********************************//