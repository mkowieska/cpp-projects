#pragma once
#include <string>
using namespace std;


struct Zawodnik {
    string imie;
    string nazwisko;
};

struct Grupa {
    Zawodnik** zawodnicy = nullptr;
    int maxIloscZawodnikow = 100;
    int iloscZawodnikow = 0;
    size_t ilosc;
};

int WylosujLiczbe(int from, int to);

void gen_data(size_t& ilosc);

void gen_data(Zawodnik* zawodnik);

void Inicjalizuj(Zawodnik** zawodnik, const size_t ilosc);
void Stworz(Zawodnik**& zawodnik, const size_t ilosc);

void Stworz(Grupa*& grupa);
void stworz(Zawodnik*& zawodnik);
void stworz(Zawodnik**& zawodnicy, const size_t ilosc);
void stworz(Grupa*& grupa);
void stworz(Grupa**& grupy, const size_t ilosc);

void Dodaj(Zawodnik**& zawodnicy, int& ilosc);

void Wyswietl(Zawodnik** zawodnik, size_t ilosc);

void Usun(Zawodnik**& zawodnik, size_t ilosc);
void Usun(Zawodnik**& zawodnicy, int& ilosc, size_t index);
void usun(Zawodnik*& zawodnik);
void usun(Zawodnik**& zawodnicy, size_t& ilosc);
void usun(Grupa*& grupa);

void Wyczysc(Grupa& grupa);

bool WalidacjaImieniaLubNazwiska(const string& imie);//s

bool WalidacjaSlowa(const string& slowo);



/* //zakomentowane przez blad
std::string imiona[] = {
    "Paulina",
    "Zofia",
    "Maja",
    "Lena",
    "Hanna",
    "Julia",
    "Julianna",
    "Julita",
    "Paula",
    "Alicja",
    "Martyna",
    "Karolina",
    "Natalia",
    "Wiktoria",
    "Sara"
};
std::string nazwiska[] = {
    "Maliniak",
    "Nowak",
    "Kowalska",
    "Nowakowska",
    "Kowal",
    "Bukowska",
    "Pazurewicz",
    "Bakowicz",
    "Bukowska",
    "Celowicz",
    "Kanawecka",
    "Kowalewska",
    "Kobierska",
    "Konierska",
    "Kawiecka"
};
*/