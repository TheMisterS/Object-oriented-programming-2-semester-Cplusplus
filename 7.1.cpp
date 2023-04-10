#include <bits/stdc++.h>
#include "7.1.h"
using namespace std;
void my_vector::my_pushback(T value){
        t[last_index] = value;
        ++last_index;
    }
template <typename T>
void bubble_sort_vector(vector<T>&Values){ // 5 PUNKTAS !!!
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
    cout << "Enter integers (end input byt entering '0')" << endl;
    cout << "Iveskite " << i << "-o indekso masyvo verte(string tipo):" << endl;
    while(cin >> index_i){
        if(index_i == 0) break;
        ++i;
        cout << "Iveskite " << i << "-o indekso masyvo verte(string tipo):" << endl;
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


