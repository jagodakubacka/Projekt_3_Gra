#ifndef GRA_H_INCLUDED
#define GRA_H_INCLUDED
#include "Plansza.h"
#include "Algorytm.h"


enum Stan {GRA, WYJSCIE};

class Gra{
public:
    void start();

private:
    void stworz();
	void koniec(bool bylRemis);
    void ruch_gracza();
    void ruch_komputera();
    void inny_gracz();


    Plansza plan;
    int aktualny;
    int komputer;
    Stan status;
    Algorytm algorytm;
    bool multiplayer;
};
#endif 


