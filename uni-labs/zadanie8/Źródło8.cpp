#include "Naglowek8.h"
#include <string>
#include <random>       
#include <iostream>        
#include <ctime>
#include <vector>

using namespace std;

vector <string> imiona{
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

vector <string> nazwiska{
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

vector <string> druzyny{
    "<9",
    "9-10",
    "11-12",
    "13-14",
    "15-16",
    "17-18",
    "19-20",
    "20",
    "Pary",
    "Studenci(20-24)"
};

int WylosujLiczbe(int from, int to) { //zmienic nazwe
    random_device random;
    default_random_engine engine{ random() };
    uniform_int_distribution <unsigned> rando(from, to);
    return rando(engine);
}

Zawodnik* Grupa::InicjalizujZawodnika() {
    int ImieIndex = WylosujLiczbe(0, imiona.size() - 1);
    int NazwiskoIndex = WylosujLiczbe(0, nazwiska.size() - 1);
    int DruzynaIndex = WylosujLiczbe(0, druzyny.size() - 1);
    int losDzien = 0;
    int losMiesiac = WylosujLiczbe(1, 12);
    if (losMiesiac == 2) {
        losDzien = WylosujLiczbe(1, 28);
    }
    else if ((losMiesiac == 1) || (losMiesiac == 3) || (losMiesiac == 5) || (losMiesiac == 7) || (losMiesiac == 8) || (losMiesiac == 10) || (losMiesiac == 12)) {
        losDzien = WylosujLiczbe(1, 31);
    }
    else
        losDzien = WylosujLiczbe(1, 30);

    int losRok = 2023 - WylosujLiczbe(7, 24);
    size_t iloscId = 1;

    Zawodnik* newZawodnik = new Zawodnik(imiona.at(ImieIndex), nazwiska.at(NazwiskoIndex), druzyny.at(DruzynaIndex), losDzien, losMiesiac, losRok);
    return newZawodnik;
}


bool WalidacjaImieniaLubNazwiska(const string& s) {
    for (char c : s) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool WalidacjaSlowa(const string& s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (false == isalpha(s[i])) {
            return false;
        }
    }
    return true;
}

/*
void gen(size_t& ilosc) {
    static random_device rd;
    static default_random_engine dfe(rd());
    static uniform_int_distribution<int> rozmiar(10, 50);
    ilosc = rozmiar(dfe);
}

size_t generujLosowa(size_t begin, size_t end) {
    static random_device seed;     // ziarno poczatkowe
    static mt19937 engine(seed()); // generator
    static uniform_int_distribution<size_t> uniformDist(begin, end);
    return uniformDist(engine);
}*/