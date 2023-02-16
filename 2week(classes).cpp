#include <iostream>
#include <vector>
using namespace std;

class Langas{
    float aukstis, plotis;
    public:
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
    vector <Langas> langai_vector;
    vector <Durys> durys_vector;
    public:
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
    void add_durys(Durys papildomos_durys){
        durys_vector.push_back(papildomos_durys);
    }
    void add_langas(Langas papildomas_langas){
        langai_vector.push_back(papildomas_langas);
    }

    float skaiciuoti_sienos_plota(){
        float plotas = 0;
        plotas = (aukstis * ilgis * 2) + (aukstis * plotis * 2); // suskaiciuojamas plotas be langu, duru.
        for(int i = 0;i < langai_vector.size();++i){
            plotas = plotas - (langai_vector[i].get_aukstis() * langai_vector[i].get_plotis()); // atimamas visu langu plotas is bendro ploto
        }
        for(int i = 0;i < durys_vector.size();++i){
            plotas = plotas - (durys_vector[i].get_aukstis() * durys_vector[i].get_plotis()); // atimamas visu duru plotas is bendro ploto
        }
        return plotas;
    }

    float skaiciuoti_grindjuosciu_ilgi(){
        float grindjuosciu_ilgis = 0;
        grindjuosciu_ilgis = (2 * ilgis) + (2 * plotis); // grindu perimetras neatemus duru.
        for(int i = 0; i < durys_vector.size();++i){
            grindjuosciu_ilgis = grindjuosciu_ilgis - durys_vector[i].get_plotis(); // is viso grindu perimetro atimamas visu duru plotis.
        }
        return grindjuosciu_ilgis;
    }
};

int main(){
    Durys durys1, durys2;
    Langas langas1, langas2;
    Kambarys kambarys1;

    durys1.set_aukstis(5);
    durys2.set_aukstis(3);
    durys1.set_plotis(6);
    durys2.set_plotis(4);

    langas1.set_aukstis(2);
    langas2.set_aukstis(1);
    langas1.set_plotis(4);
    langas2.set_plotis(3);

    kambarys1.set_aukstis(10);
    kambarys1.set_ilgis(10);
    kambarys1.set_plotis(10);
    kambarys1.add_durys(durys1);
    kambarys1.add_durys(durys2);
    kambarys1.add_langas(langas1);
    kambarys1.add_langas(langas2);

    cout << "Kambario sienos plotas yra: " << kambarys1.skaiciuoti_sienos_plota() << endl;
    cout << "Kambario grindjuosciu ilgis yra: " << kambarys1.skaiciuoti_grindjuosciu_ilgi() << endl;
    return 0;
}