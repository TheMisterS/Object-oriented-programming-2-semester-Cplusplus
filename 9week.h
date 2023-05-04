#ifndef week9
#define week9
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
class my_iterator{ // failed custom iterator
    my_vector<T> & my_vector_reference;
    int position;
 public:
    my_iterator(my_vector<T> &given_my_vector_reference, int given_vector_position);
};

class compare_ints_digit_sum{ //compares the sum of the digits in two integers
public:
    int operator()(int value1, int value2) const;
};

int count_vowels(string str); // compares the sum of the digits in two integers

class compare_vowels{ // compares the number of vowels in a word
public:
    int operator()(string str1, string str2) const;
};

template <class Iterator, class Functor>
inline void bubble_sort(Iterator begin, Iterator end);
void print_string_vector(vector<string>Values); // prints the whole string vector
void print_int_vector(vector<int>Values); // prints the whole int vector
int count_vowels(string str); // counts vowels in a word
#endif // week9
