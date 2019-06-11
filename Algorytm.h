#ifndef ALGORYTM_H_INCLUDED
#define ALGORYTM_H_INCLUDED
#include "Plansza.h"

struct ruch_komputer{
    ruch_komputer() {};
    ruch_komputer(int Wynik) : wynik(Wynik) {}
    int x;
    int y;
    int wynik;
};

class Algorytm{
public:
    void stworz(int graczSI);
    void ruch(Plansza &plansza);
private:
    ruch_komputer najwiekszy_zysk(Plansza &plansza, int gracz);
	int gra_czlowiek;
    int gra_komputer;
    
};


#endif 