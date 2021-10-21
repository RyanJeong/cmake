#ifndef __SHAPE_H__
#define __SHAPE_H__

class Rectangle {
    int width_, height_;
public:
    Rectangle(int width, int height);
    int get_size() const;
};

#endif