#include <exception>
#include <stdexcept>
#include "RGBPixel.h"
#include <iostream>

// Construct a RGBPixel with all channels initialized to 0
RGBPixel::RGBPixel() {
    new RGBPixel(0,0,0);
};

// Construct a RGBPixel with all channels initialized to r,g,b
RGBPixel::RGBPixel(unsigned int r, unsigned int g, unsigned int b) : 
                                        r(r), g(g), b(b){};

//Deconstructor
RGBPixel::~RGBPixel() {

};

// Return the brightness of a pixel
// brigtness for RGBPixel = (r + g + b)/3
unsigned int RGBPixel::getBrightness() const {
    unsigned int red = r;
    unsigned int green = g;
    unsigned int blue = b;

    unsigned int brightness = (red+green+blue)/3;
    return brightness;
};

// Should return a reference to the correspoinding 
// channel value of the pixel
// 'r' <- red channel
// 'g' <- green channel
// 'b' <- blue channel
unsigned int& RGBPixel::operator[](const char channel) {
    if(channel == 'r') {return r;}
    if(channel == 'g') {return g;}
    if(channel == 'b') {return b;}
};