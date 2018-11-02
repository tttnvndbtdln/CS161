#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

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
//attempt to make the game a more fun and enjoyable experience.

//Firstly, instead of both players starting with 10 points, this program will start both players with 5 points. It is discovered
//that if both players start with 10 points and that is the maximum number of points they can get, they have no incentives
//whatsover to type in the first question. They would not look at the question again because doing so will cost them points and
//they may not be able to recover those points. As a result, it was deemed better that both players start with 5 points. This
//will incentivize the players to answer any question, even the first one. Furthermore, since the maximum score is 10 points and
//the minimum score is 1 point (for a player to remain in the game), it makes more sense that a question's maximum number of
//words is 9. Any extra words will not count towards their total anyway. In other words, the extra effort is not rewarded, but
//will be punish by having a higher chance that the player needs to look at the long question again. Ergo, it is believe a maximum
//number of 9 words is a reasonable rule to have.

//From this, it was found that most phrases of 9 words do not take a lot of time for a player to memorize. Therefore, we have limit
//that a player can only see the question again for a maximum of two (2) times before they have to repeat it. However, the price
//for looking at the question again is three (3) points! Furthermore, one of the requirements mentioned in the assignment
//guideline is that the maximum number of characters for the question should be 130. From this, each word should have approximately
//15 characters. It also makes more sense as to keep things more balance as player may have a harder trying to memorize super long
//words.

//Lastly, from the program description, it seems that a player cannot really lose if he/she does not want to. That is, the only way
//for the player to lose point is to see the question again. If a player has 1 point left but decides not to see the question again
//and simply enter nonsense, technically, that player gains no point, but he or she can keep doing this (a real life infinite loop!)
//until the end of time. This program solves this issue by decrementing a player's point by two (2) points if he/she gained no point
//from entering the question.

//An example run of this game: Suppose player 1 entered "What is the capital of Oregon?" Player 2 decided she would like to look at
//the question again. She loses 3 points. Her total is now 2 (down from original 5). Player 2, however, has an was able to entered the
//question again correctly, word by word. Her score total now would be 8 points (6 words question)!

//In addition, this program will compare the questions entered between two players by splitting the question into words and then use
//strcmp to compare the words if they are a match.

//This constant will be used for the size of all arrays of words.
const int SIZE = 15;

//Functions Prototypes.
void welcome(char instruction);
void question_input(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[],
	 char orig_word7[], char orig_word8[], char orig_word9[], int player, int & no_of_words);

void one_word_question(char orig_word[], int player);
void two_word_question(char orig_word[], char orig_word2[], int player);
void three_word_question(char orig_word[], char orig_word2[], char orig_word3[], int player);
void four_word_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], int player);
void five_word_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], int player);
void six_word_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[], int player);
void seven_word_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[],
	char orig_word7[], int player);
void eight_word_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[],
	char orig_word7[], char orig_word8[], int player);
void nine_word_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[],
	char orig_word7[], char orig_word8[], char orig_word9[], int player);

void clear_screen();
void ask_if_player_ready(char start);
void ask_if_player_ready_1(char start);

void delay_loop_first();
void delay_loop_second();

void display_question_command_1(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[],
	char orig_word7[], char orig_word8[], char orig_word9[], char start, int & player1_score, int & no_of_words);
void display_question_command(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[],
	char orig_word7[], char orig_word8[], char orig_word9[], char start, int & player2_score, int & no_of_words);
void display_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[],
	char orig_word7[], char orig_word8[], char orig_word9[], int & no_of_words);

void reenter_question(char word[], char word2[], char word3[], char word4[], char word5[], char word6[], char word7[], char word8[], char word9[], int & no_of_words);

void compare_questions(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[], char orig_word7[], char orig_word8[], char orig_word9[],
	char word[], char word2[], char word3[], char word4[], char word5[], char word6[], char word7[], char word8[], char word9[], int & no_of_words, int & player2_score, char answer[]);
