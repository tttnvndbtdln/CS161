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

int main()
{
	char response = 'N';
	
	do
	{
		pet_library dog;
	
		node * head = NULL;
		
		dog.welcome();
		dog.read_in();
		dog.build(head);
		dog.display_all(head);
	
		cout << "Do you want to do this again (Y/N)? ";
		cin >> response;
		cin.ignore(100,'\n');
		response = toupper(response);
		
	} while ((response) == 'Y');
	
	return 0;
}