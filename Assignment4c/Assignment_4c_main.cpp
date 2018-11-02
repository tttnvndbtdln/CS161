#include "Assignment_4c.h"

//Phuong Pham
//CS162
//Program 4
//

int main()
{
	int TEMP = 0; //Temporary variable to hold result of display_options.

	pet_library dog;

	dog.welcome();

	pet * pointer = new pet[PET];
	
	do
	{
		dog.read_and_store();

		TEMP = dog.display_options();
		if (TEMP == 1)
		{
			dog.read();
			dog.write();
		}

		else if (TEMP == 2)
			dog.search();

		else if (TEMP == 3)
			dog.out_from_class();

	} while (TEMP != 4);

	return 0;
}
