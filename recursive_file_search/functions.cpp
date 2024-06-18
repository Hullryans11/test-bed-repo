#include <iostream>


//Function baiscs
//Void is the return type of the function
void print_hello(){
  std::cout << "Hello" << std::endl;
}

//Paaaments in a function, must be type delcared
void say_hello_un(std::string userName){
  std::cout << userName << std::endl;
  
}

//funct with a parameter and return type
int sum(int a, int b){
  return a + b;
}

int main(){
  int a = 3;
  int b = 4;
  
  print_hello();
  say_hello_un("ryan");
  std:cout << a << " + " << b << " = ' << sum << std:endl;


  return 0;
}

