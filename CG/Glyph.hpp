#ifndef __GLYPH_HPP__
#define __GLYPH_HPP__

#define GLYPH_WIDTH 5
#define GLYPH_HEIGHT 6

#include <iostream>
#include <initializer_list>
#include <vector>

namespace CG {
    class Glyph {
    public:
        std::vector<std::vector<int>> data;
        Glyph() : data{ {0} }, width(GLYPH_WIDTH), height(GLYPH_HEIGHT) {}
        Glyph(std::initializer_list<std::vector<int>> list) : data(list), width(GLYPH_WIDTH), height(GLYPH_HEIGHT)
        {
            if (static_cast<int>(data.size()) > height) {
                std::cerr << "ERROR: incorrect number of rows in CG::GLYPH initializer_list\n";
                exit(1);
                }
            if (static_cast<int>(data[0].size()) > width) {
                std::cerr << "ERROR: incorrect number of cols in CG::GLYPH initializer_list\n";
                exit(1);
            }
        }
        int width;
        int height;
        const std::vector<int>& operator[](int col) 
        {
            if(col  < 0 || col >= height) {
                std::cerr << "ERROR: CG::Glyphs::glyphs col "<< col << " Out of range\n"; 
                exit(1);
            }
            return data[col];
        }
    };

    static class Glyphs {
    public:
        static std::vector<Glyph> glyphs;
        const Glyph& operator[](char character) const
        {
            int index = character - 32;
            if(index  < 0 || index >= 96) {
                std::cerr << "ERROR: CG::Glyphs::glyphs index "<<  index << " Out of range\n"; 
                exit(1);
            }
            return glyphs[character - 32];
        }
        
        static const Glyphs& Get();
    } S_Glyphs;
};
#endif //   __GLYPH_HPP__

///////////////////////////////// STATIC DECLARATIONS ///////////////////////////////////
const CG::Glyphs& CG::Glyphs::Get() { return S_Glyphs; } 

std::vector<CG::Glyph> CG::Glyphs::glyphs = {
//////          ' ', !, ", #, $, %, &, ', (, ), *, +, ",", -, ., /      /////////
    CG::Glyph() = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(),
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), 
//////               0, 1, 2, 3, 4, 5, 6, 7, 8, 9                       /////////
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), 
//////                   :, ;, <, =, >, ?, @                            /////////
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), 
//////          A, B, C, D, E, F, G, H, I ,J, K, L, M, N, O             /////////
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), 
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), 
//////          P, Q, R, S, T, U, V, W, X, Y, Z                         /////////
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(),
    CG::Glyph(),
//////                  [,\, ], ^, _, `                                 /////////
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(),
//////      a, b, c, d, e, f, g, h, i ,j, k, l, m, n, o                 /////////

    CG::Glyph() = {
            {0, 1, 1, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {1, 0, 0, 1, 0},
            {1, 0, 0, 1, 0},
            {0, 1, 1, 0, 0}
        },
    CG::Glyph() = {
            {1, 0, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 1, 0, 0},
            {1, 0, 0, 1, 0},
            {1, 0, 0, 1, 0},
            {0, 1, 1, 0, 0},
        },
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(),
    CG::Glyph(), CG::Glyph(), CG::Glyph(),
//////      p, q, r, s, t, u, v, w, x, y, z                             /////////
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(),
    CG::Glyph(),
//////      {, |, }, ~                                                  /////////
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph()
};

//  End of STATIC IMPLEMENTATION