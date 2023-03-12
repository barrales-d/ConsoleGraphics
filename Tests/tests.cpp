#include <iostream>

#include "../CG/Image.hpp"
#include "../CG/Color.hpp"
#include "./TestCase.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../Others/stb_image.h"

void print_help();

int main(int argc, char** argv) {
    //  TODO: Allow command line to have test case names to run/update/print specific ones
    bool record = false;
    uint32_t *png_pixels = nullptr;

    TESTCASE::print = false;

    if(argc < 2) {
        std::cout << "ERROR: command not provided\n";
        print_help();
        return 1;
    }
    std::string command = argv[1];
    if(command == "-r") {}
    else if (command == "-u") {
        record = true;
    }else if(command == "-p") {
        TESTCASE::print = true;
    } else {
        std::cerr << "ERROR: unknown command\n";
        print_help();
        return 1;
    }

    { 
        TESTCASE::createTest("Constructor and Copy Constructor");
        CG::Image base_image(TESTCASE::width, TESTCASE::height);
        CG::Image copied_image(base_image);

        TESTCASE::assertEqual(base_image, CG::Image(TESTCASE::width, TESTCASE::height));
        TESTCASE::assertEqual(base_image, copied_image);
    }
    /////////////////////////////////////////////////////////////////////////////////////
    {
        TESTCASE::createTest("CG::Image CG::Color* Constructor");
        const int wd = 2;
        const int ht = 2;
        CG::Image base_image(wd, ht);
        base_image.fill_background(CG::Color::red);

        CG::Color pixels[wd * ht] = {
        CG::Color(0x0000FF), CG::Color(0x0000FF),
        CG::Color(0x0000FF), CG::Color(0x0000FF)
        };

        TESTCASE::assertEqual(base_image, CG::Image(pixels, wd, ht));
    }
    /////////////////////////////////////////////////////////////////////////////////////
    {
        TESTCASE::createTest("CG::Image uint32_t* Constructor");
        const int wd = 2;
        const int ht = 2;
        CG::Image base_image(wd, ht);
        base_image.fill_background(CG::Color::blue);

        uint32_t pixels[wd * ht] = {
        0xFF0000, 0xFF0000,
        0xFF0000, 0xFF0000
        };

        TESTCASE::assertEqual(base_image, CG::Image(pixels, wd, ht));
    }
    /////////////////////////////////////////////////////////////////////////////////////
    { 
        TESTCASE::createTest("Constructor with wrong height");
        CG::Image height_image(TESTCASE::width, 5);

        TESTCASE::assertAnyNotEqual<int>(height_image.get_height(), TESTCASE::height + 1);
        TESTCASE::assertNotEqual(height_image, CG::Image(TESTCASE::width, TESTCASE::height));

        CG::Image width_image(3, TESTCASE::height);

        TESTCASE::assertAnyNotEqual<int>(height_image.get_width(), TESTCASE::width * WIDTH_SCALER);
        TESTCASE::assertNotEqual(width_image, CG::Image(TESTCASE::width, TESTCASE::height));
    }
    /////////////////////////////////////////////////////////////////////////////////////
    {
        TESTCASE::createTest("Constructor default fill background");

        std::string file_name = "./Tests/Images/fill_background_default.png";
        int width = 0, height = 0, n = 0;
        png_pixels = (uint32_t *)stbi_load(file_name.c_str(), &width, &height, &n, 0);

        CG::Image base_image;

        if(record) {
            base_image = CG::Image(TESTCASE::width, TESTCASE::height);
            base_image.fill_background(CG::Color::darkgrey);
            base_image.save_image(file_name);
        } else {
            base_image = CG::Image(png_pixels, TESTCASE::width, TESTCASE::height);
        }

        TESTCASE::assertEqual(base_image,CG::Image(TESTCASE::width, TESTCASE::height));
    }
    /////////////////////////////////////////////////////////////////////////////////////
    {
        TESTCASE::createTest("get_width()");
        CG::Image base_image(TESTCASE::width, TESTCASE::height);

        TESTCASE::assertAnyEqual<int>(base_image.get_width(), TESTCASE::width * WIDTH_SCALER);
    }
    /////////////////////////////////////////////////////////////////////////////////////
    {
        TESTCASE::createTest("get_height()");
        CG::Image base_image(TESTCASE::width, TESTCASE::height);

        TESTCASE::assertAnyEqual<int>(base_image.get_height(), TESTCASE::height + 1);
    }
    /////////////////////////////////////////////////////////////////////////////////////
    {
        TESTCASE::createTest("get_uint32_pixels()");
        CG::Image base_image(TESTCASE::width, TESTCASE::height);
        base_image.fill_background(CG::Color::green);
        uint32_t *pixels = new uint32_t[TESTCASE::width * TESTCASE::height];
        base_image.get_uint32_pixels(pixels);

        TESTCASE::assertAnyEqual<uint32_t>(pixels[0], 0xFF00FF00);
        TESTCASE::assertAnyEqual<uint32_t>(pixels[TESTCASE::width], 0xFF00FF00);
        TESTCASE::assertAnyEqual<uint32_t>(pixels[TESTCASE::width*TESTCASE::height - 2], 0xFF00FF00);
        delete [] pixels;
    }
    /////////////////////////////////////////////////////////////////////////////////////
    {
        TESTCASE::createTest("fill_background(CG::Color::blue)");

        std::string file_name = "./Tests/Images/fill_background_blue.png";
        int width = 0, height = 0, n = 0;
        png_pixels = (uint32_t *)stbi_load(file_name.c_str(), &width, &height, &n, 0);

        CG::Image base_image;

        if(record) {
            base_image = CG::Image(TESTCASE::width, TESTCASE::height);
            base_image.fill_background(CG::Color::blue);
            base_image.save_image(file_name);
        } else {
            base_image = CG::Image(png_pixels, TESTCASE::width, TESTCASE::height);
        }

        CG::Image result_image(TESTCASE::width, TESTCASE::height);
        result_image.fill_background(CG::Color::blue);

        TESTCASE::assertEqual(base_image, result_image);
    }
    /////////////////////////////////////////////////////////////////////////////////////
    {
        TESTCASE::createTest("fill_rect() Match");

        std::string file_name = "./Tests/Images/fill_rect.png";
        int width = 0, height = 0, n = 0;
        png_pixels = (uint32_t *)stbi_load(file_name.c_str(), &width, &height, &n, 0);

        CG::Image base_image;

        if(record) {
            base_image = CG::Image(TESTCASE::width, TESTCASE::height);
            int wd = TESTCASE::width / 5;
            int x = TESTCASE::width / 2 - wd;
            int ht = TESTCASE::height / 5;
            int y = TESTCASE::height / 2 - ht;
            base_image.fill_rect(x, y, wd, ht, CG::Color::red);
            base_image.save_image(file_name);
        } else {
            base_image = CG::Image(png_pixels, TESTCASE::width, TESTCASE::height);
        }

        CG::Image result_image(TESTCASE::width, TESTCASE::height);
        int wd = TESTCASE::width / 5;
        int x = TESTCASE::width / 2 - wd;
        int ht = TESTCASE::height / 5;
        int y = TESTCASE::height / 2 - ht;
        result_image.fill_rect(x, y, wd, ht, CG::Color::red);

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

        std::string file_name = "./Tests/Images/fill_circle.png";
        int width = 0, height = 0, n = 0;
        png_pixels = (uint32_t *)stbi_load(file_name.c_str(), &width, &height, &n, 0);

        CG::Image base_image;

        if(record) {
            base_image = CG::Image(TESTCASE::width, TESTCASE::height);
            int x = TESTCASE::width / 2;
            int y = TESTCASE::height / 2;
            int r = TESTCASE::width / 3;
            base_image.fill_circle(x, y, r, CG::Color::cyan);
            base_image.save_image(file_name);
        } else {
            base_image = CG::Image(png_pixels, TESTCASE::width, TESTCASE::height);
        }

        CG::Image result_image(TESTCASE::width, TESTCASE::height);
        int x = TESTCASE::width / 2;
        int y = TESTCASE::height / 2;
        int r = TESTCASE::width / 3;
        result_image.fill_circle(x, y, r, CG::Color::cyan);

        TESTCASE::assertEqual(base_image, result_image);   
    }
    /////////////////////////////////////////////////////////////////////////////////////
    {
        TESTCASE::createTest("fill_triangle()");

        std::string file_name = "./Tests/Images/fill_triangle.png";
        int width = 0, height = 0, n = 0;
        png_pixels = (uint32_t *)stbi_load(file_name.c_str(), &width, &height, &n, 0);

        CG::Image base_image;

        if(record) {
            base_image = CG::Image(TESTCASE::width, TESTCASE::height);
            int x1 = TESTCASE::width / 2, y1 = 0;
            int x2 = TESTCASE::width / 7, y2 = TESTCASE::height / 4;
            int x3 = TESTCASE::width - 3, y3 = TESTCASE::height / 4;
            base_image.fill_triangle(x1, y1,x2, y2, x3, y3, CG::Color::green);
            base_image.save_image(file_name);
        } else {
            base_image = CG::Image(png_pixels, TESTCASE::width, TESTCASE::height);
        }

        CG::Image result_image(TESTCASE::width, TESTCASE::height);
        int x1 = TESTCASE::width / 2, y1 = 0;
        int x2 = TESTCASE::width / 7, y2 = TESTCASE::height / 4;
        int x3 = TESTCASE::width - 3, y3 = TESTCASE::height / 4;
        result_image.fill_triangle(x1, y1,x2, y2, x3, y3, CG::Color::green);

        TESTCASE::assertEqual(base_image, result_image);
    }
    /////////////////////////////////////////////////////////////////////////////////////
    {
        TESTCASE::createTest("draw_line()");

        std::string file_name = "./Tests/Images/draw_line.png";
        int width = 0, height = 0, n = 0;
        png_pixels = (uint32_t *)stbi_load(file_name.c_str(), &width, &height, &n, 0);

        CG::Image base_image;
        if(record) {
            base_image = CG::Image(TESTCASE::width, TESTCASE::height);
            base_image.draw_line(0, 0, TESTCASE::width, 0, CG::Color::red);
            base_image.draw_line(0, 0, 0, TESTCASE::height, CG::Color::blue);
            base_image.draw_line(0, 0, TESTCASE::width, TESTCASE::height, CG::Color::lightyellow);
            base_image.draw_line(TESTCASE::width / 2, 0, TESTCASE::width / 2 + 4, TESTCASE::height, CG::Color::magenta);
            base_image.save_image(file_name);
        } else {
            base_image = CG::Image(png_pixels, TESTCASE::width, TESTCASE::height);
        }

        CG::Image result_image(TESTCASE::width, TESTCASE::height);

        result_image.draw_line(0, 0, TESTCASE::width, 0, CG::Color::red);
        result_image.draw_line(0, 0, 0, TESTCASE::height, CG::Color::blue);    
        result_image.draw_line(0, 0, TESTCASE::width, TESTCASE::height, CG::Color::lightyellow);
        result_image.draw_line(5, 0, 9, TESTCASE::height, CG::Color::magenta);

        TESTCASE::assertEqual(base_image, result_image);

    }
    /////////////////////////////////////////////////////////////////////////////////////
    {
        TESTCASE::createTest("Save image to png");
        CG::Image base_image(TESTCASE::width, TESTCASE::height);
        base_image.fill_background(CG::Color::black);
        base_image.fill_rect(TESTCASE::width / 2 - 2, TESTCASE::height / 2 - 2, 4, 4, CG::Color::red);
        int err = base_image.save_image("./Tests/Images/red_square.png");
        TESTCASE::assertAnyNotEqual<int>(err, 0);
    }
    /////////////////////////////////////////////////////////////////////////////////////
    delete [] png_pixels;
    TESTCASE::summarizeCases();
    return 0;
}

void print_help()
{
    std::cout << "Usage: ./tests -[OPTIONS] \n";
    std::cout << "OPTIONS: \n";
    std::cout << "\tr = run tests\n";
    std::cout << "\tu = update tests\n";
    std::cout << "\tp = print tests images\n";
}