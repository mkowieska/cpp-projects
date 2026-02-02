#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <locale>
#include <cstdlib>

#include "Naglowek.h"

std::string imiona[] = {
    "Paulina",
    "Zofia",
    "Maja",
    "Lena",
    "Hanna",
    "Julia",
};
std::string nazwiska[] = {
    "Maliniak",
    "Nowak",
    "Kowalska",
    "Nowakowska",
    "Kowal",
    "Bukowska",
};

void Inicjalizuj(Zawodnik** zawodnik, const size_t ilosc) {
    for (size_t i = 0; i < ilosc; i++) {
        int iloscImion = sizeof(imiona) / sizeof(imiona[0]);
        int iloscNazwisk = sizeof(nazwiska) / sizeof(nazwiska[0]);

        Zawodnik* newZawodnik = new Zawodnik();
        zawodnik[i] = newZawodnik;
        int imieIndex = rand() % iloscImion;
        int nazwiskoIndex = rand() % iloscNazwisk;

        newZawodnik->imie = imiona[imieIndex];
        newZawodnik->nazwisko = nazwiska[nazwiskoIndex];
    }
}

void Stworz(Zawodnik**& zawodnik, const size_t ilosc) {
    zawodnik = new Zawodnik * [ilosc];
    for (size_t ind = 0; ind < ilosc; ind++)
        zawodnik[ind] = new Zawodnik;
}
void Stworz(Akademia*& Arcos) {
    size_t ilosc{ 0 };
    gen_data(ilosc);
    Zawodnik** zespoly{ nullptr };
    Stworz(zespoly, ilosc);
    Arcos = new Akademia;
    Arcos->zawodnicy = zespoly;
    Arcos->ilosc = ilosc;
}
void Wyswietl(Zawodnik** zawodnik, size_t ilosc)
{
    for (size_t i = 0; i < ilosc; i++)
    {
        Zawodnik* wyswietlZawodnika = zawodnik[i];
        std::cout << "Imie " << wyswietlZawodnika->imie << std::endl;
        std::cout << "Nazwisko " << wyswietlZawodnika->nazwisko << std::endl;
    }
}

void Usun(Zawodnik**& zawodnik, size_t ilosc) {
    for (size_t i = 0; i < ilosc; i++) {
        if (zawodnik[i] != nullptr) {
            delete zawodnik[i];
            zawodnik[i] = nullptr;
        }
    }
    delete[] zawodnik;
}

void Wyczysc(Akademia& Arcos) {
    if (nullptr != Arcos.zawodnicy) {
        Arcos.iloscZawodnikow = 0;
        Usun(Arcos.zawodnicy, Arcos.iloscZawodnikow);
    }
}
void gen_data(size_t& num) {
    static std::random_device rd;
    static std::default_random_engine dfe(rd());
    static std::uniform_int_distribution<int> rozmiar(30, 50);
    num = rozmiar(dfe);
}