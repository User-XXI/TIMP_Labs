#include <iostream>


#include <string>



int main(int argc, char** argv)
{
  std::string name;
  std::cout << "Input user_name";
  std::cin >> name;
  std::cout << "Hello world from " << name << std::endl;
  return 0;
}

