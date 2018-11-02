#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10;
const int SENTINEL = -1;

int main()
{
	int array[SIZE];
	int large = 0;
	
	for (int i = 0; array[i] == SENTINEL;)
	{
		cout << "Enter a number: ";
		cin >> array[i];
		cin.ignore(100,'\n');
	}
		
	cout << array << endl << endl;
	
	for (int i = 0; i < SIZE; ++i)
	{
		if (large < array[i])
			large = array[i];
	}
	
	cout << "Largest number is: " << large << endl;
	
	return 0;
}
