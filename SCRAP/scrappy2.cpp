#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 50;

const int SIZE2 = 20;

int main()
{
	char array[SIZE];
	char or_word[SIZE2], or_word2[SIZE2], or_word3[SIZE2];
	int word_counter = 0, no_of_words = 0;
	int i = 0, j = 0;
	
	cout << "Enter array: ";
	cin.get(array,SIZE,'\n');
	cin.ignore(100,'\n');
	
	for (int k = 0; k < SIZE; ++k)
	{
		if (array[k] == ' ')
			++word_counter;
	}
	
	no_of_words = word_counter + 1;
	
	if (no_of_words >= 1)
	{
		for (i = 0; array[i] != ' '; ++i)
			or_word[i] = array[i];
		cout << "First word: " << or_word << endl;
		++i;
	}
	
	if (no_of_words >= 2)
	{
		for (i; array[i] != ' '; ++i)
		{
			or_word2[j] = array[i];
			++j;
		}
		j = 0;
		++i;
		cout << "Second word: " << or_word2 << endl;
	}	
		
	if (no_of_words >=3)
	{
		for (i; array[i] != ' '; ++i)
		{
			or_word3[j] = array[i];
			++j;
		}
		cout << "Third word: " << or_word3 << endl;
	}
	
	
	return 0;
}