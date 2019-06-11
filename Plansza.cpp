#include "Plansza.h"

void Plansza::stworz(int rozmiar, int ile_wygrana)
{
    wymiar = rozmiar;
    ile_rzad = ile_wygrana;
    for(int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++)
        {
            plansza[i][j]=brak_elem;
        }
    }
}

void Plansza::wyswietl(){
    for(int i=0;i<wymiar;i++)
    {
        for(int j=0;j<wymiar;j++)
        if(plansza[i][j]==brak_elem){cout << "#" << " ";}
		else if (plansza[i][j] == krzyzyk) { cout << "X" << " "; }
        else if(plansza[i][j]==kolko){cout << "O" << " ";}

    cout << endl;
    }
}

void Plansza::ustaw_wartosc(int kolumna, int wiersz, int wartosc){
    plansza[wiersz][kolumna] = wartosc;
}

int Plansza::jaka_wartosc(int kolumna, int wiersz){
    return plansza[wiersz][kolumna];
}

int Plansza::wez_wymiar(){
    return wymiar;
}

int Plansza::czy_wygrana()
{
    int liczba_o=0;
    int liczba_x=0;



    for(int i=0; i<wymiar; ++i)
    {
    liczba_o = 0;
    liczba_x = 0;

        for(int j=0; j<wymiar; ++j)
        {
            if(plansza[i][j]==kolko) {liczba_x = 0; liczba_o+=1;}
            if(plansza[i][j]==krzyzyk) {liczba_o = 0; liczba_x+=1;}
            if(plansza[i][j]==brak_elem) {liczba_o=0; liczba_x=0;}
        }

     if(liczba_o==ile_rzad) return kolko;
     if(liczba_x==ile_rzad) return krzyzyk;
     }

	for (int i = 0; i < wymiar; ++i)
	{
		liczba_o = 0;
		liczba_x = 0;

		for (int j = 0; j < wymiar; ++j)
		{
			if (plansza[j][i] == kolko) { liczba_x = 0; liczba_o += 1; }
			if (plansza[j][i] == krzyzyk) { liczba_o = 0; liczba_x += 1; }
			if (plansza[j][i] == brak_elem) { liczba_o = 0; liczba_x = 0; }
		}

		if (liczba_o == ile_rzad) return kolko;
		if (liczba_x == ile_rzad) return krzyzyk;
	}


    for(int i=0; i<wymiar; ++i)
    {
    liczba_o = 0;
    liczba_x = 0;

        for(int j=0; j<wymiar; ++j)
        {
            if(plansza[j][i]==kolko) {liczba_x = 0; liczba_o+=1;}
            if(plansza[j][i]==krzyzyk) {liczba_o = 0; liczba_x+=1;}
            if(plansza[j][i]==brak_elem) {liczba_o=0; liczba_x=0;}
        }

     if(liczba_o==ile_rzad) return kolko;
     if(liczba_x==ile_rzad) return krzyzyk;
    }

    for(int i = 0; i<(wymiar-ile_rzad+1); ++i){

        liczba_o = 0;
        liczba_x = 0;

        for(int j=0; j<wymiar-i; ++j)
        {
            if(plansza[j][j+i]==kolko) {liczba_x = 0; liczba_o+=1;}
            if(plansza[j][j+i]==krzyzyk) {liczba_o = 0; liczba_x+=1;}
            if(plansza[j][j+i]==brak_elem) {liczba_o=0; liczba_x=0;}
        }

    if(liczba_o==ile_rzad) return kolko;
    if(liczba_x==ile_rzad) return krzyzyk;
    }


	for (int i = 0; i < (wymiar - ile_rzad + 1); ++i) {

		liczba_o = 0;
		liczba_x = 0;

		for (int j = 0; j < wymiar - i; ++j)
		{
			if (plansza[j + i][j] == kolko) { liczba_x = 0; liczba_o += 1; }
			if (plansza[j + i][j] == krzyzyk) { liczba_o = 0; liczba_x += 1; }
			if (plansza[j + i][j] == brak_elem) { liczba_o = 0; liczba_x = 0; }
		}

		if (liczba_o == ile_rzad) return kolko;
		if (liczba_x == ile_rzad) return krzyzyk;
	}




    for(int i = 0; i<(wymiar-ile_rzad+1); ++i){

        liczba_o = 0;
        liczba_x = 0;

        for(int j=0; j<wymiar; ++j)
        {
            if(plansza[j][wymiar-1-j-i]==kolko) {liczba_x = 0; liczba_o+=1;}
            if(plansza[j][wymiar-1-j-i]==krzyzyk) {liczba_o = 0; liczba_x+=1;}
            if(plansza[j][wymiar-1-j-i]==brak_elem) {liczba_o=0; liczba_x=0;}
        }

        if(liczba_o==ile_rzad) return kolko;
        if(liczba_x==ile_rzad) return krzyzyk;
    }

	for (int i = 0; i < (wymiar - ile_rzad + 1); ++i) {

		liczba_o = 0;
		liczba_x = 0;

		for (int j = 0; j < wymiar; ++j)
		{
			if (plansza[j + i][wymiar - 1 - j] == kolko) { liczba_x = 0; liczba_o += 1; }
			if (plansza[j + i][wymiar - 1 - j] == krzyzyk) { liczba_o = 0; liczba_x += 1; }
			if (plansza[j + i][wymiar - 1 - j] == brak_elem) { liczba_o = 0; liczba_x = 0; }
		}

		if (liczba_o == ile_rzad) return kolko;
		if (liczba_x == ile_rzad) return krzyzyk;
	}

    for(int i=0;i<wymiar;i++)
    {
        for(int j=0;j<wymiar;j++)
        {
            if(plansza[i][j] == brak_elem) return brak_elem; //zwraca brak elementow
        }
    }

    return remis;
}



