#include <iostream>

#include "../CG/Image.hpp"
#include "../CG/Color.hpp"
#include "./TestCase.hpp"

int main() {
  //  TODO: create TESTCASE::load_image and TESTCASE::save_image when I introduce stb::load/write_image
  //    use them to compare test images saved in png format 
  { 
    TESTCASE::createTest("Constructor");
    CG::Image base_image(TESTCASE::width, TESTCASE::height);

    TESTCASE::assertEqual(base_image, CG::Image(TESTCASE::width, TESTCASE::height));
  }
/////////////////////////////////////////////////////////////////////////////////////
  { 
    TESTCASE::createTest("Constructor with wrong height");
    CG::Image base_image(TESTCASE::width, TESTCASE::height);

    TESTCASE::assertNotEqual(base_image, CG::Image(TESTCASE::width, 5));
  }
/////////////////////////////////////////////////////////////////////////////////////
  {
    TESTCASE::createTest("Constructor with wrong width");
    CG::Image base_image(TESTCASE::width, TESTCASE::height);

    TESTCASE::assertNotEqual(base_image, CG::Image(3, TESTCASE::height));
  }
/////////////////////////////////////////////////////////////////////////////////////
  {
    TESTCASE::createTest("Constructor default fill background");

    CG::Image base_image(TESTCASE::width, TESTCASE::height);
    base_image.fill_background(CG::Color::darkgrey);

    TESTCASE::assertEqual(base_image,CG::Image(TESTCASE::width, TESTCASE::height));
  }
/////////////////////////////////////////////////////////////////////////////////////
  {
    TESTCASE::createTest("CG::Image::fill_background(CG::Color::blue)");

    CG::Image base_image(TESTCASE::width, TESTCASE::height);
    base_image.fill_background(CG::Color::blue);

    CG::Image result_image(TESTCASE::width, TESTCASE::height);
    result_image.fill_background(CG::Color::blue);

    TESTCASE::assertEqual(base_image, result_image);
  }
/////////////////////////////////////////////////////////////////////////////////////
  {
    TESTCASE::createTest("fill_rect() matching");

    CG::Image base_image(TESTCASE::width, TESTCASE::height);
    int wd = TESTCASE::width / 5;
    int x = TESTCASE::width / 2 - wd;
    int ht = TESTCASE::height / 5;
    int y = TESTCASE::height / 2 - ht;
    base_image.fill_rect(x, y, wd, ht, CG::Color::red);

    CG::Image result_image(TESTCASE::width, TESTCASE::height);
    result_image.fill_rect(3, 3, 2, 2, CG::Color::red);

    TESTCASE::assertEqual(base_image, result_image);
  }
/////////////////////////////////////////////////////////////////////////////////////
  {
    TESTCASE::createTest("fill_rect() Don't Match");

    
    CG::Image base_image(TESTCASE::width, TESTCASE::height);
    int wd = TESTCASE::width / 2;
    int x = TESTCASE::width / 2 - wd;
    int ht = TESTCASE::width / 5;
    int y = TESTCASE::height / 2 - ht;
    base_image.fill_rect(x, y, wd, ht, CG::Color::red);

    CG::Image result_image(TESTCASE::width, TESTCASE::height);
    result_image.fill_rect(3, 3, 2, 2, CG::Color::red);

    TESTCASE::assertNotEqual(result_image, base_image);
  }
/////////////////////////////////////////////////////////////////////////////////////
  {
    TESTCASE::createTest("fill_circle()");
    
    CG::Image base_image(TESTCASE::width, TESTCASE::height);
    int x = TESTCASE::width / 2;
    int y = TESTCASE::height / 2;
    int r = TESTCASE::width / 3;
    base_image.fill_circle(x, y, r, CG::Color::cyan);

    CG::Image result_image(TESTCASE::width, TESTCASE::height);
    result_image.fill_circle(5, 5, 3, CG::Color::cyan);

    TESTCASE::assertEqual(base_image, result_image);   
  }
/////////////////////////////////////////////////////////////////////////////////////
  {
    TESTCASE::createTest("fill_triangle()");

    CG::Image base_image(TESTCASE::width, TESTCASE::height);
    int x1 = TESTCASE::width / 2, y1 = 0;
    int x2 = TESTCASE::width / 7, y2 = TESTCASE::height / 4;
    int x3 = TESTCASE::width - 3, y3 = TESTCASE::height / 4;
    base_image.fill_triangle(x1, y1,x2, y2, x3, y3, CG::Color::green);

    CG::Image result_image(TESTCASE::width, TESTCASE::height);
    result_image.fill_triangle(5, 0, 1, 3, 7, 3, CG::Color::green);

    TESTCASE::assertEqual(base_image, result_image);
  }
/////////////////////////////////////////////////////////////////////////////////////

  TESTCASE::summarizeCases();
  return 0;
}