void compare_questions_1(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[], char orig_word7[], char orig_word8[], char orig_word9[],
	char word[], char word2[], char word3[], char word4[], char word5[], char word6[], char word7[], char word8[], char word9[], int & no_of_words, int & player1_score, char answer[]);

void declare_winner(int player1_score, int player2_score);
bool again(char play_again);

int main()
{
	//Variables initialization.
	char instruction, start, reenter_again; //variables to check/echo for instructions and start the game.
	int player1_score, player2_score; //variables to hold players' scores.
	char orig_word[SIZE] = " ", orig_word2[SIZE] = " ", orig_word3[SIZE] = " ", orig_word4[SIZE] = " ", orig_word5[SIZE] = " ", 
		orig_word6[SIZE] = " ", orig_word7[SIZE] = " ", orig_word8[SIZE] = " ", orig_word9[SIZE] = " "; //arrays to hold the words of the original question entered by the first player, hence orig_word.
	char word[SIZE] = "0", word2[SIZE] = "0", word3[SIZE] = "0", word4[SIZE] = "0", word5[SIZE] = "0", word6[SIZE] = "0", word7[SIZE] = "0",
		word8[SIZE] = "0", word9[SIZE] = "0"; //arrays to hold the words of the question entered by the second player.
	int player, no_of_words = 0; //variables to describes the turn of which player and the number of words in a question.
	char play_again, answer[SIZE]; //variables to check if players want to play again and the array to hold the answer (has no impact in the game).

	do
	{
		//Initialize the players' scores to 5 each.
		player1_score = 5;
		player2_score = 5;

		welcome(instruction);

		do
		{
			cout << "\n\nPlayer 1 will now give the question!" << endl;
			player = 1; //Player 1 provides the question.
			question_input(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, player, no_of_words);
			ask_if_player_ready(start);
			display_question_command(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, start, player2_score, no_of_words);
			reenter_question(word, word2, word3, word4, word5, word6, word7, word8, word9, no_of_words);
			compare_questions(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, word, word2, word3, word4, word5, word6, word7, word8, word9, no_of_words, player2_score, answer);

			if (player2_score > 0)
			{
				cout << "\nIt is time for Player 2 to give the question!" << endl;
				player = 2; //Player 2 provides the question.
				question_input(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, player, no_of_words);
				ask_if_player_ready_1(start);
				display_question_command_1(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, start, player1_score, no_of_words);
				reenter_question(word, word2, word3, word4, word5, word6, word7, word8, word9, no_of_words);
				compare_questions_1(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, word, word2, word3, word4, word5, word6, word7, word8, word9, no_of_words, player1_score, answer);
			}

		} while (player1_score > 0 && player2_score > 0); //Continue loop until either player's score is 0. 

		declare_winner(player1_score, player2_score);

	} while (again(play_again)); //Continue the main loop until players select to quit game.

    return 0;
}

//Function to check if the players would like to play the game again.
bool again(char play_again)
{
	cout << "\nWould you like to play again? (Y/N): ";
	cin >> play_again;

	if (toupper(play_again) == 'Y')
		return true;

	return false;
}

//Function to declare the winner when either player's score falls below 1 (player's score may fall below 0 in case they lose 2 points from entering nonsense and had 1 point left).
void declare_winner(int player1_score, int player2_score)
{
	if (player1_score < 1)
		cout << "\n\tPlayer 1 has lost! \n\n\tPLAYER 2 HAS WON!\n\n\tGAME OVER!";

	if (player2_score < 1)
		cout << "\n\tPlayer 2 has lost! \n\n\tPLAYER 1 HAS WON!\n\n\tGAME OVER!";
}

