#include "Assignment5.h"

//Phuong Pham
//CS162
//Program 5
//This program will retrieve information about an animal (name, age, 
//weight, breed, animal friendliness, kid friendliness, and behavior). 
//It will then store the information in a struct, managed by a class. 
//A build function will then be called to build a linear linked list 
//from the information in the struct. Lastly, the program will then 
//display the information in the linear linked list. 

//Building the linear linked list.
void pet_library::build (node * & head)
{
	int i = 0;
	node * temp = new node;
	
	temp -> name = array[i].name;
	temp -> age = array[i].age;
	temp -> weight = array[i].weight;
	temp -> breed = array[i].breed;
	temp -> animal_friendly = array[i].animal_friendly;
	temp -> kid_friendly = array[i].kid_friendly;
	temp -> behavior = array[i].behavior;
	temp -> next = NULL;
	head = temp;
	node * current = head;
	
	for (i = 1; i < num_of_pets; ++i)
	{
		node * temp = new node;
		
		temp -> name = array[i].name;
		temp -> age = array[i].age;
		temp -> weight = array[i].weight;
		temp -> breed = array[i].breed;
		temp -> animal_friendly = array[i].animal_friendly;
		temp -> kid_friendly = array[i].kid_friendly;
		temp -> behavior = array[i].behavior;
		temp -> next = NULL;
		
		current -> next = temp;
		current = temp;
	}
}

//Display all of the animal's information in the linear linked list.
void pet_library::display_all(node * head)
{
	node * current = head;
	while (current)
	{
		cout << endl;
		cout << "Name: " << current -> name << endl;
		cout << "Age: " << current -> age << endl;
		cout << "Weight: " << current -> weight << endl;
		cout << "Breed: " << current -> breed << endl;
		cout << "Animal Friendly? " << current -> animal_friendly << endl;
		cout << "Kid Friendly? " << current -> kid_friendly << endl;
		cout << "Behavior: " << current -> behavior << endl << endl;
			
		current = current -> next;
	}
}

//Read in the animal's information from the user.
void pet_library::read_in()
{
	char response = 'Y';
	int i = 0;
	char temp[100];

	for (i = 0; i < PET && response == 'Y'; ++i)
	{
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
		
		cout << "Please enter the breed of the animal. If the animal is a mixed, please enter"
			 << " the top two breeds in the mixed: ";
		cin.get(temp, 100, '\n');
		cin.ignore(100,'\n');
		
		array[i].breed = new char[strlen(temp) + 1];
		strcpy(array[i].breed,temp);
		
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

//Welcome the user to the program.
void pet_library::welcome()
{
	cout << endl << endl;
	cout << "Welcome! This program will prompt you for information about a pet or pets"
		 << " and will display it back to you!" << endl << endl;
}

//Class constructor
pet_library::pet_library()
{
	array = new node[100];
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

//Struct constructor. Initialize all data members.
node::node() 
{
	name = NULL;
	age = 0;
	weight = 0;
	breed = NULL;
	animal_friendly = NULL;
	kid_friendly = NULL;
	behavior = NULL;
}

//Struct destructor. Deallocate memories.
node::~node()
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

//Unsucessful tries at extra credit.
//Building the linear linked list.
/*void pet_library::build (node * & head)
{
	int i = 0;
	node * temp = new node;
	
	temp -> name = array[i].name;
	temp -> age = array[i].age;
	temp -> weight = array[i].weight;
	temp -> breed = array[i].breed;
	temp -> animal_friendly = array[i].animal_friendly;
	temp -> kid_friendly = array[i].kid_friendly;
	temp -> behavior = array[i].behavior;
	temp -> next = NULL;
	
	head = temp;
	node * current = head;
	
	for (i = 1; i < num_of_pets; ++i)
	{
		node * temp = new node;
		
		temp -> name = array[i].name;
		temp -> age = array[i].age;
		temp -> weight = array[i].weight;
		temp -> breed = array[i].breed;
		temp -> animal_friendly = array[i].animal_friendly;
		temp -> kid_friendly = array[i].kid_friendly;
		temp -> behavior = array[i].behavior;
		temp -> next = NULL;
		
		//Will add the node to the beginning if the animal's name
		//is less than the first node.
		if (strcmp(temp -> name,head -> name) <= 0)
		{
			node * head2 = head;
			head = temp;
			head -> next = head2;
		}
		
		else
		{
			node * current2 = head;
			node * previous = head;
			while (current2 -> next)
			{
				if (strcmp(temp -> name, current2 -> name) <= 0)
				{
					previous -> next = temp;
					temp -> next = current2;
				}
				
				previous = current2;
				current2 = current2 -> next;
				
				if (current2 -> next == NULL)
					current2 -> next = temp;
			}
		}
	}
}*/