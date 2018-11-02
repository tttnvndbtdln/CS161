#include "Assignment_3.h"

//Phuong Pham
//CS162
//Program 3
//The purpose of this program is to help the user in selecting a fitting rescued animal as a pet, including obtaining information regarding the new rescued animal from the user to
//add that information to an either existing or new data file, searching for the animals using a certain trait or characteristic that the user is interested in, and displaying the
//information of all the animals. The program will start by welcoming the user and asks the user what he/she would like to do. There will be four options (read in information to
//add, search using specific information, display information, and quit program). If the user would like to enter information about a new pet, a void function will access the pet
//library to add information about a new pet to it. Another function will be used to write those information out to an external file. For searching the library to output information
//about certain pets interesting to the user, it would require reading in from the external data file. A function is used to scan the external file for the interested breed the user
//is in and then display that information. In order to display the information of all the pets in the pet library, first read in the entire external data file and then display that
//out. After performing each of the option that the program has to offer, the user should then be brought back to the original four choices to see if he or she would like to read in
//information, search for information, display information, or quit the program. The last option should itself be a loop encompassing all of the program and terminate if this
//condition is met (the user selects to end the program).

int main()
{
	int TEMP = 0; //Temporary variable to hold result of display_options.
	pet_library dog; //Creating a variable for the data type pet_library.

	dog.welcome();

	do
	{
		TEMP = dog.display_options();
		if (TEMP == 1)
		{
			dog.read();
			dog.write();
		}

		else if (TEMP == 2)
			dog.search();

		else if (TEMP == 3)
			dog.read_file();

	} while (TEMP != 4);

	return 0;
}
