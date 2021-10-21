#include <fmt/core.h>

#include <iostream>
#include <string>

#include "shape.h"
#include "color.h"

int main(void)
{
    Rectangle r(4,7);
    int sz = r.get_size();
//  std::cout << "Rectangle r's size: " << sz << std::endl;
    fmt::print("Rectangle r's size: {} \n", sz);

    Color c("RED");
    std::string color = c.get_color();
//  std::cout << "Color: " << color << std::endl;
    fmt::print("Color: {} \n", color);

    return 0;
}