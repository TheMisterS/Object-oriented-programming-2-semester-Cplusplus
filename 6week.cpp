#include <bits/stdc++.h>
#include "6week.h"
using namespace std;
// LANGAI FUNCTIONS-------------------------------------------------------
Langas::Langas(float norimas_aukstis, float norimas_plotis){
        aukstis = norimas_aukstis;
        plotis = norimas_plotis;
        langu_skaicius++;
    }
void Langas::set_aukstis(float value){
        aukstis = value;
    }
void Langas::set_plotis(float value){
        plotis = value;
    }
float Langas::get_aukstis(){
        return aukstis;
    }
float Langas::get_plotis(){
        return plotis;
    }
int Langas::get_kiekis(){
        return langu_skaicius;
    }
Langas::~Langas(){
        langu_skaicius--;
    }
// DURYS FUNCTIONS--------------------------------------------------------------------------------------------------------------
Durys::Durys(float norimas_aukstis, float norimas_plotis){
    aukstis = norimas_aukstis;
    plotis = norimas_plotis;
    duru_skaicius++;
    
}
void Durys::set_aukstis(float value){
    aukstis = value;
}
void Durys::set_plotis(float value){
    plotis = value;
}
float Durys::get_aukstis(){
    return aukstis;
}
float Durys::get_plotis(){
    return plotis;
}
int Durys::get_kiekis(){
    return duru_skaicius;
}
Durys::~Durys(){
    duru_skaicius--;
}
// KAMBARYS FUNCTIONS----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Kambarys::Kambarys(float norimas_aukstis, float norimas_plotis, float norimas_ilgis){
    aukstis = norimas_aukstis;
    plotis = norimas_plotis;
    ilgis = norimas_ilgis;
}
Kambarys::Kambarys(const Kambarys &k){
    aukstis = k.aukstis;
    plotis = k.plotis;
    ilgis = k.ilgis;
    durys_pointer = k.durys_pointer;
    langai_vector = k.langai_vector;
}
void Kambarys::set_aukstis(float value){
    aukstis = value;
}
void Kambarys::set_plotis(float value){
    plotis = value;
}
void Kambarys::set_ilgis(float value){
    ilgis = value;
}
float Kambarys::get_aukstis(){
    return aukstis;
}
float Kambarys::get_plotis(){
    return plotis;
}
float Kambarys::get_ilgis(){
    return ilgis;
}
void Kambarys::add_durys(Durys *papildomos_durys){
    durys_pointer = papildomos_durys;
}
void Kambarys::add_langas(Langas *papildomas_langas){
    langai_vector.push_back(papildomas_langas);
}
Durys* Kambarys::get_durys(){
    return durys_pointer;
}
vector <Langas*> Kambarys::get_langai(){
    return langai_vector;
}
Kambarys::~Kambarys(){
    for(int i = 0;i < langai_vector.size();++i){
        if(langai_vector[i] != NULL){
            langai_vector[i] = NULL;
            delete langai_vector[i];

        }
    }
    if(durys_pointer != NULL){
            durys_pointer = NULL;
            delete durys_pointer;
        }
    langai_vector.clear();

}
Kambarys& Kambarys::operator=(const Kambarys& k){
    durys_pointer == NULL;
    for(int i = 0;i < langai_vector.size();++i){
        if(langai_vector[i] != NULL){
            delete langai_vector[i];
        }
    }
    langai_vector.clear();
    langai_vector = k.langai_vector;
    durys_pointer = k.durys_pointer;
    ilgis = k.ilgis;
    plotis = k.plotis;
    aukstis = k.aukstis;
    return *this;
}
// GLOBAL FUNCTIONS----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
float skaiciuoti_sienos_plota(Kambarys norimas_kambarys){
    float plotas = 0;
    float aukstis = norimas_kambarys.get_aukstis();
    float plotis = norimas_kambarys.get_plotis();
    float ilgis = norimas_kambarys.get_ilgis();
    Durys* index_durys = norimas_kambarys.get_durys();
    vector <Langas*> index_langai = norimas_kambarys.get_langai();

    plotas = (aukstis * ilgis * 2) + (aukstis * plotis * 2); // suskaiciuojamas plotas be langu, duru.
    for(int i = 0;i < index_langai.size();++i){
        plotas = plotas - (index_langai[i]->get_aukstis() * index_langai[i]->get_plotis()); // atimamas visu langu plotas is bendro ploto
    }
    plotas = plotas - (index_durys->get_aukstis() * index_durys->get_plotis()); // atimamas visu duru plotas is bendro ploto
    return plotas;
}
float skaiciuoti_grindjuosciu_ilgi(Kambarys norimas_kambarys){
    float grindjuosciu_ilgis = 0;
    float ilgis = norimas_kambarys.get_ilgis();
    float plotis = norimas_kambarys.get_plotis();
   Durys* index_durys = norimas_kambarys.get_durys();


    grindjuosciu_ilgis = (2 * ilgis) + (2 * plotis); // grindu perimetras neatemus duru.
    grindjuosciu_ilgis = grindjuosciu_ilgis - index_durys->get_plotis(); // is viso grindu perimetro atimamas visu duru plotis.
    return grindjuosciu_ilgis;
}

int main(){
    cout <<"Sukuriamas Kambarys..." << endl;
    Kambarys *k1 = new Kambarys(10,10,10);    
    cout << "Sukuriamos  durys ir 2 langai..." << endl;
    Durys *durys1 = new Durys(5,6);
    cout << "Duru kiekis: " << durys1->get_kiekis() << endl;
    Langas *langas1 = new Langas(2,4);
    cout << "Langu kiekis: " << langas1->get_kiekis() << endl;
    Langas *langas2 = new Langas(1,3);
    cout << "Langu kiekis: " << langas2->get_kiekis() << endl;
    cout <<"Sukurtos durys ir langai pridedami prie kambario... " << endl;
    k1->add_durys(durys1);
    k1->add_langas(langas1);
    k1->add_langas(langas2);
    cout << "Duru kiekis: " << durys1->get_kiekis() << endl;
    cout << "Langu kiekis: " << langas2->get_kiekis() << endl;
    cout << "Skaiciuojamas kambario grindjuosciu ilgis viena karta: "<<skaiciuoti_grindjuosciu_ilgi(*k1) << endl;
    cout << "Skaiciuojamas kambario grindjuosciu ilgis antra karta: "<<skaiciuoti_grindjuosciu_ilgi(*k1) << endl;
    cout << "Skaiciuojamas Kambario plotas pirma karta: "<< skaiciuoti_sienos_plota(*k1) << endl;
    cout << "Skaiciuojamas Kambario plotas antra karta: "<< skaiciuoti_sienos_plota(*k1) << endl;

    Kambarys k2(1,12,13);
    cout << "Sukuriamas naujas kambarys k2, jam priskiriami seno kambario k1 duomenys ir jis(k1) yra istrinamas...." << endl;
    k2 = *k1;   
    delete k1;
    cout << "Skaiciuojamas kambario grindjuosciu ilgis su k2 kambariu: "<<skaiciuoti_grindjuosciu_ilgi(k2) << endl;
    cout << "Skaiciuojamas Kambario plotas su k2 kambariu: "<< skaiciuoti_sienos_plota(k2) << endl;
    cout << "Duru kiekis: " << durys1->get_kiekis() << endl;
    cout << "Langu kiekis: " << langas2->get_kiekis() << endl;
    return 0;
}
