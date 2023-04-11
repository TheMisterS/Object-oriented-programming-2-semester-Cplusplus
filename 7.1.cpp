#include <bits/stdc++.h>
#include "7.1.h"
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
my_vector<T>::~my_vector(){
    delete[] t;
}

template<typename T>
void bubble_sort_vector(std::vector<T>& Values){ // 5 PUNKTAS !!!
    for(int i = 0; i < Values.size();++i){
            for(int j = 0; j < Values.size() - 1;++j){
                if(Values[j] > Values[j+1]){
                    swap(Values[j],Values[j+1]);
                }
            }
        }
}
void print_string_vector(vector<string>Values){
    cout << "Your string vector: " << endl;
    for(int i = 0;i < Values.size();++i){
        cout << "Index " << i  << ": "<< Values[i] << endl;
    }
}
void print_int_vector(vector<int>Values){
    cout << "Your int vector: " << endl;
    for(int i = 0;i < Values.size();++i){
        cout << "Index " << i  << ": "<< Values[i] << endl;
    }
}
int main(){
    int arraySize = 20, arraySpace;
    int index, i = 0;
    string index_s;
    int index_i;
    vector <string> string_values;
    vector <int> int_values;
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
    cout << "Enter integers (end input byt entering '0')" << endl;
    cout << "Iveskite " << i << "-o indekso masyvo verte(int tipo):" << endl;
    while(cin >> index_i){
        if(index_i == 0) break;
        ++i;
        cout << "Iveskite " << i << "-o indekso masyvo verte(int tipo):" << endl;
        int_values.push_back(index_i);
    }
    bubble_sort_vector<int>(int_values);
    print_int_vector(int_values);

    cout << "Now enter strings(end input by entering '-'): " << endl;
    for(int i = 0; i < arraySize;++i){
        cout << "Iveskite " << i << "-o indekso masyvo verte(string tipo):" << endl;
        cin >> index_s;
        if(index_s == "-") break;
        string_values.push_back(index_s);
    }
    bubble_sort_vector<string>(string_values);
    print_string_vector(string_values);
    return 0;
}


