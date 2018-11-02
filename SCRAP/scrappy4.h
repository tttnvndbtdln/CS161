#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

struct video
{
	int length; 
};

class video_library
{
	public:
	video_library();
	void read();
	void display();
	
	private:
	video library[2];
	int length;
};