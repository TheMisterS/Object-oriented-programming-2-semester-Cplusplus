#ifndef week7
#define week7
#include <bits/stdc++.h>
using namespace std;
template<typename T> class my_vector{
    int vector_size; //default size
    int step; //default step
    T* t;
    int last_index = 0;
public:
    my_vector(int desired_size, int desired_step);
    void my_pushback(T value);
    int my_size();
    T& operator[](int index);
    ~my_vector();
};

template <typename T>
void bubble_sort_vector(vector <T> &Values);
//void print_string_vector(vector<string>Values);
//void print_int_vector(vector<int>Values);

#endif // week7
