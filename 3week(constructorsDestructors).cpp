#include <iostream>
#include <vector>
using namespace std;

class Langas{
    float aukstis, plotis;
    public:
    Langas(float norimas_aukstis, float norimas_plotis){
        aukstis = norimas_aukstis;
        plotis = norimas_plotis;
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
};

class Durys{
    float aukstis, plotis;
    public:
    Durys(float norimas_aukstis, float norimas_plotis){
        aukstis = norimas_aukstis;
        plotis = norimas_plotis;
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
};

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
};

int main(){
    Durys *durys1 = new Durys(5,6);
    Durys *durys2 = new Durys(3,4);
    Langas *langas1 = new Langas(2,4);
    Langas *langas2 = new Langas(1,3);
    Kambarys *kambarys1 = new Kambarys(10,10,10);

    kambarys1->add_durys(durys1);
    kambarys1->add_durys(durys2);
    kambarys1->add_langas(langas1);
    kambarys1->add_langas(langas2);

    cout << "Kambario sienos plotas yra: " << kambarys1->skaiciuoti_sienos_plota() << endl;
    cout << "Kambario grindjuosciu ilgis yra: " << kambarys1->skaiciuoti_grindjuosciu_ilgi() << endl;delete durys1;

    delete durys2;
    delete langas1;
    delete langas2;
    delete kambarys1;
    return 0;
}