//Phuong Pham
//January 31, 2016
//CS 162
//Assignment 2

//In the original algorithm, this is a program that simulates a speed reading game to play between two human players. Each
//player starts with 10 points. Player one will be prompted to enter a question, at which point player two will have to reenter
//the question, as accurately as possible. Player two will only have a certain amount of time to look at the question entered
//by player one. However, he or she can opt to look at the question again for a longer period of time, but each time he or she
//does so will result in a deduction of one point from the total points of 10. Player two can do this for up to 3 times, after
//which, they will have to enter the question and gain one point for each word that matches up with the word in the original
//question entered by player one, not to exceed the original 10 points. Player two can also enter an answer if desire.
//Afterward, the players switch turn and the game continues until either player has 0 points (that player has lost).

//PLEASE READ as there are modifications made in this program that alter the guideline and the algorithm, which were made in an
//attempt to make the game a more fun and enjoyable experience. It is believed that the program still retained its core
//principles established by the assignment.

//Firstly, instead of both players starting with 10 points, this program will start both players with 5 points. It is discovered
//that if both players start with 10 points and that is the maximum number of points they can get, they have no incentives
//whatsover to type in the first question. They would not look at the question again because doing so will cost them points and
//they may not be able to recover those points. As a result, it was deemed better that both players start with 5 points. This
//will incentivize the players to answer any question, even the first one. Furthermore, since the maximum score is 10 points and
//the minimum score is 1 point (for a player to remain in the game), it makes more sense that a question's maximum number of
//words is 9. Any extra words will not count towards their total anyway. In other words, the extra effort is not rewarded, but
//will be punish by having a higher chance that the player needs to look at the long question again. Ergo, it is believe a maximum
//number of 9 words is a reasonable rule to have. From this, it was found that most phrases of 9 words do not take a lot of time
//for a player to memorize. Therefore, we have limit that a player can only see the question again for a maximum of two (2) times
//before they have to repeat it. However, the price for looking at the question again is three (3) points!

//An example run of this game: Suppose player 1 entered "Is Phuong Pham the most awesome person ever?" Player 2 decided she would
//like to look at the question again. She loses 3 points. Her total is now 2 (down from original 5). Player 2, however, has an
//was able to entered the question again correctly, word by word. Her score total now would be 10 points (8 words question).

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 130;

//Functions Prototypes.
void welcome(char instruction);
void question_input(char question[]);
void clear_screen();
void ask_if_player_ready(char start);
void delay_loop_first();
void delay_loop_second();
void delay_loop_third();
void display_question(char question[], char start, int player2_score);
void reenter_question(char question2[]);
bool compare_questions(char question[], char question2[], int player2_score);

int main()
{
	//Variables initialization.
	char instruction, start; //variables to check/echo for instructions and start the game.
	int player1_score, player2_score; //variables to hold players' scores.
	char question[SIZE]; //holds the question.
	char question2[SIZE]; //holds the question player 2 enter as he/she remembered.

	player1_score = 5;
	player2_score = 5;

	//welcome(instruction);
	question_input(question);
	//ask_if_player_ready(start);
	display_question(question, start, player2_score);
	reenter_question(question2);
	compare_questions(question,question2, player2_score);

    return 0;
}

