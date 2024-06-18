#include <iostream>
#include <vector>

int main(){

// 1.1 Ask for name and ange then output

  //init used vars
  std::string name;
  int age;

  //ask name and recieve input
  std::cout << "\nPlease enter your name: ";
  std::cin >> name;

  //ask age and recive input
  std::cout << "\nPlease enter your age: ";
  std::cin >> age;

  //Print info
  std::cout<< "Your name is " << name << " and your age is " << age << std::endl;
  
//1.2 Ask for two integers, add then print the result

  //Establish var
  int n1;
  int n2;
  //ask uuser for input
  std::cout << "\n for addition:\nPlease enter number 1: ";
  std::cin >> n1;
  std::cout << "\nPlease enter Number 2: ";
  std::cin >> n2;
  
  //math and output
  std::cout << n1 + n2 << std::endl;
  
// recive 4 numbers from user, input into a vector, comput the average and print it (while loop or for loop?)

  std::vector<int> list;

  //loop for receving input
  int input;
  for(int i = 0; i < 4; i++){
    std::cout << "\nPlease enter Number " << i << ": ";
    std::cin >> input;
    list.push_back(input);
  }
//SUMMATION
  int sum;
  for(int i = 0; i < 4; i++){
  sum += list.at(i);
  }
  //math avg and print
  std::cout << std::endl <<  sum / list.size();
  


return 0;
}













