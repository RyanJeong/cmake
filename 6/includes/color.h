#ifndef __COLOR_H__
#define __COLOR_H__

#include <string>

class Color {
    std::string color_;
public:
    Color(std::string color);
    std::string get_color() const;
};

#endif