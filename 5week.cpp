#include <bits/stdc++.h>
#include "5week.h"
using namespace std;
Trupmena::Trupmena(int norimas_skaitiklis, unsigned int norimas_vardiklis){
    try{
        if((int)norimas_vardiklis <= 0){
            throw(invalid_argument("Vardiklis turi buti >=0!"));
        }

    }catch(invalid_argument &e){
        cerr << e.what() << endl;
        cerr << "Vardiklis buvo pakeistas i leidiazama reiksme!T.Y: ";
        norimas_vardiklis = abs((int)norimas_vardiklis);
        if(norimas_vardiklis == 0) norimas_vardiklis++;
        cerr << norimas_vardiklis << endl;
    }

    skaitiklis = norimas_skaitiklis;
    vardiklis = norimas_vardiklis;
    Paprastinti();
}
Trupmena::Trupmena(int norimas_skaitklis){
    //Trupmena(norimas_skaitklis, 1); // sunku suprasti kodel neveikia
    skaitiklis = norimas_skaitklis;
    vardiklis = 1;
}
Trupmena::Trupmena(){
    skaitiklis = 0;
    vardiklis = 1;
}
void Trupmena::Paprastinti(){
    if(skaitiklis == 0){
        vardiklis = 1;
        return;
    }
    int dbd = __gcd(skaitiklis, (int)vardiklis);
    if(dbd == 1 || dbd == - 1) return; // jei dbd = 1/-1 nesigauna prastinti
    skaitiklis = skaitiklis / dbd;
    vardiklis = vardiklis / dbd;
}
void Trupmena::add(Trupmena kita_trupmena){
    skaitiklis = (skaitiklis * kita_trupmena.vardiklis) + (kita_trupmena.skaitiklis * vardiklis);
    vardiklis = vardiklis * kita_trupmena.vardiklis;
}
Trupmena Trupmena::operator+(Trupmena const &kita_trupmena){
    Trupmena result;
    result.skaitiklis = (this->skaitiklis * kita_trupmena.vardiklis) +(kita_trupmena.skaitiklis * this->vardiklis);
    result.vardiklis = this->vardiklis * kita_trupmena.vardiklis;
    return result;
}
Trupmena Trupmena::operator-(Trupmena const &kita_trupmena){
    Trupmena result;
    result.skaitiklis = (this->skaitiklis * kita_trupmena.vardiklis) -(kita_trupmena.skaitiklis * this->vardiklis);
    result.vardiklis = this->vardiklis * kita_trupmena.vardiklis;
    return result;
}
Trupmena Trupmena::operator+=(Trupmena const &kita_trupmena){
    Trupmena result;
    Trupmena pirmine_trupmena = *this;
    result = pirmine_trupmena + kita_trupmena;
    skaitiklis = result.skaitiklis;
    vardiklis = result.vardiklis;
    return result;
}
Trupmena Trupmena::operator-=(Trupmena const &kita_trupmena){
    Trupmena result;
    Trupmena pirmine_trupmena = *this;
    result = pirmine_trupmena - kita_trupmena;
    skaitiklis = result.skaitiklis;
    vardiklis = result.vardiklis;
    return result;
}
int Trupmena::operator>(Trupmena const &kita_trupmena){
    Trupmena pirmine_trupmena = *this;
    Trupmena index_trupmena = pirmine_trupmena - kita_trupmena;
    if(index_trupmena.skaitiklis > 0){
        return 1;
    }
    return 0;
}
int Trupmena::operator<(Trupmena const &kita_trupmena){
    Trupmena pirmine_trupmena = *this;
    Trupmena index_trupmena = pirmine_trupmena - kita_trupmena;
    if(index_trupmena.skaitiklis < 0){
        return 1;
    }
    return 0;
}
Trupmena Trupmena::operator++(){ //prefix
    skaitiklis = skaitiklis + 1;
    return *this;
}
Trupmena Trupmena::operator++(int){ //postfix
    Trupmena laikinas = *this;
    skaitiklis = skaitiklis + 1;
    return laikinas;
}
string Trupmena::toString(){
    string output;
    stringstream ss;
    ss << skaitiklis << '/' << vardiklis;
    ss >> output;
    ss.clear();
    return output;
}
ostream& operator<<(ostream& os, const Trupmena& tp){
    os << tp.skaitiklis << '/' << tp.vardiklis;
    return os;
}
int main(){

    Trupmena vienas; // 2 dalis
    Trupmena du(30); // 2 dalis
    Trupmena trys(-3,1); // 2 dalis
    Trupmena ketvirtas(5,1);
    Trupmena penktas;
    cout << "Ivesti skaiciai: " << endl;
    cout <<"Pirmas: "<< vienas.toString() << endl; //4 dalis
    cout <<"Antras: "<< du.toString() << endl;
    cout <<"Trecias: "<< trys.toString() << endl;
    cout <<"ketvirtas: "<< ketvirtas.toString() << endl;
    cout <<"penktas: "<< penktas.toString() << endl << endl;

    vienas.add(du);
    cout << "Prie pirmo pridedamas antras(su add), rezultatas: " << vienas << endl; // 5 dalis

    vienas = vienas + trys;
    cout << "Tada pridedamas trecias(su +), rezultatas: " << vienas << endl; // 5 dalis

    vienas = vienas - trys;
    cout << "Tada atimamas trecias(su -), rezultatas: " << vienas << endl; //6 dalis

    vienas += ketvirtas;
    cout << "Panaudojama operacija(+=) vienas+= ketvirtas , rezultatas: " << vienas << endl; //6 dalis

    vienas -= ketvirtas;
    cout << "Panaudojama operacija(-=) vienas-= ketvirtas , rezultatas: " << vienas << endl << endl; //6 dalis

    cout << "Tikrinamos lyginimo operacijos: vienas > du, rezultatas: " << (vienas > du) << endl; // 7 dalis
    cout << "Tikrinamos lyginimo operacijos: vienas < trys, rezultatas: " << (vienas < trys) << endl; // 7 dalis
    cout << "Tikrinamos lyginimo operacijos: vienas > trys, rezultatas: " << (vienas > trys) << endl; // 7 dalis
    cout << "Tikrinamos lyginimo operacijos: vienas > vienas, rezultatas: " << (vienas > vienas) << endl << endl; // 7 dalis

    vienas++;
    cout << "prefiksinio operatoriaus tikrinimas, ++vienas, Rezultatas: "<< vienas << endl; //9 dalis

    cout << "postfiksinio operatoriaus tikrinimas, penki = vienas++" << endl; //9 dalis
    cout << "Vienas pries operacija: " << vienas << endl;
    penktas = vienas++;
    cout << "penki po operacijos: " << penktas << endl;
    cout << "Vienas po operacijos: " << vienas<< endl << endl;

    cout << "Finaliniai skaiciai: " << endl; // 8 dalis
    cout << "Pirmas: " << vienas << " Antras: " << du << " Trecias: " << trys << " Ketvirtas: " << ketvirtas << " Penktas: " << penktas << endl;
    return 0;
}