//Compare the original question entered by player 2 to the one entered by player 1. Use strcmp to compare each word from each question to each other.
void compare_questions_1(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[], char orig_word7[], char orig_word8[], char orig_word9[],
	char word[], char word2[], char word3[], char word4[], char word5[], char word6[], char word7[], char word8[], char word9[], int & no_of_words, int & player1_score, char answer[])
{
	display_question(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, no_of_words); //This is calling the original question back so player 1 can see it. See function below.

	//Initialize variable to later check if player 1 entered anything correct at all.
	int nothing_right = player1_score;

	if (strcmp(orig_word,word) == 0 || strcmp(orig_word,word2) == 0 || strcmp(orig_word,word3) == 0 || strcmp(orig_word,word4) == 0 || strcmp(orig_word,word5) == 0
		|| strcmp(orig_word,word6) == 0 || strcmp(orig_word,word7) == 0 || strcmp(orig_word,word8) == 0 || strcmp(orig_word,word9) == 0)
		++player1_score;

	if (strcmp(orig_word2,word) == 0 || strcmp(orig_word2,word2) == 0 || strcmp(orig_word2,word3) == 0 || strcmp(orig_word2,word4) == 0 || strcmp(orig_word2,word5) == 0
		|| strcmp(orig_word2,word6) == 0 || strcmp(orig_word2,word7) == 0 || strcmp(orig_word2,word8) == 0 || strcmp(orig_word2,word9) == 0)
		++player1_score;

	if (strcmp(orig_word3,word) == 0 || strcmp(orig_word3,word2) == 0 || strcmp(orig_word3,word3) == 0 || strcmp(orig_word3,word4) == 0 || strcmp(orig_word3,word5) == 0
		|| strcmp(orig_word3,word6) == 0 || strcmp(orig_word3,word7) == 0 || strcmp(orig_word3,word8) == 0 || strcmp(orig_word3,word9) == 0)
		++player1_score;

	if (strcmp(orig_word4,word) == 0 || strcmp(orig_word4,word2) == 0 || strcmp(orig_word4,word3) == 0 || strcmp(orig_word4,word4) == 0 || strcmp(orig_word4,word5) == 0
		|| strcmp(orig_word4,word6) == 0 || strcmp(orig_word4,word7) == 0 || strcmp(orig_word4,word8) == 0 || strcmp(orig_word4,word9) == 0)
		++player1_score;

	if (strcmp(orig_word5,word) == 0 || strcmp(orig_word5,word2) == 0 || strcmp(orig_word5,word3) == 0 || strcmp(orig_word5,word4) == 0 || strcmp(orig_word5,word5) == 0
		|| strcmp(orig_word5,word6) == 0 || strcmp(orig_word5,word7) == 0 || strcmp(orig_word5,word8) == 0 || strcmp(orig_word5,word9) == 0)
		++player1_score;

	if (strcmp(orig_word6,word) == 0 || strcmp(orig_word6,word2) == 0 || strcmp(orig_word6,word3) == 0 || strcmp(orig_word6,word4) == 0 || strcmp(orig_word6,word5) == 0
		|| strcmp(orig_word6,word6) == 0 || strcmp(orig_word6,word7) == 0 || strcmp(orig_word6,word8) == 0 || strcmp(orig_word6,word9) == 0)
		++player1_score;

	if (strcmp(orig_word7,word) == 0 || strcmp(orig_word7,word2) == 0 || strcmp(orig_word7,word3) == 0 || strcmp(orig_word7,word4) == 0 || strcmp(orig_word7,word5) == 0
		|| strcmp(orig_word7,word6) == 0 || strcmp(orig_word7,word7) == 0 || strcmp(orig_word7,word8) == 0 || strcmp(orig_word7,word9) == 0)
		++player1_score;

	if (strcmp(orig_word8,word) == 0 || strcmp(orig_word8,word2) == 0 || strcmp(orig_word8,word3) == 0 || strcmp(orig_word8,word4) == 0 || strcmp(orig_word8,word5) == 0
		|| strcmp(orig_word8,word6) == 0 || strcmp(orig_word8,word7) == 0 || strcmp(orig_word8,word8) == 0 || strcmp(orig_word8,word9) == 0)
		++player1_score;

	if (strcmp(orig_word9,word) == 0 || strcmp(orig_word9,word2) == 0 || strcmp(orig_word9,word3) == 0 || strcmp(orig_word9,word4) == 0 || strcmp(orig_word9,word5) == 0
		|| strcmp(orig_word9,word6) == 0 || strcmp(orig_word9,word7) == 0 || strcmp(orig_word9,word8) == 0 || strcmp(orig_word9,word9) == 0)
		++player1_score;

	//This brings the player's score back to 10 (the maximum) in case it increases more than that (e.g. player gains 5 points with an original score of 7).
	if (player1_score > 10)
		player1_score = 10;

	//The variable was initially equal to the player's score. If there was no change, the player loses 2 points.
	if (nothing_right == player1_score && nothing_right < 10) //The second operand is in case the player started with 10 points and gained no point in the process.
		player1_score-=2;

	cout << "\nPlayer 1, your score is now " << player1_score << endl;

	cout << "Enter an answer if you'd like: ";
	cin >> answer;
}


