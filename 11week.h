#ifndef week11
#define week11
#include <bits/stdc++.h>

class point{
    float x, y;
 public:
    point(float desired_x, float desired_y);
    ~point();
    void set_x(float desired_x);
    void set_y(float desired_y);
    void set_both(float desired_x, float desired_y);
    float get_x();
    float get_y();
};
class figure{
 protected:
    point position;
 public:
    figure(float x, float y);
    point get();
    void set(point desired_position);
    void print();
    virtual ~figure();
};
class circle : public figure{
 protected:
    float radius;
 public:
    circle(float x, float y, float);
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
    ellipse(float x, float y, float r, float r2);
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
 protected:
    float side;
 public:
    square(float x, float y, float desired_side);
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
    rectangle(float x, float y, float desired_side, float desired_another_side);
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

#endif // week11