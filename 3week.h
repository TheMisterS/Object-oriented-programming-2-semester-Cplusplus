#ifndef room
#define room
#include <bits/stdc++.h>
using namespace std;
class Langas{
    float aukstis, plotis;
    static int langu_skaicius;
    public:
    Langas(float norimas_aukstis, float norimas_plotis){
        aukstis = norimas_aukstis;
        plotis = norimas_plotis;
        langu_skaicius++;
    }
    void set_aukstis(float value){
        aukstis = value;
    }
    void set_plotis(float value){
        plotis = value;
    }
    float get_aukstis(){
        return aukstis;
    }
    float get_plotis(){
        return plotis;
    }
    static int get_kiekis(){
        return langu_skaicius;
    }
    ~Langas(){
        langu_skaicius--;
    }
};
int Langas::langu_skaicius = 0;

class Durys{
    float aukstis, plotis;
    static int duru_skaicius;
    public:
    Durys(float norimas_aukstis, float norimas_plotis){
        aukstis = norimas_aukstis;
        plotis = norimas_plotis;
        duru_skaicius++;
    }
    void set_aukstis(float value){
        aukstis = value;
    }
    void set_plotis(float value){
        plotis = value;
    }
    float get_aukstis(){
        return aukstis;
    }
    float get_plotis(){
        return plotis;
    }
    static int get_kiekis(){
        return duru_skaicius;
    }
    ~Durys(){
        duru_skaicius--;
    }
};
int Durys::duru_skaicius = 0;

class Kambarys{
    private:
    float aukstis, plotis, ilgis;
    vector <Langas*> langai_vector;
    vector <Durys*> durys_vector;
    public:
    Kambarys(float norimas_aukstis, float norimas_plotis, float norimas_ilgis){
        aukstis = norimas_aukstis;
        plotis = norimas_plotis;
        ilgis = norimas_ilgis;
    }
    void set_aukstis(float value){
        aukstis = value;
    }
    void set_plotis(float value){
        plotis = value;
    }
    void set_ilgis(float value){
        ilgis = value;
    }
    float get_aukstis(){
        return aukstis;
    }
    float get_plotis(){
        return plotis;
    }
    float get_ilgis(){
        return ilgis;
    }
    void add_durys(Durys *papildomos_durys){
        durys_vector.push_back(papildomos_durys);
    }
    void add_langas(Langas *papildomas_langas){
        langai_vector.push_back(papildomas_langas);
    }

    float skaiciuoti_sienos_plota(){
        float plotas = 0;
        plotas = (aukstis * ilgis * 2) + (aukstis * plotis * 2); // suskaiciuojamas plotas be langu, duru.
        for(int i = 0;i < langai_vector.size();++i){
            plotas = plotas - (langai_vector[i]->get_aukstis() * langai_vector[i]->get_plotis()); // atimamas visu langu plotas is bendro ploto
        }
        for(int i = 0;i < durys_vector.size();++i){
            plotas = plotas - (durys_vector[i]->get_aukstis() * durys_vector[i]->get_plotis()); // atimamas visu duru plotas is bendro ploto
        }
        return plotas;
    }

    float skaiciuoti_grindjuosciu_ilgi(){
        float grindjuosciu_ilgis = 0;
        grindjuosciu_ilgis = (2 * ilgis) + (2 * plotis); // grindu perimetras neatemus duru.
        for(int i = 0; i < durys_vector.size();++i){
            grindjuosciu_ilgis = grindjuosciu_ilgis - durys_vector[i]->get_plotis(); // is viso grindu perimetro atimamas visu duru plotis.
        }
        return grindjuosciu_ilgis;
    }
    ~Kambarys(){
        for(int i = 0;i < langai_vector.size();++i)
            delete langai_vector[i];

        for(int i = 0;i < durys_vector.size();++i)
            delete durys_vector[i];
    }
};
#endif // room
