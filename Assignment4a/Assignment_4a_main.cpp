 #include "Assignment_4a.h"

//Phuong Pham
//CS162
//Program 4

int main()
{
	int TEMP = 0; //Temporary variable to hold result of display_options.
	pet_library dog; //Creating a variable for the data type pet_library.

	dog.welcome();

	do
	{
		TEMP = dog.display_options();
		if (TEMP == 1)
		{
			dog.read();
			dog.write();
		}

		else if (TEMP == 2)
		{
			dog.search();
		}

		else if (TEMP == 3)
		{
			dog.read_and_store();
			dog.out_from_class();
		}

	} while (TEMP != 4);

	return 0;
}
