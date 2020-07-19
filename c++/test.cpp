#include <iostream>

int main()
{
  int a = 258;
  char* p = (char*)&a; // Make a char*, and force the compiler to treat the address of a as a char pointer.
  for (int i =0;i<4;i++)
    {std::cout << (int)(*p) << std::endl; p++;} // Cycle through the 4 bytes of the int, outputting each byte as if it were an int
  return 0;
}
