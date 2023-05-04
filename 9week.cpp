#include <bits/stdc++.h>
#include "9week.h"
using namespace std;
template <typename T>
my_vector<T>::my_vector(int desired_size, int desired_step){
    vector_size = desired_size;
    step = desired_step;
    t = new T[vector_size];
}
template <typename T>
void my_vector<T>::my_pushback(T value){
    t[last_index] = value;
    ++last_index;
    if(last_index == vector_size){
        vector_size = vector_size + step;
        T* t_new = new T[vector_size];
        //memcpy(t_new, t, sizeof(T) * last_index); // nepavyko sutvarkyti
        copy(t, t + last_index, t_new);
        delete[] t;
        t = t_new;
    }
}
template <typename T>
int my_vector<T>::my_size(){
    return last_index;
}
template<typename T>
T& my_vector<T>::operator[](int index) {
    if (index >= last_index) {
        throw std::out_of_range("Index out of range");
    }
    return t[index];
}

template<typename T>
typename my_vector<T>::iterator my_vector<T>::begin(){
    return iterator(*this, 0);
}

template<typename T>
typename my_vector<T>::iterator my_vector<T>::end(){
    return iterator(*this, my_size());
}
template<typename T>
my_vector<T>::~my_vector(){
    delete[] t;
}

template<typename T>
my_iterator<T>::my_iterator(my_vector<T> &given_my_vector_reference, int given_vector_position)
: my_vector_reference(given_my_vector_reference), position(given_vector_position)
{}

compare_ints_digit_sum::operator()(int value1, int value2) const{
    int sum1 = 0, sum2 = 0;
    while(value1 > 0){
        sum1 += value1 % 10;
        value1 /= 10;
    }
    while(value2 > 0){
        sum2 += value2 % 10;
        value2 /= 10;
    }
    if(sum1 > sum2) return 1; // if the sum of the digits of the integer 1 is bigger than that of integer 2
    return 0; // if its not
}
compare_vowels::operator()(string str1, string str2) const{
    int count1 = count_vowels(str1);
    int count2 = count_vowels(str2);
    if(count1 > count2){
        return 1;
    }else{
        return 0;
    }
}
template <class Iterator, class Functor>
inline void bubble_sort(Iterator begin, Iterator end, Functor functional_object){
    for(Iterator i = begin; i != end; ++i)
        for(Iterator j = begin; j < i; ++j)
            if(functional_object(*i, *j))
                iter_swap(i, j);
}
void print_string_vector(vector<string>values){
    vector<string>::iterator ptr;
    cout << "Your string vector: " << endl;
    for(ptr = values.begin(); ptr < values.end(); ptr++)
        cout << *ptr << endl;
}
void print_int_vector(vector<int>values){
    vector<int>::iterator ptr;
    cout << "Your int vector: " << endl;
    for(ptr = values.begin(); ptr < values.end(); ptr++)
        cout << *ptr << endl;
}
int count_vowels(string str){
    int count = 0;
    for (int i = 0; i < str.length(); i++){
        if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u'){
            count++;
        }
    }
    return count;
}


int main(){
    int arraySize = 20;
    int  i = 0;
    string index_s;
    int index_i;
    vector <string> string_values;
    vector <int> int_values;
    compare_ints_digit_sum int_digit_sum;
    compare_vowels string_vowels;
    //CUSTOM VECTOR TEST
    cout << "Testing custom vector class by creating an int and a string vector(both with max size of 20 and step of 5)!" << endl;
    my_vector<int> test_int_vector(20,2);
    my_vector<string> test_string_vector(20, 3);
    cout << "Size of the vectors. Int vector: " << test_int_vector.my_size() << " String vector: " << test_string_vector.my_size() << endl;
    cout << "Pushing back 60 items to each of the vectors..." << endl;
    for(int i = 0; i < 60;++i){
        test_int_vector.my_pushback(i);
        test_string_vector.my_pushback("a");
    }
    cout << "Size of the vectors. Int vector: " << test_int_vector.my_size() << " String vector: " << test_string_vector.my_size() << endl;
    cout << "Items in the int vector: " << endl;
    for(int i = 0; i < test_int_vector.my_size();++i){
        cout << test_int_vector[i] << " ";
    }
    cout << endl;
    cout << "Items in the String vector: " << endl;
    for(int i = 0; i < test_string_vector.my_size();++i){
        cout << test_string_vector[i] << " ";
    }
    cout << endl << endl;
    // ENTERETING AND SORTING INT/STRING VALUES CHECK
    cout << "Enter integers (end input by entering '0')" << endl;
    cout << "Iveskite " << i << "-o indekso masyvo verte(int tipo):" << endl;
    while(cin >> index_i){
        if(index_i == 0) break;
        ++i;
        cout << "Iveskite " << i << "-o indekso masyvo verte(int tipo):" << endl;
        int_values.push_back(index_i);
    }
    bubble_sort(int_values.begin(),int_values.end(), int_digit_sum);
    print_int_vector(int_values);

    cout << "Now enter strings(end input by entering '-'): " << endl;
    for(int i = 0; i < arraySize;++i){
        cout << "Iveskite " << i << "-o indekso masyvo verte(string tipo):" << endl;
        cin >> index_s;
        if(index_s == "-") break;
        string_values.push_back(index_s);
    }
    bubble_sort(string_values.begin(),string_values.end(), string_vowels);
    print_string_vector(string_values);
    return 0;
}


