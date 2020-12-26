#include <iostream>
#include <fstream>
#include <string>

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