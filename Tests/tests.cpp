#include <iostream>

#include "../CG/Image.hpp"
#include "../CG/Color.hpp"
#include "./TestCase.hpp"

int main() {
  //  TODO: create TESTCASE::load_image and TESTCASE::save_image when I introduce stb::load/write_image
  //    use them to compare test images saved in png format 
  { 
    TESTCASE::createTest("Constructor");
    CG::Image base_image(TEST_WIDTH, TEST_HEIGHT);

    TESTCASE::assertEqual(base_image, CG::Image(TEST_WIDTH, TEST_HEIGHT));
  }
/////////////////////////////////////////////////////////////////////////////////////
  { 
    TESTCASE::createTest("Constructor with wrong height");
    CG::Image base_image(TEST_WIDTH, TEST_HEIGHT);

    TESTCASE::assertNotEqual(base_image, CG::Image(TEST_WIDTH, 5));
  }
/////////////////////////////////////////////////////////////////////////////////////
  {
    TESTCASE::createTest("Constructor with wrong width");
    CG::Image base_image(TEST_WIDTH, TEST_HEIGHT);

    TESTCASE::assertNotEqual(base_image, CG::Image(3, TEST_HEIGHT));
  }
/////////////////////////////////////////////////////////////////////////////////////
  {
    TESTCASE::createTest("Constructor default fill background");

    CG::Image base_image(TEST_WIDTH, TEST_HEIGHT);
    base_image.fill_background(CG::Color::darkgrey);

    TESTCASE::assertEqual(base_image,CG::Image(TEST_WIDTH, TEST_HEIGHT));
  }
/////////////////////////////////////////////////////////////////////////////////////
  {
    TESTCASE::createTest("CG::Image::fill_background(CG::Color::blue)");

    CG::Image base_image(TEST_WIDTH, TEST_HEIGHT);
    base_image.fill_background(CG::Color::blue);

    CG::Image result_image(TEST_WIDTH, TEST_HEIGHT);
    result_image.fill_background(CG::Color::blue);

    TESTCASE::assertEqual(base_image, result_image);
  }
/////////////////////////////////////////////////////////////////////////////////////
  {
    TESTCASE::createTest("CG::Image::fill_rect() matching");

    CG::Image base_image(TEST_WIDTH, TEST_HEIGHT);
    base_image.fill_rect(3, 3, 2, 2, CG::Color::red);

    CG::Image result_image(TEST_WIDTH, TEST_HEIGHT);
    int wd = TEST_WIDTH / 5;
    int x = TEST_WIDTH / 2 - wd;
    int ht = TEST_HEIGHT / 5;
    int y = TEST_HEIGHT / 2 - ht;
    result_image.fill_rect(x, y, wd, ht, CG::Color::red);

    TESTCASE::assertEqual(base_image, result_image);
  }
/////////////////////////////////////////////////////////////////////////////////////
  {
    TESTCASE::createTest("CG::Image::fill_rect() Don't Match");

    CG::Image base_image(TEST_WIDTH, TEST_HEIGHT);
    base_image.fill_rect(3, 3, 2, 2, CG::Color::red);

    CG::Image result_image(TEST_WIDTH, TEST_HEIGHT);
    int wd = TEST_WIDTH / 2;
    int x = TEST_WIDTH / 2 - wd;
    int ht = TEST_WIDTH / 5;
    int y = TEST_HEIGHT / 2 - ht;
    result_image.fill_rect(x, y, wd, ht, CG::Color::red);

    TESTCASE::assertNotEqual(base_image, result_image);
  }
/////////////////////////////////////////////////////////////////////////////////////

  TESTCASE::summarizeCases();
  return 0;
}