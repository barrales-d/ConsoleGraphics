# ConsoleGraphics

Mini 2D graphics library in C++ for the console / terminal in Linux.

It is able to create simple 2D shapes in the console (squares, circles, triangles, and lines). However, it is a little skewed vertically because of the console not 
having a 1:1 ratio.


## Quick Start
```console
$ make build
$ ./main
```
### To use the functions in your projects: 
* Download the `ColorCodes.hpp/.cpp` and the `Image.hpp/.cpp`
* `#include` both .hpp files into the files you want to use it

## Examples
### `all();` 
![All shapes in one](./ExampleImages/all.png)

### `triangle();` 
![Triangle](./ExampleImages/triangle.png)

### `checker();` 
![checker pattern](./ExampleImages/checkered.png)
