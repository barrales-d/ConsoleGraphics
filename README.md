# ConsoleGraphics

Mini 2D graphics library in C++ for the console / terminal.

Create drawings in the console
	- Rectangles / Squares
	- Circles / Ellipses
	- Lines
	- Triangles with 1 color or interpolate with 3 colors using barycentric coordinates!
	- Text rendering using a minecraft style Font

## Simple program example: 
```cpp
#include "CG.h"
using namespace CG;

#define WIDTH 20
#define HEIGHT 20
int main() {
	Image image(WIDTH, HEIGHT);
	image.fill_background(Colors::black);
	image.fill_rect(-9, -9, 15, 15, Color(0xFFFFFF00));
	image.fill_rect(1, 1, 11, 20, Color(255, 20, 20, 128));
	image.fill_triangle(20, 0, 10, 10, 20, 20, Colors::red, Colors::green, Colors::blue);
	image.show();

    return 0;
}
```

## References: 
### For color codes and terminal manipulation:
- https://www.2daygeek.com/understanding-the-color-code-of-linux-files/
- https://web.archive.org/web/20151004211730/http://www.termsys.demon.co.uk/vtansi.htm/

### For saving png images:
- https://github.com/nothings/stb

## [Console Graphic Examples Website](https://barrales-d.github.io/ConsoleGraphics/)
