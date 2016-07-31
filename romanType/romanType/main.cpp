#include <iostream>
#include <string>
#include "romanType.h"
using namespace std;

void displayMessage();
void getRoman(string & roman);

int main()
{
	string roman;

	displayMessage();
	getRoman(roman);

	romanType firstTry;
	firstTry.set(roman);
	firstTry.displayRoman();
	firstTry.convertRoman();
	firstTry.displayConverted();
	

	return 0;
}
//****************************
void displayMessage()
{
	cout << "Enter roman numeral: ";
}
void getRoman(string & roman)
{
	cin >> roman;
}

