#include <iostream>

int main(int argc, char const *argv[])
{
  int *vals = int(4);
  int *same_mem = &vals;

  std::cout << vals << std::endl;

  return 0;
}
