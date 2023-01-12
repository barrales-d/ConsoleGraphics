#include <iostream>

#include "CG/CG_Image.hpp"
#include "CG/ColorCodes.hpp"
#include "TestCase.hpp"

int main() {
  {
    TestCase test("Constructor");

    CG_Image base_image(TEST_WIDTH, TEST_HEIGHT);
    test.runTest(base_image, []() {
      CG_Image result(TEST_WIDTH, TEST_HEIGHT);
      return result;
    });
  }
  {
    TestCase test("Constructor with wrong height");

    CG_Image base_image(TEST_WIDTH, TEST_HEIGHT);
    test.runTest(base_image, []() {
      CG_Image result(TEST_WIDTH, 5);
      return result;
    });
    test.expectFailure();
  }
  {
    TestCase test("Constructor with wrong width");

    CG_Image base_image(TEST_WIDTH, TEST_HEIGHT);
    test.runTest(base_image, []() {
      CG_Image result(3, TEST_HEIGHT);
      return result;
    });
    test.expectFailure();
  }
  {
    TestCase test("Constructor default fill background");

    CG_Image base_image(TEST_WIDTH, TEST_HEIGHT);
    base_image.fill_background(ColorCodes::bg_DarkGrey);

    test.runTest(base_image, []() {
      CG_Image result(TEST_WIDTH, TEST_HEIGHT);
      return result;
    });
  }
  {
    TestCase test("CG_Image::fillbackground(Blue)");

    CG_Image base_image(TEST_WIDTH, TEST_HEIGHT);
    base_image.fill_background(ColorCodes::bg_Blue);
    test.runTest(base_image, []() {
      CG_Image result(TEST_WIDTH, TEST_HEIGHT);
      result.fill_background(ColorCodes::bg_Blue);
      return result;
    });
  }

  if (TestCase::s_passed == TestCase::s_total) {
    std::cout << ColorCodes::fg_Green;
  } else {
    std::cout << ColorCodes::fg_Red;
  }
  std::cout << TestCase::s_passed << " out of " << TestCase::s_total
            << " PASSED!\n";
  std::cout << ColorCodes::Reset;
  return 0;
}