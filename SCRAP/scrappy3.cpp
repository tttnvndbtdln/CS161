#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 20;

void func(int & play, int & what);

int main()
{
	int play = 0, what = 0;
	
	func(play, what);
	
	return 0;
}

void func(int & play, int & what)
{
	play = 5;
	cout << "Play is " << play << endl;
}