#include "scrappy4.h"

video_library::video_library()
{
	length = 0;
}

void video_library::read()
{
	int length = 0;
	for (int i = 0; i < 2; ++i) {
	cout << "Enter length: ";
	cin >> library[i].length;
	cin.ignore(100,'\n'); }
}

void video_library::display()
{
	for (int i = 0; i < 2; ++i)
	{
		cout << library[i].length << endl;
		//cout << length << endl;
	}
}