#include <iostream>

#include "shape.h"

int main(void)
{
    Rectangle r(5,6);
    std::cout << "Rectangle r's size: " << r.get_size() << std::endl;

    return 0;
}