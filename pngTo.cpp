#include "./CG/Color.hpp"
#include "./CG/Image.hpp"

#include <iostream>
#include <fstream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "./Others/stb_image.h"

std::string uppercase(const std::string& s)
{
    std::string result = "";
    for(char x : s) result += std::toupper(x);
    return result;
}

int main(int argsc, char** argsv) {
    std::string png_file_name;
    std::string output_name = "image";

    if(argsc < 2) {
        std::cerr << ansi_code::foreground(CG::Color::red);
        std::cerr << "ERROR: No png file provided!\n";
        std::cerr << "Usage: pngTo [png file name] [output name for pixels array = 'image' default]\n\n";
        std::cerr << ansi_code::reset;
        return 1;
    }
    argsv++;
    png_file_name = std::string(*argsv++);
    std::cout << "Loading " << png_file_name << "\n";
    if(*argsv) {
        output_name = std::string(*argsv++);
        std::cout << "Creating " << output_name << ".cpp\n";
    }

    int width = 0, height = 0, n = 0;
    uint32_t *png_pixels = (uint32_t *)stbi_load(png_file_name.c_str(), &width, &height, &n, 0);
    if(png_pixels == nullptr) {
        std::cerr << ansi_code::foreground(CG::Color::red);
        std::cerr << "ERROR: Could not read file into memory!\n";
        std::cerr << ansi_code::reset;
        return 1;
    }

    //          rotates the bits so AA channel is put at the end and >> shifted out 
    //  TODO: (((png_pixels[index] << 8)|(png_pixels[index] >> 24)) >> 8) belongs in CG image or color
    //      like this pngtocpp only outputs 4 components 0xAABBGGRR

    std::string output_file_name = output_name + ".cpp";
    std::fstream file_out = std::fstream(output_file_name, std::ios::out); 
    if(!file_out.is_open()) {
        std::cerr << ansi_code::foreground(CG::Color::red);
        std::cerr << "ERROR: couldn't open file\n";
        std::cerr << ansi_code::reset;
        return 1;
    }
    std::string upper = uppercase(output_name);
    file_out << "#ifndef __" + upper + "_PIXELS_CPP__\n";
    file_out << "#define __" + upper + "_PIXELS_CPP__\n\n";
    file_out << "#include <stdint.h>\n\n";
    file_out << "const int " + output_name + "_width = " << width << ";\n";
    file_out << "const int " + output_name + "_height = " << height << ";\n";
    file_out << "uint32_t " + output_name + "_pixels[] = { \n";


    for (int i = 0; i < height; i++) {
        file_out << "\t";
        for (int j = 0; j < width; j++)
        {
            int index = i * width + j;
            file_out << std::hex << "0x" << png_pixels[index];
            if(index < width*height - 1) {
                file_out << ", ";
            }
        }
        file_out << "\n";
    }
    file_out << "};\n";

    file_out << "#endif // __" + upper + "_PIXELS_CPP__";

    file_out.close();
    std::cout << "Done\n";
    delete [] png_pixels;
    return 0;
}