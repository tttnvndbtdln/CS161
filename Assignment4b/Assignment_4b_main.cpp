 #include "Assignment_4b.h"

//Phuong Pham
//CS162
//Program 4
//

int main()
{
	int TEMP = 0, num = 0; //Temporary variable to hold result of display_options.
	//pet_library dog; //Creating a variable for the data type pet_library.

	cout << "How many pets are there? ";
	cin >> num;
	cin.ignore(100,'\n');
	
	pet_library dog(num);
	
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
			//dog.search();
			dog.read_and_store();

		else if (TEMP == 3)
			dog.read_file();

	} while (TEMP != 4);

	return 0;
}
