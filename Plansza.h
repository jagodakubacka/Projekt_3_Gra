#ifndef PLANSZA_H_INCLUDED
#define PLANSZA_H_INCLUDED
#include <iostream>

#define ROZMIAR 15

using namespace std;

const int krzyzyk = 1;
const int kolko = 2;
const int remis = -1;
const int brak_elem = 0;


class Plansza{
    int ile_rzad;
    int wymiar;
    int plansza[ROZMIAR][ROZMIAR] ;

public:
    void stworz(int rozmiar, int ilosc_wygrana);
    void wyswietl();
	int wez_wymiar();
	int czy_wygrana();
    int jaka_wartosc(int kolumna, int wiersz);
    void ustaw_wartosc(int kolumna, int wiersz, int wartosc);

};


#endif 


