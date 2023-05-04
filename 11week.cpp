#include <cmath>
#include <bits/stdc++.h>
#include "11week.h"
using namespace std;
#define PI 3.14159265
// Point functions
point::point(float desired_x, float desired_y){
    x = desired_x;
    y = desired_y;
    cout << "[POINT constructor]" << endl;
}
void point::set_x(float desired_x){
    x = desired_x;
}
void point::set_y(float desired_y){
    x = desired_y;
}
void point::set_both(float desired_x, float desired_y){
    x = desired_x;
    y = desired_y;
}
float point::get_x(){
    return x;
}
float point::get_y(){
    return y;
}
point::~point(){
    cout << "[POINT destructor]" << endl;
}
// Figure functions
figure::figure(float x, float y)
: position(x, y)
{
    cout << "[FIGURE constructor]" << endl;
}
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
    cout << "[FIGURE destructor]" << endl;
}
// Circle functions
circle::circle(float x, float y, float r)
   : figure(x,y)
{
    radius = r;
    cout << "[CIRCLE constructor]" << endl;
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
}
circle::~circle(){
    cout << "[CIRCLE destructor]" << endl;
}
// Ellipse functions
ellipse::ellipse(float x, float y, float r, float r2)
: circle(x, y ,r)
{
    second_axis = r2;
    cout << "[ELLIPSE constructor]" << endl;
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
}
ellipse::~ellipse(){
    cout << "[ELLIPSE destructor]" << endl;
}
//Square functions
square::square(float x, float y, float desired_side)
    : figure(x, y)
{
    side = desired_side;
    cout << "[SQUARE constructor]" << endl;
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
}
square::~square(){
    cout << "[SQUARE destructor]" << endl;
}
//Rectangle functions
rectangle::rectangle(float x, float y, float desired_side, float desired_another_side)
:   square(x, y, desired_side)
{
    another_side = desired_another_side;
    cout << "[RECTANGLE constructor]" << endl;
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
}
rectangle::~rectangle(){
    cout << "[RECTANGLE destructor]" << endl;
}
// Main function(for testing)
int main(){
vector<figure*> figures;
int round_figure_count = 0, square_figure_count = 0;
float round_figure_area = 0, square_figure_area = 0;
circle* circ1 = new circle(1.2,3.1,5);
ellipse* ellipse1 = new ellipse(2.1,2.2,6,6.5);
square* square1 = new square(3.1,3.2,7);
rectangle* rect1 = new rectangle(4.1,4.2,8,8.1);
rectangle* rect2 = new rectangle(4.1,4.2,9,9);
figures.push_back(circ1);
figures.push_back(ellipse1);
figures.push_back(square1);
figures.push_back(rect1);
figures.push_back(rect2);
cout << "The coordinates of the figures in the vector are: " << endl;
for(vector<figure*>::iterator iter = figures.begin();iter < figures.end();++iter){
    (*iter)->print();
}
for(int i = 0;i < figures.size();++i){
    if(ellipse* round_figure = dynamic_cast<ellipse*>(figures[i])){
        round_figure_area += round_figure->area();
        round_figure_count++;
    }else if(rectangle* square_figure = dynamic_cast<rectangle*>(figures[i])){
        square_figure_area += square_figure->area();
        square_figure_count++;
    }else if(square* square_figure = dynamic_cast<square*>(figures[i])){
        square_figure_area += square_figure->area();
        square_figure_count++;
    }else if(circle* round_figure = dynamic_cast<circle*>(figures[i])){
        round_figure_area += round_figure->area();
        round_figure_count++;
    }else{
        cout <<"Unkown type" << endl;
    }
}
cout << "There are " << round_figure_count << " round figures in the vector." << endl;
cout << "There are " << square_figure_count << " square figures in the vector." << endl;
cout << "The combined area of round figures is: " << round_figure_area << endl;
cout << "The combined area of round figures is: " << square_figure_area << endl;
cout <<"Deleting the vector..." << endl;
for(int i = 0; i < figures.size();++i) delete figures[i];
return 0;
}
