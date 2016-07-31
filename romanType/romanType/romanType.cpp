#include "romanType.h"

void romanType::set(string _roman)
{
	roman = _roman;
}
void romanType::displayRoman()
{
	cout << roman << endl;
}
void romanType::displayConverted()
{
	cout << count << endl;
}
void romanType::convertRoman()
{
	//loop through the list
	for (int i = 0; i < roman.size(); i++)
	{
		switch (roman[i])
		{
		case 'M':
			count += 1000;
			break;
		case 'D':
			count += 500;
			break;
		case 'C':
			count += 100;
			break;
		case 'L':
			count += 50;
			break;
		case 'X':
			count += 10;
			break;
		case 'V':
			count += 5;
			break;
		case 'I':
			count += 1;
			break;
		default:
			cout << "ERROR\n";
		}
	}
}