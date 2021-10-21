#include "shape.h"

Rectangle::Rectangle(int width, int height) : width_(width), height_(height) { }

int Rectangle::get_size() const
{

    return width_*height_;
}
