#include <iostream>
#include <cstring>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <stdexcept>
#include <random>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include "Naglowek44.h"

using namespace std;

Grupa::Grupa(int ilosc) {
    IloscZawodnikow = ilosc;
    zawodnicy = new Zawodnik * [ilosc];

    for (size_t i = 0; i < ilosc; i++) {
        zawodnicy[i] = InicjalizujZawodnika();
    }
}

Grupa::Grupa(const Grupa& other) {
    maxIloscZawodnikow = other.maxIloscZawodnikow;
    IloscZawodnikow = other.IloscZawodnikow;
    zawodnicy = new Zawodnik * [maxIloscZawodnikow];
    for (int i = 0; i < IloscZawodnikow; i++) {
        zawodnicy[i] = new Zawodnik(*other.zawodnicy[i]);
    }
}

Grupa::~Grupa() { 
    for (size_t i = 0; i < IloscZawodnikow; i++) {
        delete zawodnicy[i];
    }
    delete[] zawodnicy;
}

void Grupa::DodajZawodnika() {
    if (IloscZawodnikow < maxIloscZawodnikow) {
        Zawodnik** temp = new Zawodnik * [IloscZawodnikow + 1];

        for (size_t i = 0; i < IloscZawodnikow; i++) {
            temp[i] = zawodnicy[i];
        }
        delete[] zawodnicy;
        zawodnicy = temp;

        zawodnicy[IloscZawodnikow] = InicjalizujZawodnika();

        ++IloscZawodnikow;
        cout << "Zawodnik dodany." << endl;

    }
    else {
        cout << "Blad." << endl;
    }
}
void Grupa::WyswietlWszystkichZawodnikow() {
    for (size_t i = 0; i < IloscZawodnikow; i++) {
        if (nullptr != zawodnicy[i]) {
            zawodnicy[i]->Wyswietl();
        }
        else {
            cout << "Brak zawodnikow." << endl;
            break;
        }
    }
}
void Grupa::WyswietlLosowegoZawodnika()
{
    int losIndex = WylosujLiczbe(0, IloscZawodnikow - 1);
    zawodnicy[losIndex];
    zawodnicy[losIndex]->DodajIdKolejne();
}

void Grupa::UsunLosowoZawodnika() {
    if (IloscZawodnikow < 1) {
        cout << "Nie ma osob." << endl;
        return;
    }

    int losowyIndex = WylosujLiczbe(0, IloscZawodnikow - 1);

    if (nullptr != zawodnicy[losowyIndex]) {
        delete zawodnicy[losowyIndex];
        zawodnicy[losowyIndex] = nullptr;
        --IloscZawodnikow;
        cout << "Zawodnik usuniety." << endl;
        cout << IloscZawodnikow << endl;
    }
    else {
        cout << "Blad." << endl;
    }
}

void Grupa::Edytuj(const Zawodnik& nowyZawodnik) {
    int losowyIndex = WylosujLiczbe(0, IloscZawodnikow - 1);

    if (nullptr != zawodnicy[losowyIndex]) {
        delete zawodnicy[losowyIndex];
        zawodnicy[losowyIndex] = new Zawodnik(nowyZawodnik);
    }
    else {
        cout << "Blad." << endl;
    }
}

int Grupa::GetLiczbeZawodnikow() {
    return IloscZawodnikow;
}

void Grupa::Wyczysc() {
    if (zawodnicy != nullptr) {
        for (int i = 0; i < IloscZawodnikow; i++) {
            delete zawodnicy[i];
        }
        delete[] zawodnicy;
        zawodnicy = nullptr;
        IloscZawodnikow = 0;
    }
}



void Grupa::WyswietlIdLosowegoZawodnika(){
    int losIndex = WylosujLiczbe(0, IloscZawodnikow - 1);
    zawodnicy[losIndex]->Wyswietl();
    zawodnicy[losIndex]->WyswietlIds();
}

void Grupa::Lista(const string& druzyna){
    for (size_t i = 0; i < IloscZawodnikow; i++)  {
        if (nullptr != zawodnicy[i] && zawodnicy[i]->GetDruzyne() == druzyna) {
            zawodnicy[i]->Wyswietl();
        }
    }
}