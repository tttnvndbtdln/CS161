#include "Assignment_4c.h"

//Phuong Pham
//CS162
//Program 4
//The purpose of this program is similar to program 3, but to expand it
//and having a class that contains a dynamically allocated array of animals.
//The following is the algorithm for program 3 that this program will mirror.

//The purpose of this program (program 3) is to help the user in selecting a 
//fitting rescued animal as a pet, including obtaining information regarding 
//the new rescued animal from the user to add that information to an either 
//existing or new data file, searching for the animals using a certain trait 
//or characteristic that the user is interested in, and displaying the information 
//of all the animals. The program will start by welcoming the user and asks the 
//user what he/she would like to do. There will be four options (read in information 
//to add, search using specific information, display information, and quit program). 
//If the user would like to enter information about a new pet, a void function will 
//access the pet library to add information about a new pet to it. Another function 
//will be used to write those information out to an external file. For searching the 
//library to output information about certain pets interesting to the user, it would 
//require reading in from the external data file. A function is used to scan the 
//external file for the interested breed the user is in and then display that 
//information. In order to display the information of all the pets in the pet library, 
//first read in the entire external data file and then display that out. After 
//performing each of the option that the program has to offer, the user should then 
//be brought back to the original four choices to see if he or she would like to read 
//in information, search for information, display information, or quit the program. 
//The last option should itself be a loop encompassing all of the program and terminate 
//if this condition is met (the user selects to end the program).


//Struct constructor to initialize data members.
pet::pet() 
{
	name = NULL;
	age = 0;
	weight = 0;
	breed = NULL;
	animal_friendly = NULL;
	kid_friendly = NULL;
	behavior = NULL;
}

//Struct destructor to deallocate all dynamically allocated arrays.
pet::~pet()
{
	if (name)
	{
		delete [] name;
		name = NULL;
	}
	if (breed)
	{
		delete [] breed;
		breed = NULL;
	}
	if (animal_friendly)
	{
		delete [] animal_friendly;
		animal_friendly = NULL;
	}	

	if (kid_friendly)
	{
		delete [] kid_friendly;
		kid_friendly = NULL;
	}

	if (behavior)
	{
		delete [] behavior;
		behavior = NULL;
	}
	age = 0;
	weight = 0;
}

//Class constructor
pet_library::pet_library()
{
	array = new pet[100];
	size_array = 100;
	num_of_pets = 0; 
}

//Class destructor.
pet_library::~pet_library()
{
	if (array)
		delete[] array;
	size_array = 100;
	num_of_pets = 0;
}


//Display options and ask what the user would like to do.
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

	return select; //Return the result of select to main, which will be 
				   //stored in the variable TEMP (in main).
}


//Search for a pet using a breed the user put in.
void pet_library::search()
{
	char breed[100]; //Variable to hold user's input of the interested breed.
	bool found = false;

	cout << "\nWhat type of breed would you like to search by (Type in the breed, followed by a semicolon)? ";
	cin.get(breed, 100, '\n');
	cin.ignore(100,'\n');

	for (int i = 0; i < num_of_pets; ++i)
	{
		//If the word matches with the breed the user input.
		if (strcmp(breed,array[i].breed) == 0) 
		{
			cout << array[i].name << endl; 
			cout << array[i].breed << endl; 
			cout << array[i].age << endl; 
			cout << array[i].weight << endl; 
			cout << array[i].animal_friendly << endl; 
			cout << array[i].kid_friendly << endl; 
			cout << array[i].behavior << endl;
			
			found = true;
		}
	}

	if (found == false)
		cout << "\nSorry. No pets with that breed. Try again." << endl;
}

