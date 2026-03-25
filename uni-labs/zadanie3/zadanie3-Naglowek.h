#pragma once
#include <string>;
#include <iostream>;

using namespace std;

int WylosujLiczbe(int from, int to);

class Zawodnik { 
    string imie;
    string nazwisko;
public:
    Zawodnik(const string& imie, const string& nazwisko); //konstruktor
    void Wyswietl();
};

class Grupa {
    int maxIloscZawodnikow = 10;
    int iloscZawodnikow = WylosujLiczbe(0, maxIloscZawodnikow);
    Zawodnik** zawodnicy = nullptr;
    Zawodnik* InicjalizujZawodnika(); //obiekt
    //bo wiele razy uzywam w kodzie w wielu funkcjach
public:
    Grupa(int iloscZawodnikow);
    ~Grupa(); //destruktor 
    void DodajZawodnika();
    void EdytujZawodnika(const Zawodnik& nowyZawodnik);
    void WyswietlWszystkichZawodnikow();
    void UsunLosowoZawodnika();
    void Wyczysc();
    int PobierzLiczbeZawodnikow();
    size_t ilosc{};
};

void gen_data(size_t& ilosc);

bool WalidacjaImieniaLubNazwiska(const string& s);

bool WalidacjaSlowa(const string& s);

void usun(Zawodnik*& zawodnik);
void usun(Zawodnik*& zawodnik, const size_t ilosc);
void usun(Zawodnik**& zawodnicy, size_t& ilosc);
void usun(Zawodnik**& wszyscy, size_t& ilosc, size_t index);