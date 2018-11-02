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

//Constructor to initialize data members
pet_library::pet_library() //constructor
{
	num_of_pets = 0;
}

//Display Options.
int pet_library::display_options()
{
	int select = 0; //Initialize user's choice.

	do
	{
		cout << "\n\nWhat would you like to do?" << endl << "\t1. Add information about a new animal."
			 << endl << "\t2. Search for animals to find a particular breed." << endl << "\t3. Display"
			 << " all pets' information." << endl << "\t4. Quit program." << endl;
		cin >> select;
		cin.ignore(100,'\n');
	} while (select < 1 || select > 4); //Repeat loop until user select appropriate option.

	return select; //Return the result of select to main, which will be stored in the variable TEMP (in main).
}

//Search for a pet using a breed the user put in.
void pet_library::search()
{
	char breed[BREED]; //Variable to hold user's input of the interested breed.
	bool found = false;

	cout << "\nWhat type of breed would you like to search by (Type in the breed, follow by a semicolon(;))? ";
	cin.get(breed, BREED, '\n');
	cin.ignore(100,'\n');

	ifstream in_file;
	in_file.open(outfile); //Open file.

	char word[50]; //Initialize word because will be reading in a word from the file.
	int counter = 0;

	while (in_file.good()) //While it is not the end of the file yet.
	{
		in_file >> word; //Read in a whole word from the file.

		if (strcmp(breed,word) == 0) //If the word matches with the breed the user input.
		{
			while (in_file.good() && counter < 20) //If it is a match, it will display the next block of section that has the pet's information.
			{
				for (int i = 0; i < 15; ++i)
				{
					if (word[i] == '*')
						cout << endl;
				}
				cout << word << " ";
				in_file >> word;
				++counter;
				found = true;
			}
		}
		counter = 0;

	}

	if (found == false)
		cout << "\nSorry. No pets with that breed. Try again." << endl;
}

//Read in from external file and display information of all pets.
void pet_library::read_file()
{
	char ch;
	ifstream in_file;
	in_file.open(outfile); //Open animal.txt.

	if (in_file) //If connected.
	{
		ch = in_file.get(); //Read in.
		while (in_file && !in_file.eof())
		{
			cout << ch;
			//Put out spaces and delimiters to make it looks nicer.
			if (ch == ';')
				cout << endl;
			else if (ch == ' ')
				cout << ' ';
			else if (ch == '*')
				cout << endl << endl;

			ch = in_file.get(); //Continue to read again.
		}
	}

	in_file.close();
	in_file.clear();

}

//Write out to external file.
void pet_library::write()
{
	ofstream out;
	out.open(outfile, ios::app); //Will always append. If the file does not exist, it will create one.

	if (out)
	{
		for (int j = 0; j < num_of_pets; ++j)
		{
			out << "\nBreed: " << library[j].breed << ";" << endl << "Name: " << library[j].name << ";" << endl << "Age: " 
				<< library[j].age << ";" << endl << "Weight: " << library[j].weight << ";" << endl << "Friendly to other animals? " 
				<< library[j].animal_friendly << ";" << endl << "Friendly to kids? " << library[j].kid_friendly << ";" << endl 
				<< "Animal's behavior: " << library[j].behavior << endl << "*" << endl;
		}
	}

	out.close();
	out.clear();

}

//Read in information of a pet from the user.
void pet_library::read()
{
	char response = 'Y';
	int i = 0;

	for (i = num_of_pets; i < PET && response == 'Y'; ++i)
	{
		cout << "Please enter the name of the animal: ";
		cin.get(library[i].name, NAME, '\n');
		cin.ignore(100,'\n');

		cout << "Please enter the age of the animal: ";
		cin >> library[i].age;
		cin.ignore(100,'\n');

		cout << "Please enter the weight of the animal: ";
		cin >> library[i].weight;
		cin.ignore(100,'\n');

		cout << "Please enter the breed of the animal. If the animal is a mixed, please enter"
		     << " the top two breeds in the mixed: ";
		cin.get(library[i].breed, BREED, '\n');
		cin.ignore(100,'\n');

		cout << "Is the animal friendly with other animals? ";
		cin.get(library[i].animal_friendly, ANIMAL_FRIENDLY, '\n');
		cin.ignore(100,'\n');

		cout << "Is the animal friendly with kids? ";
		cin.get(library[i].kid_friendly, KID_FRIENDLY, '\n');
		cin.ignore(100,'\n');

		cout << "What is the behaviors of the animal like (playful, bashful, etc.)? ";
		cin.get(library[i].behavior, BEHAVIOR, '\n');
		cin.ignore(100,'\n');

		cout << "Would you like to enter information of another pet (Y/N)? ";
		cin >> response;
		cin.ignore(100,'\n');
		response = toupper(response);
	}

	num_of_pets = i;
}

void pet_library::welcome()
{
	cout << "\nWelcome! This program has several functions. Please select from the following options."
		 << "\nOption 1 will allow you to add information about a new pet to the existing pet's library."
		 << "\nOption 2 will allow you to search for a certain pet of a breed you're interested in."
		 << "\nOption 3 will display all of the pets' information in the library."
		 << "\nOption 4 will quit the program.";
}

//Failed codes. Trying to compare characters and then combine those characters to see if they match up to the breed.
	/*
	//char animal_breed[BREED];
	//bool found = false;
	//char ch;
	//int i = 0;
	if (in_file)
	{
		ch = in_file.get();

		while (in_file && !in_file.eof())
		{
			if (ch == breed[i]) //If there is a match in the first letter.
			{
				animal_breed[i] = breed[i]; //Save that letter in the animal_breed array.
				++i;
			}

			if (strcmp(breed,animal_breed) == 0) //If the whole word of the animal_breed array is a match with the breed word.
			{
				cout << ch; //Start ouputting.
				if (ch == '*') //Until end of the pet's section.
					animal_breed[0] = 0; //Then change the array to make the condition for this if statement false.

				found = true;
			}

			ch = in_file.get();
		}
	}*/

	//if (!found)
		//cout << "\nSorry, no pets with that breed. Try again." << endl;

/*
//Failed codes. Realized I needed to read in from file to display.
//Display all pets' information.
void pet_library::display()
{
	for (int i = 0; i < num_of_pets; ++i)
	{
		cout << "\nName: " << library[i].name << endl << library[i].age << endl << library[i].weight << endl
			 << library[i].breed << endl << "Friendly to another animals? " << library[i].animal_friendly
			 << endl << "Friendly to kids? " << library[i].kid_friendly << endl << "Animal's behavior: "
			 << library[i].behavior << endl;
	}
}
*/

/*
//Failed partial codes. Realized this would only search for pet information typed in during that program.
//After program exits, all information will be lost.
	for (int i = 0; i < num_of_pets; ++i)
	{
		if (strcmp(breed,library[i].breed) == 0)
		{
			cout << "\nName: " << library[i].name << endl << "Age: " << library[i].age << endl << "Weight: "
				 << library[i].weight <<  endl << "Breed: " << library[i].breed << endl << "Friendly to other animals? "
				 << library[i].animal_friendly << ";" << endl << "Friendly to kids? " << library[i].kid_friendly << endl
				 << "Animal's behavior: " << library[i].behavior << ";" << endl;
			found = true;
		}
	}
*/
