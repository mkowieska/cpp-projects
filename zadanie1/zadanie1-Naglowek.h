#pragma once
#include <string>

struct Zawodnik {
    std::string imie;
    std::string nazwisko;
};
struct Akademia {
    Zawodnik** zawodnicy = nullptr;
    int maxIloscZawodnikow = 10;
    int iloscZawodnikow = 0;
    size_t ilosc;
};

void Inicjalizuj(Zawodnik** zawodnik, const size_t ilosc);
void Stworz(Zawodnik**& zawodnik, const size_t ilosc);
void Stworz(Akademia*& Arcos);
void Wyswietl(Zawodnik** zawodnik, size_t ilosc);
void Usun(Zawodnik**& zawodnik, size_t ilosc);
void Wyczysc(Akademia& Arcos);
void gen_data(size_t&);