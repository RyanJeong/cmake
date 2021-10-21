#include <iostream>

#include "shape.h"

int main(void)
{
    Rectangle r(3,4);
    int sz = r.get_size();
    std::cout << "Rectangle r's size: " << sz << std::endl;

    return 0;
}