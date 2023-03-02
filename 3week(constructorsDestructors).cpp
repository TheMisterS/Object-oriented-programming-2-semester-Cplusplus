#include <bits/stdc++.h>
#include "3week.h"
using namespace std;

int main(){
    cout << "Sukuriamos dvi poros duru ir langu..." << endl;
    Durys *durys1 = new Durys(5,6);
    cout << "Duru kiekis: " << durys1->get_kiekis() << endl;
    Durys *durys2 = new Durys(3,4);
    cout << "Duru kiekis: " << durys2->get_kiekis() << endl;
    Langas *langas1 = new Langas(2,4);
    cout << "Langu kiekis: " << langas1->get_kiekis() << endl;
    Langas *langas2 = new Langas(1,3);
    cout << "Langu kiekis: " << langas2->get_kiekis() << endl;

    cout << endl << "Sukuriama dar viena pora..." << endl;
    Durys *durys3 = new Durys(7,9);
    cout << "Duru kiekis: " << durys3->get_kiekis() << endl;
    Langas *langas3 = new Langas(4,6);
    cout << "Langu kiekis: " << langas3->get_kiekis() << endl;
    cout << endl << "Sunaikinami paskutins langas ir durys..." << endl;
    delete durys3;
    delete langas3;
    cout << "Duru kiekis: " << durys3->get_kiekis() << endl;
    cout << "Langu kiekis: " << langas3->get_kiekis() << endl;

    cout << endl << "Sukuriamas Kambarys ir jam pridedami langai bei durys..." << endl;
    Kambarys *kambarys1 = new Kambarys(10,10,10);
    kambarys1->add_durys(durys1);
    kambarys1->add_durys(durys2);
    kambarys1->add_langas(langas1);
    kambarys1->add_langas(langas2);
    cout << "Duru kiekis: " << durys3->get_kiekis() << endl;
    cout << "Langu kiekis: " << langas3->get_kiekis() << endl;
    cout << "Kambario plotas: "<<kambarys1->skaiciuoti_sienos_plota() << endl;
    cout << "Kambario grindjuosciu ilgis: "<<kambarys1->skaiciuoti_grindjuosciu_ilgi() << endl;

    cout << endl << "Sunaikinamas kambarys(kartu susinaikina langai bei durys jame)" << endl;
    delete kambarys1;
    cout << "Duru kiekis: " << durys3->get_kiekis() << endl;
    cout << "Langu kiekis: " << langas3->get_kiekis() << endl;
    return 0;
}