//Compare the original question entered by player 1 to the one entered by player 2. NOTE: This function is similar to the previous one, but it manipulates player 2's score instead.
void compare_questions(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[], char orig_word7[], char orig_word8[], char orig_word9[],
	char word[], char word2[], char word3[], char word4[], char word5[], char word6[], char word7[], char word8[], char word9[], int & no_of_words, int & player2_score, char answer[])
{
	display_question(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, no_of_words);

	int nothing_right = player2_score;

	if (strcmp(orig_word,word) == 0 || strcmp(orig_word,word2) == 0 || strcmp(orig_word,word3) == 0 || strcmp(orig_word,word4) == 0 || strcmp(orig_word,word5) == 0
		|| strcmp(orig_word,word6) == 0 || strcmp(orig_word,word7) == 0 || strcmp(orig_word,word8) == 0 || strcmp(orig_word,word9) == 0)
		++player2_score;

	if (strcmp(orig_word2,word) == 0 || strcmp(orig_word2,word2) == 0 || strcmp(orig_word2,word3) == 0 || strcmp(orig_word2,word4) == 0 || strcmp(orig_word2,word5) == 0
		|| strcmp(orig_word2,word6) == 0 || strcmp(orig_word2,word7) == 0 || strcmp(orig_word2,word8) == 0 || strcmp(orig_word2,word9) == 0)
		++player2_score;

	if (strcmp(orig_word3,word) == 0 || strcmp(orig_word3,word2) == 0 || strcmp(orig_word3,word3) == 0 || strcmp(orig_word3,word4) == 0 || strcmp(orig_word3,word5) == 0
		|| strcmp(orig_word3,word6) == 0 || strcmp(orig_word3,word7) == 0 || strcmp(orig_word3,word8) == 0 || strcmp(orig_word3,word9) == 0)
		++player2_score;

	if (strcmp(orig_word4,word) == 0 || strcmp(orig_word4,word2) == 0 || strcmp(orig_word4,word3) == 0 || strcmp(orig_word4,word4) == 0 || strcmp(orig_word4,word5) == 0
		|| strcmp(orig_word4,word6) == 0 || strcmp(orig_word4,word7) == 0 || strcmp(orig_word4,word8) == 0 || strcmp(orig_word4,word9) == 0)
		++player2_score;

	if (strcmp(orig_word5,word) == 0 || strcmp(orig_word5,word2) == 0 || strcmp(orig_word5,word3) == 0 || strcmp(orig_word5,word4) == 0 || strcmp(orig_word5,word5) == 0
		|| strcmp(orig_word5,word6) == 0 || strcmp(orig_word5,word7) == 0 || strcmp(orig_word5,word8) == 0 || strcmp(orig_word5,word9) == 0)
		++player2_score;

	if (strcmp(orig_word6,word) == 0 || strcmp(orig_word6,word2) == 0 || strcmp(orig_word6,word3) == 0 || strcmp(orig_word6,word4) == 0 || strcmp(orig_word6,word5) == 0
		|| strcmp(orig_word6,word6) == 0 || strcmp(orig_word6,word7) == 0 || strcmp(orig_word6,word8) == 0 || strcmp(orig_word6,word9) == 0)
		++player2_score;

	if (strcmp(orig_word7,word) == 0 || strcmp(orig_word7,word2) == 0 || strcmp(orig_word7,word3) == 0 || strcmp(orig_word7,word4) == 0 || strcmp(orig_word7,word5) == 0
		|| strcmp(orig_word7,word6) == 0 || strcmp(orig_word7,word7) == 0 || strcmp(orig_word7,word8) == 0 || strcmp(orig_word7,word9) == 0)
		++player2_score;

	if (strcmp(orig_word8,word) == 0 || strcmp(orig_word8,word2) == 0 || strcmp(orig_word8,word3) == 0 || strcmp(orig_word8,word4) == 0 || strcmp(orig_word8,word5) == 0
		|| strcmp(orig_word8,word6) == 0 || strcmp(orig_word8,word7) == 0 || strcmp(orig_word8,word8) == 0 || strcmp(orig_word8,word9) == 0)
		++player2_score;

	if (strcmp(orig_word9,word) == 0 || strcmp(orig_word9,word2) == 0 || strcmp(orig_word9,word3) == 0 || strcmp(orig_word9,word4) == 0 || strcmp(orig_word9,word5) == 0
		|| strcmp(orig_word9,word6) == 0 || strcmp(orig_word9,word7) == 0 || strcmp(orig_word9,word8) == 0 || strcmp(orig_word9,word9) == 0)
		++player2_score;

	if (player2_score > 10)
		player2_score = 10;

	if (nothing_right == player2_score && nothing_right < 10)
		player2_score-=2;

	cout << "\nPlayer 2, your score is now " << player2_score << endl;

	cout << "Enter an answer if you'd like: ";
	cin >> answer;
}

