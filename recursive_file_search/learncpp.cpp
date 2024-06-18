//libs...
#include <iostream>


//constants, cant be modified in the future... should be something that sho9uld never be changed, like minutes in an hour or somthing
//Usually declared before any functions in classes and main
const int min_per_hour = 60;


int main()
{
	//int examples rounded positive and neg numbers
	int a = 2;

	//doubles exapmples
	double b;
	b = -35.4;

	//boolean type true ot false, no cap
	bool y;
	y = false;

	//string type C++ only, must use char* array in c
	std::string s;
	s = "string content";

	
	
	
  
  std::cout << "Text" << b << "\n" << y << "\n" << s;
return 0;
}
