#include <iostream>
using namespace std;
#include <string>
class romanType
{
public:
	void set(string _roman);
	void displayRoman();
	void displayConverted();
	void convertRoman();
private:
	string roman;
	int count = 0;
};