#ifndef exceptions
#define exceptions
#include <bits/stdc++.h>
using namespace std;

class Skaicius {
    int skaicius;
public:
    static int MinimaliReiksme, Maksimalireiksme;
    int get_skaicius(){
        return skaicius;
    }
    void set_skaicius(int NorimasSkaicius){
            if(NorimasSkaicius >= MinimaliReiksme && NorimasSkaicius <= Maksimalireiksme){
                skaicius = NorimasSkaicius;
            }else{
                throw(out_of_range("Skaicius nepataiko i rezius!Kartokite!"));
            }
    }
    static void change_MinimaliReiksme(int NorimaMinimali){
            MinimaliReiksme = NorimaMinimali;
    }
    static void change_MaksimaliReiksme(int NorimaMaksimali){
            Maksimalireiksme = NorimaMaksimali;
    }
};

#endif // exceptions