//Read from the external file and store it in array of animals.
//I understand this function exceeds 30 lines. I just didn't have
//time to break it apart or the heart to because it's just working
//so well. Sorry. 
void pet_library::read_and_store()
{
	ifstream in_file;
	in_file.open(outfile);
	int i = 0;
	char temp[100];

	num_of_pets = 0; //num_of_pets will be updated after reading in
					 //this prevent the num_of_pets being carried
					 //over from read function.
					 
	if (in_file)
	{
		in_file >> temp;
		in_file.ignore(100,'\n');
		
		array[i].breed = new char [strlen(temp) + 1];
		strcpy(array[i].breed,temp);

		for (i = 0; !in_file.eof();)
		{	
			in_file >> temp;
			in_file.ignore(100,'\n');
			
			array[i].name = new char[strlen(temp) + 1];
			strcpy(array[i].name,temp);			
			
			in_file >> array[i].age;
			in_file.ignore(100,'\n');
			in_file >> array[i].weight;
			in_file.ignore(100,'\n');
			
			in_file >> temp;
			in_file.ignore(100,'\n');
			
			array[i].animal_friendly = new char[strlen(temp) + 1];
			strcpy(array[i].animal_friendly,temp);		
			
			in_file >> temp;
			in_file.ignore(100,'\n');
			
			array[i].kid_friendly = new char[strlen(temp) + 1];
			strcpy(array[i].kid_friendly,temp);
			
			in_file >> temp;
			in_file.ignore(100,'\n');
		
			array[i].behavior = new char[strlen(temp) + 1];
			strcpy(array[i].behavior,temp);

			++i;

			in_file >> temp;
			in_file.ignore(100,'\n');

			array[i].breed = new char [strlen(temp) + 1];
			strcpy(array[i].breed,temp);
		}	
	}

	in_file.close();
	in_file.clear();

	//The number of times the loop iterates is the number of pets,
	//which will be updated to num_of_pets.
	num_of_pets = num_of_pets + i; 
}

//Display all animals from array of animals from class
void pet_library::out_from_class()
{

	for (int i = 0; i < num_of_pets; ++i)
	{
		cout << "Name: " << array[i].name << endl; 
		cout << "Breed: " << array[i].breed << endl; 
		cout << "Age: " << array[i].age << endl;
		cout << "Weight: " << array[i].weight << endl; 
		cout << "Animal friendly? " << array[i].animal_friendly << endl; 
		cout << "Kid friendly? " << array[i].kid_friendly << endl; 
		cout << "Behavior: " << array[i].behavior << endl;
	}
}


//Write out information from the user's input  to external file.
void pet_library::write()
{
	ofstream out;
	//Will always append. If the file does not exist, it will create one.
	out.open(outfile, ios::app); 

	if (out)
	{
		for (int i = 0; i < num_of_pets; ++i)
		{
			out << array[i].breed << ";" << endl; 
			out << array[i].name << ";" << endl; 
			out << array[i].age << ";" << endl; 
			out << array[i].weight << ";" << endl; 
			out << array[i].animal_friendly << ";" << endl; 
			out << array[i].kid_friendly << ";" << endl; 
			out << array[i].behavior << ";" << endl;
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
	char temp[100];

	for (i = 0; i < PET && response == 'Y'; ++i)
	{
		cout << "Please enter the breed of the animal. If the animal is a mixed, please enter"
			 << " the top two breeds in the mixed: ";
		cin.get(temp, 100, '\n');
		cin.ignore(100,'\n');
		
		array[i].breed = new char[strlen(temp) + 1];
		strcpy(array[i].breed,temp);
		
		cout << "Please enter the name of the animal: ";
		cin.get(temp, 100, '\n');
		cin.ignore(100,'\n');
		
		array[i].name = new char[strlen(temp) + 1];
		strcpy(array[i].name,temp);

		cout << "Please enter the age of the animal: ";
		cin >> array[i].age;
		cin.ignore(100,'\n');

		cout << "Please enter the weight of the animal: ";
		cin >> array[i].weight;
		cin.ignore(100,'\n');
		
		cout << "Is the animal friendly with other animals? ";
		cin.get(temp, 100, '\n');
		cin.ignore(100,'\n');
		
		array[i].animal_friendly = new char[strlen(temp) + 1];
		strcpy(array[i].animal_friendly,temp);
		
		cout << "Is the animal friendly with kids? ";
		cin.get(temp, 100, '\n');
		cin.ignore(100,'\n');
		
		array[i].kid_friendly = new char[strlen(temp) + 1];
		strcpy(array[i].kid_friendly,temp);

		cout << "What is the behaviors of the animal like (playful, bashful, etc.)? ";
		cin.get(temp, 100, '\n');
		cin.ignore(100,'\n');
		
		array[i].behavior = new char[strlen(temp) + 1];
		strcpy(array[i].behavior,temp);

		cout << "Would you like to enter information of another pet (Y/N)? ";
		cin >> response;
		cin.ignore(100,'\n');
		response = toupper(response);
	}
	
	num_of_pets = i;
}

//Function to welcome the user to the program and explain the choices that he/she can make.
void pet_library::welcome()
{
	cout << "\nWelcome! This program has several functions. Please select from the following options."
		 << "\nOption 1 will allow you to add information about a new pet to the existing pet's library."
		 << "\nOption 2 will allow you to search for a certain pet of a breed you're interested in."
		 << "\nOption 3 will display all of the pets' information in the library."
		 << "\nOption 4 will quit the program.";
}
