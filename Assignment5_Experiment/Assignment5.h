#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//Phuong Pham
//CS162
//Program 5
//This program will retrieve information about an animal (name, age, 
//weight, breed, animal friendliness, kid friendliness, and behavior). 
//It will then store the information in a struct, managed by a class. 
//A build function will then be called to build a linear linked list 
//from the information in the struct. Lastly, the program will then 
//display the information in the linear linked list. 

const int PET = 100; //Maximum size of pets a user can enter at once.

struct node
{
	node(); //constructor
	~node(); //destructor
	
	char * name;
	int age;
	int weight;
	char * breed;
	char * animal_friendly;
	char * kid_friendly;
	char * behavior;
	node * next;
};


class pet_library
{
	public:
		pet_library();
		~pet_library();
		
		void build(node * & head);
		void display_all(node * head);
		void read_in();
		void out_from_class();
		void welcome();
		
	private:
		node * array;
		int size_array;
		int num_of_pets;
};
