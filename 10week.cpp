#include <cmath>
#include <bits/stdc++.h>
#include "10week.h"
using namespace std;
#define PI 3.14159265
// Point functions
point::point(int desired_x, int desired_y){
 x = desired_x;
 y = desired_y;
}
void point::set_x(int desired_x){
    x = desired_x;
}
void point::set_y(int desired_y){
    x = desired_y;
}
void point::set_both(int desired_x, int desired_y){
    x = desired_x;
    y = desired_y;
}
int point::get_x(){
    return x;
}
int point::get_y(){
    return y;
}
point::~point(){
 x = 0;
 y = 0;
}
// Figure functions
figure::figure(int x, int y)
: position(x, y)
{}
point figure::get(){
    return position;
}
void figure::set(point desired_position){
    position = desired_position;
}
void figure::print(){
    cout << "(" << position.get_x() << ";" << position.get_y() << ")" << endl;
}
figure::~figure(){
}
// Circle functions
circle::circle(int x, int y, float r)
   : figure(x,y)
{
    radius = r;
}
float circle::get_radius(){
    return radius;
}
point circle::get_position(){
    return position;
}
void circle::set_radius(float desired_radius){
    radius = desired_radius;
}
void circle::set_position(point desired_position){
    position = desired_position;
}
float circle::area(){
    return PI * radius * radius;
}
float circle::circumference(){
    return 2 * PI * radius;
}
void circle::print(){
    figure::print();
    cout  << "Circle's radius is: " << get_radius() << endl;
    cout  << "Circle's area is: " << area() << endl; 
    cout  << "Circle's circumference is: " << circumference() << endl; 
}
circle::~circle(){
}
// Ellipse functions
ellipse::ellipse(int x, int y, float r, float r2)
: circle(x, y ,r)
{
    second_axis = r2;
}
float ellipse::get_minor_axis(){
    if(second_axis > get_radius()) return get_radius();
    return second_axis;
}
float ellipse::get_major_axis(){
    if(second_axis > get_radius()) return second_axis;
    return get_radius();
}
point ellipse::get_position(){
    return position;
}
void ellipse::set_both_axis(float desired_min_axis, float desired_maj_axis){
    set_radius(desired_min_axis);
    second_axis = desired_maj_axis;
}
void ellipse::set_position(point desired_point){
    position = desired_point;
}
float ellipse::area(){
    return PI * get_radius() * second_axis;
}
float ellipse::circumference(){
    float one_axis = get_radius();
    return PI * (3 * (one_axis + second_axis) - sqrt((3 * one_axis + second_axis) * (one_axis + 3 * second_axis)));
}
void ellipse::print(){
    figure::print();
    cout  << "Ellipse's one axis is:  " << get_radius() << endl;
    cout  << "Ellipse's second axis is: " << second_axis << endl;
    cout  << "Ellipse's area is: " << area() << endl; 
    cout  << "Ellipse's circumference is: " << circumference() << endl;    
}
ellipse::~ellipse(){
}
//Square functions
square::square(int x, int y, float desired_side)
    : figure(x, y)
{
    side = desired_side;
}
float square::get_side(){
    return side;
}
point square::get_position(){
    return position;
}
void square::set_side(float desired_side){
    side = desired_side;
}
void square::set_position(point desired_point){
    position = desired_point;
}
float square::area(){
    return side * side;
}
float square::circumference(){
    return 4 * side;
}
void square::print(){
    figure::print();
    cout << "Square's side length is: " << side << endl;
    cout << "Square's are is: " << area() << endl;
    cout << "Square's circumference is: " << circumference() << endl;
}
square::~square(){
}
//Rectangle functions
rectangle::rectangle(int x, int y, float desired_side, float desired_another_side)
:   square(x, y, desired_side)
{
    another_side = desired_another_side;
}
float rectangle::get_longer_side(){
    if(another_side > get_side()) return another_side;
    return get_side();
}
float rectangle::get_shorter_side(){
    if(another_side < get_side()) return another_side;
    return get_side();    
}
point rectangle::get_position(){
    return position;
}
void rectangle::set_both_sides(float desired_side, float desired_another_side){
    set_side(desired_side);
    another_side = desired_another_side;
}
void rectangle::set_position(point desired_point){
    position = desired_point;
}
float rectangle::area(){
    return get_side() * another_side;
}
float rectangle::circumference(){
    return get_side() * 2 + another_side * 2;
}
void rectangle::print(){
    figure::print();
    cout << "The shorter side of the rectangle is: " << get_shorter_side() << " ,the longer side is: " << get_longer_side() << endl;
    cout << "The area of the rectangle is: " << area() << endl;
    cout << "The circumference of the rectangle is: " << circumference() << endl;
}
rectangle::~rectangle(){
}
// Main function(for testing)
int main(){
circle circl(3,5,7);
ellipse elips(3, 3, 6, 5);
square squar(1,6,5);
rectangle rectan(20,5,5,6);
circl.print();
elips.print();
squar.print();
rectan.print();
return 0;
}
