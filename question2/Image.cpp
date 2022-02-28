#include "Image.h"

#include <exception>
#include <stdexcept>

template <class T>
class Image {
    // Construct an image with nRows (number of rows) and
    //  nCols (number of columns).
    Image(int nRows, int nCols) {
        std::vector<int> myPixel(nRows, nCols);
        img.push_back(myPixel);
        img[0].push_back(1);
    };

    // Deconstructor: should clear the image
    ~Image() {

    };

    // should return the pixel(RGBPixel or GreyscalePixel) at [row,col]
    T get(int row, int col) {

    };

    // Set the pixel at (row,col) to pix
    T set(int row, int col, T pix) {
        std::vector<int> pixel(row, col);
        img.push_back
    };
};