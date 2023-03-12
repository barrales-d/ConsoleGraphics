
#include "Glyphs.hpp"

int CG::Glyph::width =  GLYPH_WIDTH;
int CG::Glyph::height = GLYPH_HEIGHT;

CG::Glyph CG::Glyphs::glyphs[96] = {
//////          ' ', !, ", #, $, %, &, ', (, ), *, +, ",", -, ., /      /////////
    CG::Glyph() = {
        .data = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        }
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
        .data = {
            {0, 1, 1, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {1, 0, 0, 1, 0},
            {0, 1, 1, 0, 0}
        }
    },
    CG::Glyph() = {
        .data = {
            {1, 0, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 1, 0, 0},
            {1, 0, 0, 1, 0},
            {0, 1, 1, 0, 0},
        }
    },
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(),
    CG::Glyph(), CG::Glyph(), CG::Glyph(),
//////      p, q, r, s, t, u, v, w, x, y, z                             /////////
 
    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph(),
    CG::Glyph(),
//////      {, |, }, ~                                                  /////////

    CG::Glyph(), CG::Glyph(), CG::Glyph(), CG::Glyph()
};


