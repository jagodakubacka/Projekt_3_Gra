#include "Gra.h"
#include <string>



void Gra::stworz()
{
  int N,x;
  cout << "\n********************************\n";
  cout<<"******* KOLKO I KRZYZYK! *******\n";
  cout << "********************************\n";
  cout<<"\n Zasady gry:\n";
  cout << "\n Gra ta polega na umiejscowieniu znakow w tej samej linii szybciej ni¿ Twoj przeciwnik!\n";
  cout << "\n Mozesz wybrac tryb gry - multiplayer lub gre z komputerem. Przed rozpoczeciem gry pomysl nad strategia!\n";
  cout<<"\n Minimalny rozmiar tablicy to 3. Maksymalny to 15!\n";
  cout << "\n Milej zabawy!!!!";
  cout << "\n Wpisz rozmiar tablicy (NxN):\n";
  cout<<" N = "; cin>>N;
  cout << "\n Wpisz liczbe elementow w rzedzie (x): \n";
  cout<<" x = "; cin>>x;

  status = GRA;
  plan.stworz(N, x);
  aktualny = krzyzyk;



  cout<<"\n\n Czy chcesz zagrac w tryb multiplayer, czyli z druga osoba? Jezeli tak, to wybierz t, jezeli chcesz zagrac z komputerem wybierz n.\n";
  bool czyPrawidlowy;
  char multi;

  do{
    czyPrawidlowy = true;
    if (!(cin >> multi)) {
        cout << "Blad!";
        cin.clear();
        cin.ignore(1000, '\n');
        czyPrawidlowy = false;
    } else if (multi == 't' || multi == 'T'){
        multiplayer = true;
    } else {
        multiplayer = false;
    }
  } while (czyPrawidlowy == false);

  if (!multiplayer){
    cout << "\n Teraz wybierz symbol, ktory chcesz uzywac w grze. Chcesz byc O czy X? \n(O/X): ";

    do{
       czyPrawidlowy = true;

        if (!(cin >> multi)) {
            cout << "Blad!";
            cin.clear();
            cin.ignore(1000, '\n');
            czyPrawidlowy = false;
       } else if (multi == 'x' || multi == 'X' ){
            komputer = kolko;
       } else if (multi == 'o' || multi == 'O' ){
            komputer = krzyzyk;
       } else {
            cout <<"Blad! Wpisz X lub O!";
            czyPrawidlowy = false;
       }
    }while (czyPrawidlowy == false);

    algorytm.stworz(komputer);
    }
    cout<<"\n\n";
}
void Gra::start()
{
	stworz();

	while (status != WYJSCIE) {
		plan.wyswietl();

		if (aktualny == kolko) {
			cout << "\n\n Czas na gracza z symbolem kolka!\n\n";
			
		}
		else {
			cout << "\n\n Czas na gracza z symbolem krzyzyk!\n\n";
		}

		if (!multiplayer && aktualny == komputer) {
			ruch_komputera();
		}
		else {
			ruch_gracza();
		}

		int ow = plan.czy_wygrana();
		if (ow != brak_elem) {
			koniec(ow == remis);
		}
		else {
			inny_gracz();

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}
	}
}
void Gra::ruch_gracza()
{
    bool bylDobry = false;
    int x,y;

    do{
        cout << "Numer kolumny: ";
        while (!(cin >> x)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Blad!";
        }
        cout << "Numer wiersza: ";
        while (!(cin >> y)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Blad!";
        }

        if (x < 1 || y < 1 || x > plan.wez_wymiar() || y > plan.wez_wymiar()){
            cout << " Wprowadz inne dane, poniewaz te sa bledne!\n";
        } else if (plan.jaka_wartosc(x-1, y-1) != brak_elem){
            cout << " W tym miejscu jest juz symbol! :( \n";
        } else {
            bylDobry = true;
        }
    } while (!bylDobry);

    plan.ustaw_wartosc(x-1, y-1, aktualny);
}

void Gra::ruch_komputera()
{
    algorytm.ruch(plan);
}

void Gra::inny_gracz()
{
    if(aktualny == krzyzyk){
        aktualny = kolko;
    } else {
        aktualny = krzyzyk;
    }
}


void Gra::koniec(bool bylRemis){

    plan.wyswietl();

    if(bylRemis){
        cout << "\n\n REMIS! Wcisnij cokolwiek by rozpoczac gre ponownie\n";
        cout << " lub Z zeby zakonczyc: ";
    } else {
        if (aktualny == kolko){
            cout << "\n\n WYGRANA KOLKA! Wcisnij cokolwiek by rozpoczac gre ponownie\n";
            cout << " lub Z zeby zakonczyc: ";
        } else {
            cout << "\n\n WYGRANA KRZYZYKA! Wcisnij cokolwiek by rozpoczac gre ponownie\n";
            cout << " lub Z zeby zakonczyc: ";
        }

    }

    char wej;
    cin >> wej;
    if(wej == 'Z' || wej == 'z'){
        status = WYJSCIE;
    } else {
        stworz();
    }
}