//Prompt player to reenter the question as best as he/she can remember it. The function stores the input as individual words and then use those words to compare to the original question.
void reenter_question(char word[], char word2[], char word3[], char word4[], char word5[], char word6[], char word7[], char word8[], char word9[], int & no_of_words)
{
	cout << "\nPlease enter the question as best as you can remember it: ";
	if (no_of_words == 1)
		cin >> word;
	else if (no_of_words == 2)
		cin >> word >> word2;
	else if (no_of_words == 3)
		cin >> word >> word2 >> word3;
	else if (no_of_words == 4)
		cin >> word >> word2 >> word3 >> word4;
	else if (no_of_words == 5)
		cin >> word >> word2 >> word3 >> word4 >> word5;
	else if (no_of_words == 6)
		cin >> word >> word2 >> word3 >> word4 >> word5 >> word6;
	else if (no_of_words == 7)
		cin >> word >> word2 >> word3 >> word4 >> word5 >> word6 >> word7;
	else if (no_of_words == 8)
		cin >> word >> word2 >> word3 >> word4 >> word5 >> word6 >> word7 >> word8;
	else if (no_of_words == 9)
		cin >> word >> word2 >> word3 >> word4 >> word5 >> word6 >> word7 >> word8 >> word9;
	cin.ignore(100,'\n');
}

//The program has received input for the question already from player 2 and it is now displaying the question for player 1.
void display_question_command_1(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[],
	char orig_word7[], char orig_word8[], char orig_word9[], char start, int & player1_score, int & no_of_words)
{
	display_question(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, no_of_words); //See function below for details.
	delay_loop_first(); //Short time for player 1 to look at the question (first time seeing it).
	clear_screen();

	if (player1_score > 3) //If player 1 has more than 3 points, he/she can afford to look at the question again!
	{
		cout << "Would you like to see the question again? Three (3) points will be deducted from your total (Y/N): ";
		cin >> start;
		cin.ignore(100,'\n');

		if (toupper(start) == 'Y')
		{
			player1_score = player1_score - 3;
			display_question(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, no_of_words);
			delay_loop_second(); //Long time for player 1 to look at the question (second and last time seeing it before reentering it).
			clear_screen();
		}
	}

	cout << "Hint: There are " << no_of_words << " words in the question!" << endl; //The program needs the other player to enter the same number of words to compare and display this hint for player 1.
	cout << "Player 1, your score is now " << player1_score << endl;
}

