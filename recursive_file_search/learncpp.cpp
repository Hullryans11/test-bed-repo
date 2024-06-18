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

	//Arrays must be init with a fioxed size or with the compnents

	double temp[4];
	//or
	int temp2[4] = { 0, 1, 2, 3};
	//modifiy array like normal by index
	temp2[3] = 3;
	
	//vectors!!! in stad C== library bsically a dynamic array implimentation in the STD library
	//# include <vector>
	
	

	
	
	
  
  std::cout << "Text" << b << "\n" << y << "\n" << s;
return 0;
}
