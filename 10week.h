#ifndef week10
#define week10
#include <bits/stdc++.h>

class point{
    int x, y;
 public:
    point(int desired_x, int desired_y);
    ~point();
    void set_x(int desired_x);
    void set_y(int desired_y);
    void set_both(int desired_x, int desired_y);
    int get_x();
    int get_y();
};
class figure{
 protected:
    point position;
 public:
    figure(int x, int y);
    point get();
    void set(point desired_position);
    void print();
    ~figure();
};
class circle : public figure{
    float radius;
 public:
    circle(int x, int y, float);
    float get_radius();
    point get_position();
    void set_radius(float desired_radius);
    void set_position(point desired_position);
    float area();
    float circumference();
    void print();
    ~circle();
}; 
class ellipse : public circle{
    float second_axis;
 public:
    ellipse(int x, int y, float r, float r2);
    float get_minor_axis();
    float get_major_axis();
    point get_position();
    void set_both_axis(float desired_min_axis, float desired_maj_axis);
    void set_position(point desired_position);
    float area();
    float circumference();
    void print();
    ~ellipse();
};
class square : public figure {
    float side;
 public:
    square(int x, int y, float desired_side);
    float get_side();
    point get_position();
    void set_side(float desired_side);
    void set_position(point desired_point);
    float area();
    float circumference();
    void print();
    ~square();
};
class rectangle : public square {
    float another_side;
 public:
    rectangle(int x, int y, float desired_side, float desired_another_side);
    float get_longer_side();
    float get_shorter_side();
    point get_position();
    void set_both_sides(float desired_side, float desired_another_side);
    void set_position(point desired_point);
    float area();
    float circumference();
    void print();
    ~rectangle();
};

#endif // week10