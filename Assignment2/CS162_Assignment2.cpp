//Phuong Pham
//January 31, 2016
//CS 162
//Assignment 2

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    char instruction, stick_echo;     //variables to check/echo for instructions and number of sticks, respectively
    double no_sticks;                 //the total number of sticks the game will start with
    double number;                    //variable to generate random number
    int head_tail, pick_stick;        //hold coin toss result and number of sticks the player picks, respectively
    int computer_first, player_first; //hold results to determine which player starts the game
    bool bFail;                       //variable to check cin.fail() to ensure that the player entered the data correctly

    //Welcome user to the game and ask if the user would like to see the instructions.
    cout << "\n\tWELCOME TO PICK-UP STICKS!\n\n" << "Would you like to learn how to play the game? (Y/N): ";
    cin >> instruction;
    cin.ignore(100,'\n');

    //Display instructions.
    if (instruction == 'Y' || instruction == 'y')
    {
        cout << "In Pick-Up Stick, two players (the computer and you) start with a pile of sticks containing a certain"
             << " number of sticks that is less than 21. Each player then takes turn to remove 1 or 2 sticks from the pile."
             << " Whoever picks up the last stick loses the game. A coin toss will determine who will begin the game.\n\n";
    }

    //Prompt for number of sticks that the game will start with.
    do
    {
        do
        {
            cout << "\nHow many sticks would you like the game to start with? (2-20, select higher number for more fun!): ";
            cin >> no_sticks;

            bFail = cin.fail(); // Should the user enter invalid data (characters for integers), cin.fail() becomes true.
            cin.clear();        // Clear input buffer.
            cin.ignore(100,'\n');
        }
        //Last condition check for input failure. If cin.fail() is true, bFail is true, and the loop repeats.
        while (no_sticks > 20 || no_sticks < 2 || bFail == true);

        //Echo number of sticks.
        cout << "\nDo you want to start the game with " << no_sticks << " sticks? (Y/N): ";
        cin >> stick_echo;
        cin.ignore(100,'\n');
    }
    while (stick_echo == 'N' || stick_echo == 'n'); //Repeats the loop if user would like to reenter the number of sticks.

    //Determine who will start the game.
    do
    {
        cout << "\nThe game will start with " << no_sticks << " sticks. We will now determine who shall begin the game with a coin toss.\n\nWould you like to pick head or tail (1 for head and 2 for tail)? ";
        cin >> head_tail;

        //Similar to above, we're checking if the user's input is valid.
        bFail = cin.fail();
        cin.clear();
        cin.ignore(100,'\n');
    }
    while ((head_tail != 1 && head_tail != 2) || bFail == true);

    //Initialize random seed.
    srand(time(0));
    //Randomly generate a 1 or 2.
    number = rand()%2+1;

    //if statements to compare the random generator result's and the user's input. This will determine who will begin the game.
    if (head_tail == number && number == 1)
    {
        cout << "\nThe coin toss resulted in a head and you will go first.";
        player_first = 1;
    }

    else if (head_tail == number && number == 2)
    {
        cout << "\nThe coin toss resulted in a tail and you will go first.";
        player_first = 1;
    }

    else if (head_tail != number && number == 1)
    {
        cout << "\nThe coin toss resulted in a head and the computer will go first.";
        computer_first = 1;
    }

    else
    {
        cout << "\nThe coin toss resulted in a tail and the computer will go first.";
        computer_first = 1;
    }

    //If the player goes first.
    if (player_first == 1)
    {
        do
        {
            //Prompt the user for the number of sticks he/she would like to remove (1 or 2).
            do
            {
                cout << "\nPlease select the number of sticks you would like to pick up (1 or 2): ";
                cin >> pick_stick;

                //Similarly to above, bFail becomes true if input failure.
                bFail = cin.fail();
                cin.clear();
                cin.ignore(100,'\n');
            }
            while ((pick_stick != 1 && pick_stick != 2) || bFail == true);

            //Decrement the total sticks by the number of sticks the user removed.
            no_sticks = no_sticks - pick_stick;

            //Let the user know how many sticks they removed and how many are left.
            cout << "\nYou have picked up " << pick_stick << " stick(s) and there are "
                 << no_sticks << " sticks left now.\n";

            //This illustrates the computer's turn after the player.
            //This if statement executes if the number of sticks left is 1 more than the "poison" numbers.
            //There is no 20 in the conditional expression since the maximum number of sticks is 20 and the
            //user needs to remove at least 1 stick in the previous turn.
            if (no_sticks == 5 || no_sticks == 8 || no_sticks == 11 || no_sticks == 14 || no_sticks == 17)
            {
                //In this case, the computer will remove 1 stick to force the player with the "poison" number.
                no_sticks = no_sticks - 1;

                //Let the user know how many sticks the computer removed and how many are left.
                cout << "\nThe computer has picked up 1 stick and there are " << no_sticks << " sticks left now.\n";

                //The computer can also correctly predict that it will win this round!
                cout << "\nThe computer will win this round.\n";
            }

            //This else if statement executes if the number of sticks left is 2 more than the "poison" numbers.
            else if (no_sticks == 6 || no_sticks == 9 || no_sticks == 12 || no_sticks == 15 || no_sticks == 18)
            {
                //The computer will remove 2 sticks to force the player with the "poison" number.
                no_sticks = no_sticks - 2;

                //Let the user know what is happening.
                cout << "\nThe computer has picked up 2 sticks and there are " << no_sticks << " sticks left now.\n";

                //Similarly to the if statement above, the computer can also predict it will win this round!
                cout << "\nThe computer will win this round.\n";
            }

            //This block will executes if the computer is left with the "poison" number.
            else if (no_sticks == 4 || no_sticks == 7 || no_sticks == 10 || no_sticks == 13 || no_sticks == 16 || no_sticks == 19)
            {
                //The computer will remove 1 stick in this case.
                no_sticks = no_sticks - 1;

                //Echo number of sticks removed/left.
                cout << "\nThe computer has picked up 1 stick and there are " << no_sticks << " sticks left now.\n";

                //The computer does not know the skill level of the user. An unskilled player may not know what 17 is a
                //"poison" number and make a mistake. As a result, the computer will only safely predict the user's
                //victory when it is clear (e.g. there are 3 sticks left after the computer's turn).
                if (no_sticks == 3 || no_sticks == 2)
                {
                    cout << "\nIt appears you will win this round.\n";
                }

                //When the user is close to winning (5 or 6 sticks left after the computer's turn).
                else if (no_sticks == 6 || no_sticks == 5)
                {
                    cout << "\nIt appears you are close to victory.\n";
                }
            }

            //This block executes to nicely end the game and display the Game Over message when there are 3 sticks left.
            else if (no_sticks == 3)
            {
                no_sticks = 1;
                cout << "\nThe computer has picked up 2 sticks and there is 1 stick left.\nYOU HAVE LOST!\n\nGAME OVER!\n";
            }

            //Similar to the next one above but with 2 sticks left instead of 3.
            else if (no_sticks == 2)
            {
                 no_sticks = 1;
                 cout << "\nThe computer has picked up 1 stick and there is 1 stick left.\nYOU HAVE LOST!\n\nGAME OVER!\n";
            }

            //The user wins if there is 1 stick left and it is the computer's turn.
            else if (no_sticks == 1)
            {
                cout << "\nYOU HAVE WIN!\n\nGAME OVER!\n";
            }

            //Catch the case user remove 2 sticks when there are 2 sticks left. By definition, the user still removed the last
            //stick and considered to have lost.
            else
            {
                cout << "\nYOU HAVE LOST!\n\nGAME OVER!\n";
            }
        }
        while (no_sticks > 1); //Do/while loops continue until the last stick.
    }

    //This block executes if the computer goes first.
    if (computer_first == 1)
    {
        do
        {
            //User wins if there is 1 stick left (or 0 in case user picked up 2 sticks when there were 2 left
            //and it's the computer's turn.
            if (no_sticks == 1 || no_sticks == 0)
            {
                cout << "\nYOU HAVE WON!\n\nGAME OVER!\n";
            }

            //The computer will force the user with a "poison" number by removing 1 stick in this block.
            else if (no_sticks == 5 || no_sticks == 8 || no_sticks == 11 || no_sticks == 14 || no_sticks == 17 || no_sticks == 20)
            {
                //Decrement total sticks by 1.
                no_sticks = no_sticks - 1;
                cout << "\nThe computer has picked up 1 stick.\n";

                //Prompt the user to remove sticks (the user's turn).
                do
                {
                    cout << "\nThere are now " << no_sticks << " sticks left.\n\nHow many sticks would you like to pick up (1 or 2)? ";
                    cin >> pick_stick;

                    bFail = cin.fail();
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                while ((pick_stick != 1 && pick_stick != 2) || bFail == true); //Loop until valid input.

                //Decrement total sticks by user's input.
                no_sticks = no_sticks - pick_stick;

                //The computer can predict it will win since the user will be left with a "poison" number.
                cout << "\nThere are now " << no_sticks << " sticks left.\n\nThe computer will win this round.\n";
            }

            //This block executes if number of sticks left is 2 more than the "poison" numbers.
            else if (no_sticks == 6 || no_sticks == 9 || no_sticks == 12 || no_sticks == 15 || no_sticks == 18)
            {
                //Decrement total sticks by 2 to force player with "poison" numbers.
                no_sticks = no_sticks - 2;
                cout << "\nThe computer has picked up 2 sticks.\n";

                //Prompt the user to remove sticks (user's turn).
                do
                {
                    cout << "\nThere are now " << no_sticks << " sticks left. How many sticks would you like to pick up (1 or 2)? ";
                    cin >> pick_stick;

                    bFail = cin.fail();
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                while ((pick_stick != 1 && pick_stick != 2) || bFail == true); //Loop until valid input.

                //Decrement by user's input.
                no_sticks = no_sticks - pick_stick;

                //The computer can predict it will win since the user will be left with a "poison" number.
                cout << "\nThere are now " << no_sticks << " sticks left.\n\nThe computer will win this round.\n";
            }

            //This block executes if number of sticks left is a "poison" number.
            else if (no_sticks == 4 || no_sticks == 7 || no_sticks == 10 || no_sticks == 13 || no_sticks == 16 || no_sticks == 19)
            {
                //The computer will removes 1 stick in this case.
                no_sticks = no_sticks - 1;
                cout << "\nThe computer has picked up 1 stick.\n";

                //Prompt the user to remove sticks (user's turn).
                do
                {
                    cout << "\nThere are " << no_sticks << " left. How many sticks would you liek to pick up (1 or 2)? \n";
                    cin >> pick_stick;

                    bFail = cin.fail();
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                while ((pick_stick != 1 && pick_stick != 2) || bFail == true);

                //Decrement by user's input.
                no_sticks = no_sticks - pick_stick;
                cout << "\nThere are now " << no_sticks << " sticks left.\n";

                //Safely predict the user's victory when it is apparent.
                if (no_sticks == 3 || no_sticks == 2)
                {
                    cout << "\nIt appears you will win this round.\n";
                }

                //Let the user know if he/she is close to winning.
                else if (no_sticks == 6 || no_sticks == 5)
                {
                    cout << "\nIt appears you are close to winning.\n";
                }
            }

            //This block excecutes if there are 3 sticks left, and the computer will win.
            else if (no_sticks == 3)
            {
                no_sticks = 1;
                cout << "\nThe computer has picked up 2 sticks and there is 1 stick left.\n\nYOU HAVE LOST!\n\nGAME OVER!\n";
            }

            //The computer will also win if there are 2 sticks left and it is its turn.
            else if (no_sticks == 2)
            {
                no_sticks = 1;
                cout << "\nThe computer has picked up 1 stick and there is 1 stick left.\n\nYOU HAVE LOST!\n\nGAME OVER!\n";
            }
        }
        while (no_sticks > 1); //Loop until number of sticks is 1.
    }

  return 0;
}
