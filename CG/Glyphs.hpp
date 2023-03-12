#ifndef __Alphabet_HPP__
#define __Alphabet_HPP__

namespace CG {
    #define GLYPH_WIDTH 5
    #define GLYPH_HEIGHT 5
    
    struct Glyph {
        int data[GLYPH_WIDTH][GLYPH_HEIGHT];
        static int width;
        static int height;
    };

    static struct Glyphs {
        static Glyph glyphs[96];
        Glyph operator[](char character) const
        {
            return glyphs[character - 32];
        }
    } Glyphs;
};
#endif //   __Alphabet_HPP__