//Display question command to show the question for player 2. This function is similar to the one previous, but it is manipulating player 2's score.
void display_question_command(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[],
	char orig_word7[], char orig_word8[], char orig_word9[], char start, int & player2_score, int & no_of_words)
{
	display_question(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, no_of_words);
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
			display_question(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, no_of_words);
			delay_loop_second();
			clear_screen();
		}
	}

	cout << "Hint: There are " << no_of_words << " words in the question!" << endl;
	cout << "Player 2, your score is now " << player2_score << endl;
}

//Output the original question to the other player.
void display_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[],
	char orig_word7[], char orig_word8[], char orig_word9[], int & no_of_words)
{
	if (no_of_words == 1)
		cout << "The question was: " << orig_word << endl;
	if (no_of_words == 2)
		cout << "The question was: " << orig_word << " " << orig_word2 << endl;
	if (no_of_words == 3)
		cout << "The question was: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << endl;
	if (no_of_words == 4)
		cout << "The question was: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 << " " << endl;
	if (no_of_words == 5)
		cout << "The question was: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 << " " << orig_word5 << endl;
	if (no_of_words == 6)
		cout << "The question was: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 << " " << orig_word5 << " " << orig_word6 << endl;
	if (no_of_words == 7)
		cout << "The question was: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 << " " << orig_word5 << " " << orig_word6 << " " << orig_word7 << endl;
	if (no_of_words == 8)
		cout << "The question was: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 << " " << orig_word5 << " " << orig_word6 << " " << orig_word7 << " " << orig_word8 << endl;
	if (no_of_words == 9)
		cout << "The question was: " << orig_word << " " << orig_word2 << " " << orig_word3 << " " << orig_word4 << " " << orig_word5 << " " << orig_word6 << " " << orig_word7 << " " << orig_word8 << " " << orig_word9 << endl;
}

//Prompt player 1 if he/she is ready to start repeating the question entered by player 2.
void ask_if_player_ready_1(char start)
{
	do
	{
		cout << "Player 1, are you ready to start (Y/N)? ";
	    cin >> start;
	    cin.ignore(100,'\n');
	} while (toupper(start) != 'Y');
}

//Prompt player 2 if he/she is ready to start repeating the question entered by player 1. Since this is the opposing player rather than one who entered the question, the player variable could not be used.
//Since it is a short function, I decided just to make a new function to use it when it is player 2's turn to enter the question.
void ask_if_player_ready(char start)
{
	do
	{
		cout << "Player 2, are you ready to start (Y/N)? ";
	    cin >> start;
	    cin.ignore(100,'\n');
	} while (toupper(start) != 'Y');
}

//Asks the player how many words he/she would like to input for the question to store it accordingly to the correct array. This is for a 1 word question.
void one_word_question(char orig_word[], int player)
{
	cout << "\nPlayer " << player << ", please enter your question, without the question mark: ";
	cin >> orig_word;
	cin.ignore(100,'\n');
}

//For 2 words question.
void two_word_question(char orig_word[], char orig_word2[], int player)
{
	cout << "\nPlayer " << player << ", please enter your question, without the question mark: ";
	cin >> orig_word >> orig_word2;
	cin.ignore(100,'\n');
}

//For 3 words question.
void three_word_question(char orig_word[], char orig_word2[], char orig_word3[], int player)
{
	cout << "\nPlayer " << player << ", please enter your question, without the question mark: ";
	cin >> orig_word >> orig_word2 >> orig_word3;
	cin.ignore(100,'\n');
}

//For 4 words question.
void four_word_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], int player)
{
	cout << "\nPlayer " << player << ", please enter your question, without the question mark: ";
	cin >> orig_word >> orig_word2 >> orig_word3 >> orig_word4;
	cin.ignore(100,'\n');
}

//For 5 words question.
void five_word_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], int player)
{
	cout << "\nPlayer " << player << ", please enter your question, without the question mark: ";
	cin >> orig_word >> orig_word2 >> orig_word3 >> orig_word4 >> orig_word5;
	cin.ignore(100,'\n');
}

