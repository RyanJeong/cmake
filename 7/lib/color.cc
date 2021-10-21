#include <string>

#include "color.h"

Color::Color(std::string color) : color_(color) { }

std::string Color::get_color() const
{
    
    return color_;
}