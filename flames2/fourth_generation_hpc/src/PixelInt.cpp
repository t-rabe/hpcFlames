#include "../headers/PixelInt.hpp"

// NOTE: CHANGE r,g,b VALUES TO SET BACKGROUND COLOR
// e.g. r,g,b = 10 (vals get divided by 10) makes background white
PixelInt::PixelInt() {
    this->r = 1;
    this->g = 4;
    this->b = 0;
    this->a = 1;
}