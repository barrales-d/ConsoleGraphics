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
* Download the `./CI/` folder to your project directory
* `#include` both .hpp files into the files you want to use it
1. Create an Image object with the Width and Height of the canvas you want
    `Image myImage(WIDTH, HEIGHT);`
2. Use the functions the Image Class has to create your shapes 
3. Remember to use the `show()` function after everything to show your image
    `myImage.show();`

## Examples
### `all();` 
![All shapes in one](./ExampleImages/all.png)

### `triangle();` 
![Triangle](./ExampleImages/triangle.png)

### `checker();` 
![checker pattern](./ExampleImages/checkered.png)
