#include <iostream>

#include "CG/CG_Image.hpp"
#include "CG/ColorCodes.hpp"
#include "TestCase.hpp"

int main() {
  TestCase test1("background color");
  TestCase test2("width and height");

  std::cout << "Total number of tests: " << TestCase::s_total << '\n';
  return 0;
}