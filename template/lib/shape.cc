#include "shape.h"
#include "hello.h"

Rectangle::Rectangle(int width, int height) : width_(width), height_(height) { }

int Rectangle::get_size() const
{
    lib_hello();

    return width_*height_;
}