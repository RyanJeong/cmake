#include <iostream>
#include <string>

#include "shape.h"
#include "color.h"

int main(void)
{
    Rectangle r(5,5);
    int sz = r.get_size();
    std::cout << "Rectangle r's size: " << sz << std::endl;

    Color c("RED");
    std::string color = c.get_color();
    std::cout << "Color: " << color << std::endl;

    return 0;
}