//Compare the original question to the one entered by the other player.
bool compare_questions(char question[], char question2[], int player2_score)
{
	int counter = 0, counter2 = 0, word_match_counter = 0;
	int space = 0, i = 0, j = 0;

	cout << "\nThe original question was: " << question << endl;
	cout << "\nThe question you put in was: " << question2 << endl;

	for (int i = 0; i < SIZE; ++i)
	{
		if (question[i] == question2[j])
		{
			++counter;
		}
		++j;
	}

	for (int i = 0; question[i] != ' '; ++i) 
	{
		if (question[i+1] == question2[j+1])
			++counter;
		++counter2;
	}

	cout << counter << " " << counter2 << endl << endl;

	if (counter == counter2 + 1)
		++word_match_counter;

	counter = 0;
	counter2 = 0;


	/*
	for (int i = counter; i < SIZE; ++i)
	{
		question[i] = question[i+1];
		question2[i] = question2[i+1];
	}




	for (int i = 0; question[i] != ' '; i++)
	{
		if (question[i] == question2[i])
			++counter;
		++counter2;
	}

	cout << counter << " " << counter2 << endl << endl;

	if (counter == counter2)
		++word_match_counter;
	*/



	/*
	for (int i = 0; i < SIZE; ++i)
	{
		if (question[i] == ' ')
			space = i+1;
	}

	for (int i = 0; question[i+space] != ' '; ++i)
	{
		if (question[i+space] == question2[i])
			++counter;
		++counter2;
	}

	cout << counter << " " << counter2;

	if (counter == counter2)
		++word_match_counter;

	counter = 0;
	counter2 = 0;
	*/

	/*

	for (int i = space; i < SIZE; ++i)
	{
		if (question2[i] == ' ')
			space = space + i;
	}

	for (int i = 0; question2[)
	*/



	player2_score = player2_score + word_match_counter;

	if (player2_score > 10)
		player2_score = 10;

	cout << "\nYour score is now " << player2_score << endl;
}

//Prompt player to reenter the question as best as he/she can remember it.
void reenter_question(char question2[])
{
	cout << "\nPlease enter the question as best as you can remember it: ";
	cin.get(question2,SIZE,'\n');
	cin.ignore(100,'\n');
}

//Display question.
void display_question(char question[], char start, int player2_score)
{
	cout << "The question is: " << question << endl;
	delay_loop_first();
	clear_screen();

	cout << "Would you like to see the question again? Three (3) points will be deducted from your total (Y/N): ";
	cin >> start;
	cin.ignore(100,'\n');

	if (toupper(start) == 'Y')
	{
		player2_score = player2_score - 3;
		cout << question << endl;
		delay_loop_second();
		clear_screen();

		cout << "Your score is now " << player2_score << endl;
	}
}

//Prompt the user if he/she is ready to start repeating the question entered by the other player.
void ask_if_player_ready(char start)
{
	do
	{
		cout << "Player 2, are you ready to start (Y/N)? ";
	    cin >> start;
	    cin.ignore(100,'\n');
	} while (toupper(start) != 'Y');
}

//Delay the time (long) the question appears on the screen (second time player looks at question).
void delay_loop_second()
{
	for (int i = 0; i < 75000; ++i)
	{
		for (int j = 0; j < 75000; ++j)
		{}
	}
}

//Delay the time (short) the question appears on the screen (first time player looks at question).
void delay_loop_first()
{
	for (int i = 0; i < 20000; ++i)
	{
		for (int j = 0; j < 20000; ++j)
		{}
	}
}

//Prompt player to input the question.
void question_input(char question[])
{
	cout << "\n\nPlayer 1, please enter your question: ";
	cin.get(question, SIZE, '\n');
	cin.ignore(100,'\n');
	clear_screen();

	while (strlen(question) > SIZE)
	{
		cout << "Your question is too long. Please enter a shorter question: ";
		cin.get(question,SIZE,'\n');
		cin.ignore(100,'\n');
		clear_screen();
	}
}

//Clear the screen.
void clear_screen()
{
	for (int i = 0; i < 100; ++i)
		cout << endl;
}

//Welcome the users to the game and how to play the game.
void welcome(char instruction)
{
    cout << "\n\tWELCOME TO FLASH READ!\n\n" << "Would you like to learn how to play the game? (Y/N): ";
    cin >> instruction;
    cin.ignore(100,'\n');

	if (toupper(instruction) == 'Y')
        {
		cout << "In FLASH READ, two players start the game with 10 points. Player one will enter a question. Player two will then be allow to look at the"
			 << "question for a period of time and then ask to enter the question as accurately as possible. Player two can opt to look at the question"
			 << "again but three (3) points will be deducted from his or her total. Player two will gain one point for every word entered that match up"
			 << "with the original question, but not to exceed the original 10 points. Player two may enter the answer to the question if desired."
			 << "Afterward, the players switch turn, at which point player 2 will now enter the question that player 1 needs to reenter, as accurate as"
			 << "he or she can remember it.";
	}
}
