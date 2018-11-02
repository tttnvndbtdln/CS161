#include "Assignment_4b.h"

//Phuong Pham
//CS162
//Program 4
//

//Constructor to initialize data members
pet::pet() //constructor
{
	name = NULL;
	age = 0;
	weight = 0;
	breed = NULL;
	animal_friendly = NULL;
	kid_friendly = NULL;
	behavior = NULL;
}

//Destructor.
pet::~pet()
{
	if (name)
		delete [] name;
	if (breed)
		delete [] breed;
	if (animal_friendly)
		delete [] animal_friendly;
	if (kid_friendly)
		delete [] kid_friendly;
	if (behavior)
		delete [] behavior;
	age = 0;
	weight = 0;
}

//Constructor expecting integer argument.
pet_library::pet_library(int num_of_pets)
{
	array = new pet[num_of_pets];
	size_array = num_of_pets;
	num_of_pets = 0;
}

//Destructor.
pet_library::~pet_library()
{
	if (array)
		delete[] array;
	size_array = 0;
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

/*
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
*/

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



//Read in and store.
void pet_library::read_and_store()
{
	ifstream in_file;
	in_file.open(outfile);
	
	if (in_file)
	{
		for (int i = 0; i < 10; ++i)
			in_file >> array[i].breed >> array[i].name >> array[i].age >> array[i].weight >> array[i].animal_friendly
					>> array[i].kid_friendly >> array[i].behavior;
	}
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
			/*out << "\nBreed: " << library[j].breed << ";" << endl << "Name: " << library[j].name << ";" << endl << "Age: " 
				<< library[j].age << ";" << endl << "Weight: " << library[j].weight << ";" << endl << "Friendly to other animals? " 
				<< library[j].animal_friendly << ";" << endl << "Friendly to kids? " << library[j].kid_friendly << ";" << endl 
				<< "Animal's behavior: " << library[j].behavior << endl << "*" << endl;*/
				
			out << array[j].breed << endl << array[j].name << endl << array[j].age << endl << array[j].weight << endl 
				<< array[j].animal_friendly << endl << array[j].kid_friendly << endl << array[j].behavior << endl << "*" << endl;
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

	for (i = num_of_pets; response == 'Y'; ++i)
	{
		cout << "Please enter the name of the animal: ";
		cin.get(array[i].name, 100, '\n');
		cin.ignore(100,'\n');

		cout << "Please enter the age of the animal: ";
		cin >> array[i].age;
		cin.ignore(100,'\n');

		cout << "Please enter the weight of the animal: ";
		cin >> array[i].weight;
		cin.ignore(100,'\n');

		cout << "Please enter the breed of the animal. If the animal is a mixed, please enter"
		     << " the top two breeds in the mixed: ";
		cin.get(array[i].breed, 100, '\n');
		cin.ignore(100,'\n');

		cout << "Is the animal friendly with other animals? ";
		cin.get(array[i].animal_friendly, 100, '\n');
		cin.ignore(100,'\n');

		cout << "Is the animal friendly with kids? ";
		cin.get(array[i].kid_friendly, 100, '\n');
		cin.ignore(100,'\n');

		cout << "What is the behaviors of the animal like (playful, bashful, etc.)? ";
		cin.get(array[i].behavior, 100, '\n');
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
