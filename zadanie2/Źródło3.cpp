#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <locale>
#include <stdexcept>
#include <random>
#include <ctype.h>

import <cstdlib>;
import <iostream>;
import <string>;
import <sstream>;
import <ctype.h>;
import <random>;

#include "Nagłówek3.h"
using namespace std;

string imiona[] = {
    "Paulina",
    "Zofia",
    "Maja",
    "Lena",
    "Hanna",
    "Julia",
};
string nazwiska[] = {
    "Maliniak",
    "Nowak",
    "Kowalska",
    "Nowakowska",
    "Kowal",
    "Bukowska",
};
int WylosujLiczbe(int from, int to) { 
    random_device random; //generuje losowe liczby
    default_random_engine engine{ random() }; 
    uniform_int_distribution <unsigned> zawodnik(from, to); 
    return zawodnik(engine);
}

void gen_data(size_t& ilosc) {
    static random_device rd;
    static default_random_engine dfe(rd());
    static uniform_int_distribution<int> rozmiar(0, 50);
    ilosc = rozmiar(dfe);
}

void gen_data(Zawodnik* zawodnik) {
    static random_device rd;
    static default_random_engine dfe(rd());
    static uniform_int_distribution<int> numerDist(1, 1000);
    size_t ilosc = numerDist(dfe);
    zawodnik->imie = "Maria" + to_string(ilosc);
    zawodnik->nazwisko = "Nowak" + to_string(ilosc);
}

void Inicjalizuj(Zawodnik** zawodnik, const size_t ilosc) {
    int iloscImion = sizeof(imiona) / sizeof(imiona[0]);
    int iloscNazwisk = sizeof(nazwiska) / sizeof(nazwiska[0]);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> imieDist(0, iloscImion - 1);
    uniform_int_distribution<int> nazwiskoDist(0, iloscNazwisk - 1);

    for (size_t i = 0; i < ilosc; i++) {
        Zawodnik* newZawodnik = new Zawodnik();
        zawodnik[i] = newZawodnik;

        int imieIndex = imieDist(gen);
        int nazwiskoIndex = nazwiskoDist(gen);

        newZawodnik->imie = imiona[imieIndex];
        newZawodnik->nazwisko = nazwiska[nazwiskoIndex];
    }
}

void Stworz(Zawodnik**& zawodnik, const size_t ilosc) {
    zawodnik = new Zawodnik * [ilosc];
}

void Stworz(Grupa*& grupa) {
    size_t ilosc{ 0 };
    gen_data(ilosc);
    Zawodnik** grupy{ nullptr };
    Stworz(grupy, ilosc);
    grupa = new Grupa;
    grupa->zawodnicy = grupy;
    grupa->ilosc = ilosc;
}
void stworz(Zawodnik*& zawodnik) {
    zawodnik = new Zawodnik;
    gen_data(zawodnik);
}
void stworz(Zawodnik**& zawodnicy, const size_t ilosc) {
    zawodnicy = new Zawodnik * [ilosc];
    for (size_t ind = 0; ind < ilosc; ind++)
        stworz(zawodnicy[ind]);
}
void stworz(Grupa*& grupa) {
    size_t ilosc{ 0 };
    gen_data(ilosc);
    Zawodnik** zawodnicy{ nullptr };
    stworz(zawodnicy, ilosc);
    grupa = new Grupa;
    grupa->zawodnicy = zawodnicy;
    grupa->ilosc = ilosc;
}
void stworz(Grupa**& grupy, const size_t ilosc) {
    grupy = new Grupa * [ilosc];
    for (size_t ind = 0; ind < ilosc; ind++)
        grupy[ind] = new Grupa;
}

void Dodaj(Zawodnik**& zawodnicy, int& ilosc) {
    Zawodnik** temp = new Zawodnik * [ilosc + 1];
    if (ilosc == 0) {
        temp[ilosc] = new Zawodnik;
    }
    else {
        for (size_t i = 0; i < ilosc; ++i) {
            temp[i] = zawodnicy[i];
        }
        temp[ilosc] = new Zawodnik; 
        delete[] zawodnicy;
    }
    zawodnicy = temp;
    ++ilosc;

    int iloscImion = sizeof(imiona) / sizeof(imiona[0]);
    int iloscNazwisk = sizeof(nazwiska) / sizeof(nazwiska[0]);

    int ImieIndex = WylosujLiczbe(0, iloscImion);
    int IndexNazwisko = WylosujLiczbe(0, iloscNazwisk);

    zawodnicy[ilosc - 1]->imie = imiona[ImieIndex];
    zawodnicy[ilosc - 1]->nazwisko = nazwiska[IndexNazwisko];
}

void Wyswietl(Zawodnik** zawodnik, size_t ilosc) {
    for (size_t i = 0; i < ilosc; i++) {
        Zawodnik* wyswietlZawodnika = zawodnik[i];
        cout << "Imie " << wyswietlZawodnika->imie << endl;
        cout << "Nazwisko " << wyswietlZawodnika->nazwisko << endl;
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
void Usun(Zawodnik**& zawodnicy, int& ilosc, size_t index) {
    if (index < ilosc) {
        Zawodnik** temp = new Zawodnik * [ilosc - 1];
        int j = -1;
        for (size_t i = 0; i < ilosc; ++i) {
            if (i != index) {
                ++j;
                temp[j] = zawodnicy[i];
            }
        }
        delete[] zawodnicy;
        zawodnicy = temp;
        --ilosc;
    }
}
void usun(Zawodnik*& zawodnik) {
    delete zawodnik;
    zawodnik = nullptr;
}
void usun(Zawodnik**& zawodnicy, size_t& ilosc) {
    for (size_t ind = 0; ind < ilosc; ind++)
        usun(zawodnicy[ind]);
    delete[] zawodnicy;
    zawodnicy = nullptr;
    ilosc = 0;
}
void usun(Grupa*& grupa) {
    usun(grupa->zawodnicy, grupa->ilosc);
    delete grupa;
    grupa = nullptr;
}

void Wyczysc(Grupa& grupa) {
    if (grupa.zawodnicy != nullptr) {
        grupa.iloscZawodnikow = 0;
        Usun(grupa.zawodnicy, grupa.iloscZawodnikow);
    }
}

bool WalidacjaImieniaLubNazwiska(const string& s) {
    for (char c : s) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}
/*
bool WalidacjaImieniaLubNazwiska(const string& s) {
    if (!isalpha(s[0])) {
        return false;
    }
    for (size_t i = 1; i < s.size(); i++) {
        if (!isalpha(s[i])) {
            return false;
        }
    }
    return true;
}*/

bool WalidacjaSlowa(const string& slowo) {
    for (size_t i = 0; i < slowo.size(); i++) {
        if (false == isalpha(slowo[i])) {
            return false;
        }
    }
    return true;
}