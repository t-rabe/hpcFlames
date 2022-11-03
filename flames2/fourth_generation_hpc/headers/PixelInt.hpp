#ifndef PIXELINT_H
#define PIXELINT_H

struct PixelInt {
    int r, g, b, a;
    PixelInt(); // pass in default constructor
    ~PixelInt() = default;
};

#endif