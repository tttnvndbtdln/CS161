#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

//Phuong Pham
//CS162
//Program 4
//

//TO LOAD FROM EXTERNAL FILE AND STORE IT IN ARRAY OF ANIMALS:
//CHECK OUT PAGE 623 OF TEXTBOOK.
//ALSO SLIDES ON STRUCTURES.

//External file to write out.
const char outfile[] = "animal.txt";

struct pet
{
	pet();
	~pet();
	
	char * name;
	int age;
	int weight;
	char * breed;
	char * animal_friendly;
	char * kid_friendly;
	char * behavior;
};

//Class Interface.
class pet_library
{
	public:
		pet_library(); //constructor
		~pet_library(); //destructor
		pet_library(int num_of_pets);

		void welcome(); //Welcome user.
		void read(); //Read in pet's information.
		void write(); //Write out to external file.
		int display_options(); //Display all 4 options.
		int how_many();
		void read_file(); //Read in information from external file.
		void search(); //Search library for a certain pet.

	private:
		pet *array;
		int size_array;
		int num_of_pets;
};
