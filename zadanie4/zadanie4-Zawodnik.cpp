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
#include "Naglowek44.h"

using namespace std;

Zawodnik::Zawodnik() {}
Zawodnik::Zawodnik(const string& _imie, const string& _nazwisko, const string& _druzyna)
    : imie(_imie), nazwisko(_nazwisko), druzyna(_druzyna){}
Zawodnik::Zawodnik(size_t& _iloscId, Id**& _id_s, const string& _imie, const string& _nazwisko,const string& _druzyna)
    : iloscId(_iloscId), ids(_id_s), imie(_imie), nazwisko(_nazwisko), druzyna(_druzyna){}

/*
Zawodnik::Zawodnik(const Zawodnik& zaw) : id_zawodnika{ zaw.id_zawodnika } {
    imie = zaw.imie;
    nazwisko = zaw.nazwisko;
}
*/

Zawodnik::~Zawodnik()
{
    for (size_t i = 0; i < iloscId; i++)
    {
        delete ids[i];
    }
    delete[] ids;
    ids = nullptr;
    iloscId = 0;

}
void Zawodnik::Wyswietl() {
    cout << " " << endl;
    cout << "Imie: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    std::cout << "Druzyna: " << druzyna << endl;
}

string Zawodnik::GetDruzyne() {
    return druzyna;
}

size_t Zawodnik::GetIloscIds() {
    return iloscId;
}

void Zawodnik:: WyswietlIds() {
    for (size_t i = 0; i < iloscId; i++) {
        if (ids[i] != nullptr) {
            cout << "Id: " << ids[i]->getWartosc() << endl;
        }
        else {
            cout << "Blad. " << endl;
        }
    }
}


//id

void Zawodnik::DodajId() {
    auto temp = new Id * [iloscId + 1];
    if (iloscId == 0) {
        temp[iloscId] = new Id;
    }
    else {
        for (size_t i = 0; i < iloscId; i++)
        {
            temp[i] = ids[i];
        }
        temp[iloscId] = new Id;
        delete[] ids;
    }
    ids = temp;

    int nowaId = 0;
    cout << "Wpisz id (1-10): ";
    cin >> nowaId;
    if ((nowaId > 11) || (nowaId < 1))
    {
        cout << "Blad. " << endl;
        return;
    }

    ids[iloscId] = new Id(nowaId);

    cout << "Id stworzony. "<<endl;
    ids++;
}




/*
void usun(Zawodnik*& zawodnik) {
    delete zawodnik;
    zawodnik = nullptr;
}
void usun(Zawodnik*& zawodnik, const size_t ilosc) {
    delete[] zawodnik;
    zawodnik = nullptr;
}
void usun(Zawodnik**& zawodnicy, size_t& ilosc) {
    for (size_t ind = 0; ind < ilosc; ind++)
        delete zawodnicy[ind];
    delete[] zawodnicy;
    zawodnicy = nullptr;
    ilosc = 0;
}
void usun(Zawodnik**& wszyscy, size_t& ilosc, size_t index) {
    if (index < ilosc) {
        Zawodnik** temp = new Zawodnik * [ilosc - 1];
        short int j{ -1 };
        for (size_t i = 0; i < ilosc; ++i)
            if (i != index) {
                ++j;
                temp[j] = wszyscy[i];
            }
        usun(wszyscy, ilosc);
        wszyscy = temp;
        --ilosc;
    }
    else
        cout << "Blad." << endl;
}*/