#ifndef overload
#define overload
#include <bits/stdc++.h>
using namespace std;
class Trupmena {
    int skaitiklis;
    unsigned int vardiklis;
public:
    Trupmena(int norimas_skaitiklis, unsigned int norimas_vardiklis);
    Trupmena(int norimas_skaitklis);
    Trupmena();
    void Paprastinti();
    void add(Trupmena kita_trupmena);
    Trupmena operator+(Trupmena const &kita_trupmena);
    Trupmena operator+=(Trupmena const &kita_trupmena);
    Trupmena operator-(Trupmena const &kita_trupmena);
    Trupmena operator-=(Trupmena const &kita_trupmena);
    int operator>(Trupmena const &kita_trupmena);
    int operator<(Trupmena const &kita_trupmena);
    Trupmena operator++();
    Trupmena operator++(int);
    friend ostream& operator<<(ostream& os, const Trupmena& tp);
    string toString();
};


ostream& operator<<(ostream& os, const Trupmena& tp);
#endif // overload
