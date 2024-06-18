#include <iostream>
#include <vector>

int main(){
  
  //init requires data type in <> name, size not required because it dyanmic
  std::vector<int> vecT; // or you can = 0,1,2,3};
  vecT = { 0, 1, 2, 3};
  //access an element of a vector using the .at() func with the index
  std::cout << vecT.at(3);
  vecT.at(3) = 2;
  std::cout << vecT.at(3);
  

  return 0;
}
