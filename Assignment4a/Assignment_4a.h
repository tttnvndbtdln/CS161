#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

//Phuong Pham
//CS162
//Program 4

//Constants to hold size of the arrays containing certain information about the pet.
const int NAME = 31;
const int BREED = 51;
const int ANIMAL_FRIENDLY = 51;
const int KID_FRIENDLY = 51;
const int BEHAVIOR = 101;
const int PET = 100;

//External file to write out.
const char outfile[] = "animal.txt";

struct pet
{
	char name[NAME];
	int age;
	int weight;
	char breed[BREED];
	char animal_friendly[ANIMAL_FRIENDLY];
	char kid_friendly[KID_FRIENDLY];
	char behavior[BEHAVIOR];
};

//Class Interface.
class pet_library
{
	public:
		pet_library(); //constructor

		void welcome(); //Welcome user.
		void read(); //Read in pet's information.
		void write(); //Write out to external file.
		int display_options(); //Display all 4 options.
		void search(); //Search library for a certain pet.
		void read_and_store();
		void out_from_class();

	private:
		pet library[PET];
		int num_of_pets;
};
