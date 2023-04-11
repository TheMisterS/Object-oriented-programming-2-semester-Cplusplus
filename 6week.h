#ifndef room2
#define room2
#include <bits/stdc++.h>
using namespace std;
class Langas{
    float aukstis, plotis;
    static int langu_skaicius;
    public:
    Langas(float norimas_aukstis, float norimas_plotis);
    void set_aukstis(float value);
    void set_plotis(float value);
    float get_aukstis();
    float get_plotis();
    static int get_kiekis();
    ~Langas();
};
int Langas::langu_skaicius = 0;

class Durys{
    float aukstis, plotis;
    static int duru_skaicius;
    public:
    Durys(float norimas_aukstis, float norimas_plotis);
    void set_aukstis(float value);
    void set_plotis(float value);
    float get_aukstis();
    float get_plotis();
    static int get_kiekis();
    ~Durys();
};
int Durys::duru_skaicius = 0;

class Kambarys{
    private:
    float aukstis, plotis, ilgis;
    vector <Langas*> langai_vector;
    Durys* durys_pointer;
    public:
    Kambarys(float norimas_aukstis, float norimas_plotis, float norimas_ilgis);
    Kambarys(const Kambarys &k);
    void set_aukstis(float value);
    void set_plotis(float value);
    void set_ilgis(float value);
    float get_aukstis();
    float get_plotis();
    float get_ilgis();
    Durys* get_durys();
    vector <Langas*> get_langai();
    void add_durys(Durys *papildomos_durys);
    void add_langas(Langas *papildomas_langas);
    Kambarys& operator=(const Kambarys& k);
    ~Kambarys();
};
#endif // room2

float skaiciuoti_sienos_plota(Kambarys norimas_kambarys);
float skaiciuoti_grindjuosciu_ilgi(Kambarys norimas_kambarys);