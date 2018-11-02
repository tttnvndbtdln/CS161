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
//before they have to repeat it. However, the price for looking at the question again is three (3) points! Lastly, from the
//program description, it seems that a player cannot really lose if he/she does not want to. That is, the only way for the player
//to lose point is to see the question again. If a player has 1 point left but decides not to see the question again and simply
//enter nonsense, technically, that player gains no point, but he or she can keep doing this (a real life infinite loop!) until
//the end of time. This program solves this issue by decrementing a player's point by two (2) points if he/she gained no point
//from entering the question.

//An example run of this game: Suppose player 1 entered "Is Phuong Pham the most awesome person ever?" Player 2 decided she would
//like to look at the question again. She loses 3 points. Her total is now 2 (down from original 5). Player 2, however, has an
//was able to entered the question again correctly, word by word. Her score total now would be 10 points (8 words question).

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 15;

//Functions Prototypes.
void welcome(char instruction);
void question_input(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char enter_question, int player);
void clear_screen();
void ask_if_player_ready(char start);
void ask_if_player_ready_1(char start);
void delay_loop_first();
void delay_loop_second();
void display_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char start, int & player2_score);
void display_question_1(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char start, int & player1_score);
void reenter_question(char word[], char word2[], char word3[], char word4[], char word5[], char reenter_again);
void compare_questions(char [], char [], char [], char [], char [], char [], char [], char [], char [], char [], int & player2_score);
void compare_questions_1(char [], char [], char [], char [], char [], char [], char [], char [], char [], char [], int & player1_score);
void declare_winner(int player1_score, int player2_score);
bool again(char play_again);

int main()
{
	//Variables initialization.
	char instruction, start, enter_question, reenter_again; //variables to check/echo for instructions and start the game.
	int player1_score, player2_score; //variables to hold players' scores.
	char orig_word[SIZE], orig_word2[SIZE], orig_word3[SIZE], orig_word4[SIZE], orig_word5[SIZE];
	char word[SIZE], word2[SIZE], word3[SIZE], word4[SIZE], word5[SIZE];
	int player;
	char play_again;
	
	player1_score = 5;
	player2_score = 5;

	do
	{
		welcome(instruction);
	
		do
		{
			cout << "\nIt is time to switch players!" << endl << endl;
			
			player = 1; //Player 1 provides the question.
			question_input(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, enter_question, player);
			ask_if_player_ready(start);
			display_question(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, start, player2_score);
			reenter_question(word, word2, word3, word4, word5, reenter_again);
			compare_questions(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, word, word2, word3, word4, word5, player2_score);
		
			if (player2_score > 0)
			{
				cout << "\nIt is time to switch players!" << endl << endl;
		
				player = 2; //Player 2 provides the question.
				question_input(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, enter_question, player);
				ask_if_player_ready_1(start);
				display_question_1(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, start, player1_score);
				reenter_question(word, word2, word3, word4, word5, reenter_again);
				compare_questions_1(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, word, word2, word3, word4, word5, player1_score);
			}
		
		} while (player1_score > 0 && player2_score > 0);
		
		declare_winner(player1_score, player2_score);
	
	} while (again(play_again));
	
    return 0;
}

bool again(char play_again)
{
	cout << "\nWould you like to play again? (Y/N): ";
	cin >> play_again;
	
	if (toupper(play_again) == 'Y')
		return true;
	
	return false;
}

void declare_winner(int player1_score, int player2_score)
{
	if (player1_score < 1)
		cout << "\n\tPlayer 1 has lost! \n\n\tPLAYER 2 HAS WON!\n\n\tGAME OVER!";

	if (player2_score < 1)
		cout << "\n\tPlayer 2 has lost! \n\n\tPLAYER 1 HAS WON!\n\n\tGAME OVER!";
}

//Compare the original question to the one entered by the other player.
void compare_questions_1(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char word[], char word2[], char word3[], char word4[], char word5[], int & player1_score)
{
	cout << "The original question was: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 << " " << orig_word5 << "?" << endl;
	cout << "The question you entered was: " << word << " " << word2 << " " << word3 << " " << word4 << " " << word5 << "?" << endl;
	
	int nothing_right = player1_score;
	
	if (strcmp(orig_word,word) == 0 || strcmp(orig_word,word2) == 0 || strcmp(orig_word,word3) == 0 || strcmp(orig_word,word4) == 0 || strcmp(orig_word,word5) == 0)
		++player1_score;
	
	if (strcmp(orig_word2,word) == 0 || strcmp(orig_word2,word2) == 0 || strcmp(orig_word2,word3) == 0 || strcmp(orig_word2,word4) == 0 || strcmp(orig_word2,word5) == 0)
		++player1_score;
	
	if (strcmp(orig_word3,word) == 0 || strcmp(orig_word3,word2) == 0 || strcmp(orig_word3,word3) == 0 || strcmp(orig_word3,word4) == 0 || strcmp(orig_word3,word5) == 0)
		++player1_score;
	
	if (strcmp(orig_word4,word) == 0 || strcmp(orig_word4,word2) == 0 || strcmp(orig_word4,word3) == 0 || strcmp(orig_word4,word4) == 0 || strcmp(orig_word4,word5) == 0)
		++player1_score;
	
	if (strcmp(orig_word5,word) == 0 || strcmp(orig_word5,word2) == 0 || strcmp(orig_word5,word3) == 0 || strcmp(orig_word5,word4) == 0 || strcmp(orig_word5,word5) == 0)
		++player1_score;	
	
	if (player1_score > 10)
		player1_score = 10;
	
	if (nothing_right == player1_score && nothing_right < 10)
		player1_score-=2;

	cout << "\nPlayer 1, your score is now " << player1_score << endl;
}

