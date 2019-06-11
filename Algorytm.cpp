#include "Algorytm.h"
#include <vector>

void Algorytm::stworz(int graczSI)
{
    gra_komputer = graczSI;
    if (gra_komputer == krzyzyk){
        gra_czlowiek = kolko;
    } else {
        gra_czlowiek = krzyzyk;
    }
}

ruch_komputer Algorytm::najwiekszy_zysk(Plansza &plansza, int gracz)
{

    int ow = plansza.czy_wygrana();
    if(ow == gra_komputer) {
        return ruch_komputer(10);
    } else if (ow == gra_czlowiek) {
        return ruch_komputer(-10);
    }else if (ow == remis) {
        return ruch_komputer(0);
    }

    vector<ruch_komputer> tmc;


    for(int y = 0; y<plansza.wez_wymiar(); y++ ){
        for(int x = 0; x<plansza.wez_wymiar(); x++){
            if (plansza.jaka_wartosc(x, y) == brak_elem){
                ruch_komputer ruch;
                ruch.x = x;
                ruch.y = y;
                plansza.ustaw_wartosc(x, y, gracz);
                if (gracz == gra_komputer) {
                    ruch.wynik = najwiekszy_zysk(plansza, gra_czlowiek).wynik;
                } else {
                    ruch.wynik = najwiekszy_zysk(plansza, gra_komputer).wynik;
                }
                tmc.push_back(ruch);
                plansza.ustaw_wartosc(x,y, brak_elem);

            }
        }
    }

    int najlepszyRuch = 0;
    if (gracz == gra_komputer){
        int najlepiej1 = -1000000;
        for (size_t i = 0; i<tmc.size(); i++){
            if(tmc[i].wynik > najlepiej1 ) {
                najlepszyRuch = i;
                najlepiej1 = tmc[i].wynik;
            }
        }
    } else {
        int najlepiej2 = 1000000;
        for (size_t i = 0; i<tmc.size(); i++){
            if(tmc[i].wynik < najlepiej2 ) {
                najlepszyRuch = i;
                najlepiej2 = tmc[i].wynik;
            }
        }
    }

    return tmc[najlepszyRuch];
}


void Algorytm::ruch(Plansza &plansza)
{

	ruch_komputer najlepszy = najwiekszy_zysk(plansza, gra_komputer);

	plansza.ustaw_wartosc(najlepszy.x, najlepszy.y, gra_komputer);
}