//For 6 words question.
void six_word_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[], int player)
{
	cout << "\nPlayer " << player << ", please enter your question, without the question mark: ";
	cin >> orig_word >> orig_word2 >> orig_word3 >> orig_word4 >> orig_word5 >> orig_word6;
	cin.ignore(100,'\n');
}

//For 7 words question.
void seven_word_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[], char orig_word7[], int player)
{
	cout << "\nPlayer " << player << ", please enter your question, without the question mark: ";
	cin >> orig_word >> orig_word2 >> orig_word3 >> orig_word4 >> orig_word5 >> orig_word6 >> orig_word7;
	cin.ignore(100,'\n');
}

//For 8 words question.
void eight_word_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[], char orig_word7[], char orig_word8[], int player)
{
	cout << "\nPlayer " << player << ", please enter your question, without the question mark: ";
	cin >> orig_word >> orig_word2 >> orig_word3 >> orig_word4 >> orig_word5 >> orig_word6 >> orig_word7 >> orig_word8;
	cin.ignore(100,'\n');
}

//For 9 words question.
void nine_word_question(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[], char orig_word7[], char orig_word8[], char orig_word9[], int player)
{
	cout << "\nPlayer " << player << ", please enter your question, without the question mark: ";
	cin >> orig_word >> orig_word2 >> orig_word3 >> orig_word4 >> orig_word5 >> orig_word6 >> orig_word7 >> orig_word8 >> orig_word9;
	cin.ignore(100,'\n');
}

//Asks the user how many words he/she would like to enter for the question and then appropriately store it in the right arrays.
void question_input(char orig_word[], char orig_word2[], char orig_word3[], char orig_word4[], char orig_word5[], char orig_word6[],
	char orig_word7[], char orig_word8[], char orig_word9[], int player, int & no_of_words)
{
	cout << "How many words would you like to enter for your questions, player " << player << " (Enter a number from 1-9)?: ";
	cin >> no_of_words;

	if (no_of_words == 1)
		one_word_question(orig_word, player);

	else if (no_of_words == 2)
		two_word_question(orig_word, orig_word2, player);

	else if (no_of_words == 3)
		three_word_question(orig_word, orig_word2, orig_word3, player);

	else if (no_of_words == 4)
		four_word_question(orig_word, orig_word2, orig_word3, orig_word4, player);

	else if (no_of_words == 5)
		five_word_question(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, player);

	else if (no_of_words == 6)
		six_word_question(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, player);

	else if (no_of_words == 7)
		seven_word_question(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, player);

	else if (no_of_words == 8)
		eight_word_question(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, player);

	else if (no_of_words == 9)
		nine_word_question(orig_word, orig_word2, orig_word3, orig_word4, orig_word5, orig_word6, orig_word7, orig_word8, orig_word9, player);

	clear_screen();
}

//Clear the screen by sending out a bunch of lines.
void clear_screen()
{
	for (int i = 0; i < 100; ++i)
		cout << endl;
}

//Delay the time (long) the question appears on the screen (second time player looks at question).
void delay_loop_second()
{
	for (int i = 0; i < 60000; ++i)
	{
		for (int j = 0; j < 60000; ++j)
		{}
	}
}

//Delay the time (short) the question appears on the screen (first time player looks at question). This is half the time of the previous delay loop.
void delay_loop_first()
{
	for (int i = 0; i < 30000; ++i)
	{
		for (int j = 0; j < 30000; ++j)
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
		cout << "In FLASH READ, two players start the game with 5 points. Player one will enter a question. The requirements are the the question's" 
			 << "number of words has to be between 1 and 9, inclusively, and that a word should not exceed 15 characters. Player two will then be allow"
			 << "to look at the question for a period of time and then ask to enter the question as accurately as possible. Player two can opt to look"
			 << "at the question again but three (3) points will be deducted from his or her total. Player two will gain one point for every word"
			 << "entered that match up with the original question, but not to exceed 10 points. Player two may enter the answer to the question if"
			 << "desired. Afterward, the players switch turn, at which point player 2 will now enter the question that player 1 needs to reenter, as" 
			 << "accurate as he or she can remember it.";
	}
}
