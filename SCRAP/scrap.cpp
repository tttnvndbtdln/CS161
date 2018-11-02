#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cmath>

using namespace std;

const int SIZE = 10;

int main()
{
  int array[SIZE];
  int input;
  int large = 0;
  int i = 0;

  cout << "Please enter a number (Enter 0 if you are finished): ";
  cin >> input;

  while (input != 0)
  {
    array[i] = input;
    cout << "Please enter a number (Enter 0 if you are finished: ";
    cin >> input;
    ++i;
  }

  cout << "Your numbers are: " << array[SIZE] << endl << endl;

  return 0;
}
