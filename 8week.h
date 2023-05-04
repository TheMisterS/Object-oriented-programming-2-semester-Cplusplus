#ifndef week8
#define week8
#include <bits/stdc++.h>
using namespace std;
template <typename T> class my_iterator;

template<typename T> class my_vector{
    int vector_size; //default size
    int step; //default step
    T* t;
    int last_index = 0;
    friend class  my_iterator<T>;
public:
    typedef my_iterator<T> iterator;
    my_vector(int desired_size, int desired_step);
    void my_pushback(T value);
    int my_size();
    T& operator[](int index);
    iterator begin();
    iterator end();
    ~my_vector();
};

template<typename T>
class my_iterator{
    my_vector<T> & my_vector_reference;
    int position;
 public:
    my_iterator(my_vector<T> &given_my_vector_reference, int given_vector_position);
};
template <class Iterator>
inline void bubble_sort(Iterator begin, Iterator end);
void print_string_vector(vector<string>Values);
void print_int_vector(vector<int>Values);

#endif // week8
