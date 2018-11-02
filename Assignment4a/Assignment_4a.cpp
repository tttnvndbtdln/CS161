#include "Assignment_4a.h"

//Phuong Pham
//CS162
//Program 4

//Constructor to initialize data members
pet_library::pet_library() //constructor
{
	num_of_pets = 0;
}

//Display Options and ask what the user would like to do.
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

	cout << "\nWhat type of breed would you like to search by? ";
	cin.get(breed, BREED, '\n');
	cin.ignore(100,'\n');
	
	read_and_store();

	int counter = 0;
	for (int i = 0; i < 10; ++i)
	{
		//If the word matches with the breed the user input.
		if (strcmp(breed,library[i].breed) == 0) 
		{
			cout << library[i].name << endl << library[i].breed << endl 
			 << library[i].age << endl << library[i].weight << endl 
			 << library[i].animal_friendly << endl << library[i].kid_friendly 
			 << endl << library[i].behavior << endl;
			found = true;
		}
	}

	if (found == false)
		cout << "\nSorry. No pets with that breed. Try again." << endl;
}


//Read from the external file and store it in array of animals.
void pet_library::read_and_store()
{
	ifstream in_file;
	in_file.open(outfile);
	int i;

	if (in_file)
	{
		for (i = 0; !in_file.eof(); ++i)
		{
			in_file >> library[i].breed;
			in_file.ignore(100,'\n');
			in_file >> library[i].name;
			in_file.ignore(100,'\n');
			in_file >> library[i].age;
			in_file.ignore(100,'\n');
			in_file >> library[i].weight;
			in_file.ignore(100,'\n');
			in_file >> library[i].animal_friendly;
			in_file.ignore(100,'\n');
			in_file >> library[i].kid_friendly;
			in_file.ignore(100,'\n');
			in_file >> library[i].behavior;
			in_file.ignore(100,'\n');
			
			++i;
		}	
	}

	in_file.close();
	in_file.clear();
	
	num_of_pets = num_of_pets + i;
}

//Display all animals from array from class
void pet_library::out_from_class()
{
	for (int i = 0; i < num_of_pets; ++i)
		cout << library[i].name << endl << library[i].breed << endl 
			 << library[i].age << endl << library[i].weight << endl 
			 << library[i].animal_friendly << endl << library[i].kid_friendly 
			 << endl << library[i].behavior << endl;
}


//Write out to external file.
void pet_library::write()
{
	ofstream out;
	//Will always append. If the file does not exist, it will create one.
	out.open(outfile, ios::app); 

	if (out)
	{
		for (int i = 0; i < num_of_pets; ++i)
		{
			out << library[i].breed << ";" << endl; 
			out << library[i].name << ";" << endl; 
			out << library[i].age << ";" << endl; 
			out << library[i].weight << ";" << endl; 
			out << library[i].animal_friendly << ";" << endl; 
			out << library[i].kid_friendly << ";" << endl; 
			out << library[i].behavior << ";" << endl;
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

	for (i = 0; i < PET && response == 'Y'; ++i)
	{
		cout << "Please enter the breed of the animal. If the animal is a mixed, please enter"
			 << " the top two breeds in the mixed: ";
		cin.get(library[i].breed, BREED, '\n');
		cin.ignore(100,'\n');
		
		cout << "Please enter the name of the animal: ";
		cin.get(library[i].name, NAME, '\n');
		cin.ignore(100,'\n');

		cout << "Please enter the age of the animal: ";
		cin >> library[i].age;
		cin.ignore(100,'\n');

		cout << "Please enter the weight of the animal: ";
		cin >> library[i].weight;
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
/*

			in_file.get(library[i].breed,BREED,'\n');
			in_file.get(library[i].name,NAME,'\n');
			in_file >> library[i].age;
			//in_file.ignore(100,';');
			in_file >> library[i].weight;
			//in_file.ignore(100,';');
			in_file.get(library[i].animal_friendly,ANIMAL_FRIENDLY,'\n');
			in_file.get(library[i].kid_friendly,KID_FRIENDLY,'\n');
			in_file.get(library[i].behavior,BEHAVIOR,'\n');
			

			in_file >> library[i].breed >> library[i].name >> library[i].age 
					>> library[i].weight >> library[i].animal_friendly 
					>> library[i].kid_friendly >> library[i].behavior;*/