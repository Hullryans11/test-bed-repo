#include <iostream>
#include <vector>

int main(){
  int a = 10
  //init requires data type in <> name, size not required because it dyanmic
  std::vector<int> vecT; // or you can = 0,1,2,3};
  vecT = { 0, 1, 2, 3};
  //access an element of a vector using the .at() func with the index
  std::cout << vecT.at(3);
  vecT.at(3) = 2;
  std::cout << vecT.at(3);

  //show size
  std::cout << vecT.size();

  // add an elemnt to the end
  vecT.push_back(a);
  //insert an element insert()
  //remove last element = .pop_back()
  //remove a specified element or range based on index .erase(va or .erase(index, index+4)
  
  
  

  return 0;
}
