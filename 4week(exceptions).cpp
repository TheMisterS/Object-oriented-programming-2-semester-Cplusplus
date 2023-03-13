#include <stdexcept>
#include <limits>
#include <bits/stdc++.h>
#include "4week.h"
using namespace std;

int Skaicius::MinimaliReiksme = 0;
int Skaicius::Maksimalireiksme = 0;

int main(){
    Skaicius Skaiciai[10];
    int index;
    cout << "Pirminiai reziai:  [" <<Skaiciai[0].MinimaliReiksme << ";" << Skaiciai[0].Maksimalireiksme << "]" << endl;
    Skaiciai[0].change_MinimaliReiksme(0);
    Skaiciai[0].change_MaksimaliReiksme(10);
    cout << "Pakeisti reziai:   [" <<Skaiciai[0].MinimaliReiksme << ";" << Skaiciai[0].Maksimalireiksme << "]" << endl;
    cout << "Iveskite 10 skaiciu, kurie patenka i rezius [" << Skaiciai[0].MinimaliReiksme << ";" << Skaiciai[0].Maksimalireiksme << "] :" << endl;
    for(int i = 0; i <10;++i){
            IvedimoPradzia:
        try{
            cout << "Iveskite " << i +1 << "-aji skaiciu:" << endl;
            if(!(cin >> index)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw(invalid_argument("Ivestas ne skaicius!Kartokite!"));
            }else{
                Skaiciai[i].set_skaicius(index);
            }
        }catch(invalid_argument &e){
                cerr << e.what() << endl;
                goto IvedimoPradzia;
        }catch(out_of_range &e){
                cerr << e.what() << endl;
                goto IvedimoPradzia;
        }

    }
    cout << "Sekmingai ivesti skaiciai: " << endl;
    for(int i = 0; i <10;++i){
        cout << "Skaicius Nr." << i + 1 << ": ";
        index = Skaiciai[i].get_skaicius();
        cout << index << endl;
    }
    return 0;
}
