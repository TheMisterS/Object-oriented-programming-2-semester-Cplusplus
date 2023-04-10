#ifndef week7
#define week7
#include <bits/stdc++.h>
#define SIZE 20;
template<typename T> class my_vector{
    T* t = new T[SIZE];
    int last_index = 0;
public:
    void my_pushback(T value);{
        t[last_index] = value;
        ++last_index;
    }

};


template <typename T> void bubble_sort_vector(vector<T>&Values);
void print_string_vector(vector<string>Values);
void print_int_vector(vector<int>Values);

#endif // week7



;
