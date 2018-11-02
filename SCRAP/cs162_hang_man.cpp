//Phuong Pham

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//Prototypes
void welcome();
int get_secret(char secret_word[]);
void clear_screen();

const int SIZE = 21; //size of the secret word

int main()
{
    char secret[SIZE]; //holds the secret word
    int length;        // the length of the word

    welcome();

    length = get_secret(secret); //function call

    //testing
    cout << "The word is: " << secret << endl;

    return 0;
}

//Prompt and read in the word the other players will need to guess.
//It returns the number of characters in the words.
int get_secret(char word[])
{
     cout << "Please enter a secret word: ";
     cin.width(SIZE);
     cin >> word;
     cin.ignore(100,'\n');
     clear_screen();
     return strlen(word);
}

//Send out a bunch of lines to clear screen
void clear_screen()
{
    for (int i = 0; i < 100; ++i)
        cout << endl;
}

//Explain the purpose of the program and how to play the game
void welcome()
{
     cout << "Welcome to the hangman program,\n"
          << "After a secret word is provided,\n"
          << "the player will select characters\n"
          << "until the word is guessed....";

     cout << endl < endl;
}
