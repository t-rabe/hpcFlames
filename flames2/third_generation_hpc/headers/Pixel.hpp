#ifndef PIXEL_H
#define PIXEL_H

struct Pixel {
  float r, g, b, a;
  Pixel(); // pass in default constructor
	~Pixel() = default;
};

#endif