#include "GreyscalePixel.h"
#include <exception>
#include <stdexcept>

// Construct a GreyscalePixel with intensity channels initialized to 0
GreyscalePixel::GreyscalePixel() {
    // intensity = 0;
    new GreyscalePixel(0);
};

// Construct a GreyscalePixel with intensity channels 
// initialized to intensity
GreyscalePixel::GreyscalePixel(unsigned int intensity) : intensity(intensity) {
};

//Deconstructor
GreyscalePixel::~GreyscalePixel() {
    
};

// Return the brightness of a pixel
// brigtness for GreyscalePixel = intensity
unsigned int GreyscalePixel::getBrightness() const {
    return intensity;
};

// Should return a reference to the correspoinding 
// channel value of the pixel
// 'i' <- intensity
unsigned int& GreyscalePixel::operator[](const char channel) {
    return channel[&intensity];
};