//Compare the original question to the one entered by the other player.
void compare_questions(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char word[], char word2[], char word3[], char word4[], char word5[], int & player2_score)
{
	cout << "The original question was: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 << " " << orig_word5 << "?" << endl;
	cout << "The question you entered was: " << word << " " << word2 << " " << word3 << " " << word4 << " " << word5 << "?" << endl;
	
	int nothing_right = player2_score;
	
	if (strcmp(orig_word,word) == 0 || strcmp(orig_word,word2) == 0 || strcmp(orig_word,word3) == 0 || strcmp(orig_word,word4) == 0 || strcmp(orig_word,word5) == 0)
		++player2_score;
	
	if (strcmp(orig_word2,word) == 0 || strcmp(orig_word2,word2) == 0 || strcmp(orig_word2,word3) == 0 || strcmp(orig_word2,word4) == 0 || strcmp(orig_word2,word5) == 0)
		++player2_score;
	
	if (strcmp(orig_word3,word) == 0 || strcmp(orig_word3,word2) == 0 || strcmp(orig_word3,word3) == 0 || strcmp(orig_word3,word4) == 0 || strcmp(orig_word3,word5) == 0)
		++player2_score;
	
	if (strcmp(orig_word4,word) == 0 || strcmp(orig_word4,word2) == 0 || strcmp(orig_word4,word3) == 0 || strcmp(orig_word4,word4) == 0 || strcmp(orig_word4,word5) == 0)
		++player2_score;
	
	if (strcmp(orig_word5,word) == 0 || strcmp(orig_word5,word2) == 0 || strcmp(orig_word5,word3) == 0 || strcmp(orig_word5,word4) == 0 || strcmp(orig_word5,word5) == 0)
		++player2_score;	
	
	if (player2_score > 10)
		player2_score = 10;
	
	if (nothing_right == player2_score && nothing_right < 10)
		player2_score-=2;

	cout << "\nPlayer 2, your score is now " << player2_score << endl;
}

//Prompt player to reenter the question as best as he/she can remember it.
void reenter_question(char word[], char word2[], char word3[], char word4[], char word5[], char reenter_again)
{
	do
	{
		cout << "\nPlease enter the question as best as you can remember it: ";
		cin >> word >> word2 >> word3 >> word4 >> word5;
		cin.ignore(100,'\n');
		
		cout << "The question you have entered is " << word << " " << word2 << " " << word3 << " " << word4 << " " << word5 << "?" << endl;
		cout << "Is this correct (Y/N): ";
		cin >> reenter_again;
	} while (toupper(reenter_again) == 'N');
}


//Display question.
void display_question_1(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char start, int & player1_score)
{
	cout << "The question is: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 << " " << orig_word5 << endl;
	delay_loop_first();
	clear_screen();

	if (player1_score > 3)
	{
		cout << "Would you like to see the question again? Three (3) points will be deducted from your total (Y/N): ";
		cin >> start;
		cin.ignore(100,'\n');

		if (toupper(start) == 'Y')
		{
			player1_score = player1_score - 3;
			cout << "The question is: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 << " " << orig_word5 << endl;
			delay_loop_second();
			clear_screen();

			cout << "Player 1, your score is now " << player1_score << endl;
		}
	}
}


//Display question.
void display_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char start, int & player2_score)
{
	cout << "The question is: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 << " " << orig_word5 << endl;
	delay_loop_first();
	clear_screen();

	if (player2_score > 3)
	{
		cout << "Would you like to see the question again? Three (3) points will be deducted from your total (Y/N): ";
		cin >> start;
		cin.ignore(100,'\n');

		if (toupper(start) == 'Y')
		{
			player2_score = player2_score - 3;
			cout << "The question is: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 << " " << orig_word5 << endl;
			delay_loop_second();
			clear_screen();

			cout << "Player 2, your score is now " << player2_score << endl;
		}
	}
}

//Prompt the user if he/she is ready to start repeating the question entered by the other player.
void ask_if_player_ready_1(char start)
{
	do
	{
		cout << "Player 1, are you ready to start (Y/N)? ";
	    cin >> start;
	    cin.ignore(100,'\n');
	} while (toupper(start) != 'Y');
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

//Prompt player to input the question.
void question_input(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char enter_question, int player)
{
	do
	{
		cout << "\n\nPlayer " << player << ", please enter your question (5 words!), without the question mark: ";
		cin >> orig_word >> orig_word2 >> orig_word3 >> orig_word4 >> orig_word5;
		cin.ignore(100,'\n');
		
		cout << "The question you have entered is: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 
			 << " " << orig_word5 << "?" << endl;
		cout << "Is this correct? (Y/N): ";
		cin >> enter_question;
	} while (toupper(enter_question) == 'N');
	
	clear_screen();
}

//Clear the screen.
void clear_screen()
{
	for (int i = 0; i < 100; ++i)
		cout << endl;
}

//Delay the time (long) the question appears on the screen (second time player looks at question).
void delay_loop_second()
{
	for (int i = 0; i < 20000; ++i)
	{
		for (int j = 0; j < 20000; ++j)
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
