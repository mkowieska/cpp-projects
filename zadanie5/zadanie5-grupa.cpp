#include "wyslac-Naglowek5.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


Grupa::Grupa(int _IloscZawodnikow) {
    IloscZawodnikow = _IloscZawodnikow;
    zawodnicy = new Zawodnik * [IloscZawodnikow];
    for (int i = 0; i < _IloscZawodnikow; i++) {
        zawodnicy[i] = InicjalizujZawodnika();
    }
}

Grupa::Grupa(const Grupa& Volley) {
    IloscZawodnikow = Volley.IloscZawodnikow;
    maxIloscZawodnikow = Volley.maxIloscZawodnikow;
    zawodnicy = new Zawodnik * [maxIloscZawodnikow];
    for (int i = 0; i < IloscZawodnikow; i++) {
        zawodnicy[i] = new Zawodnik(*Volley.zawodnicy[i]);
    }
}

Grupa::~Grupa() {
    for (size_t i = 0; i < IloscZawodnikow; i++) {
        delete zawodnicy[i];
    }
    delete[] zawodnicy;
}

Grupa& Grupa::operator=(const Grupa& V) {
    if (&V != this) {
        this->Grupa::~Grupa();
        this->Grupa::Grupa(V);
    }
    return *this;
}

istream& operator>>(istream& input, Grupa& V) {
    for (int i = 0; i < V.IloscZawodnikow; i++) {
        input >> *V.zawodnicy[i];
    }
    return input;
}

ostream& operator<<(ostream& output, const Grupa& V) {
    output << setfill('-') << setw(50) << "--" << endl;
    output << "Zawodnicy" << endl;
    output << setfill('-') << setw(50) << "--" << endl;
    output << "Liczba zawodnikow: " << V.IloscZawodnikow << endl;
    output << setfill('-') << setw(50) << "--" << endl;
    for (int i = 0; i < V.IloscZawodnikow; i++) {
        output << *(V.zawodnicy[i]) << endl;
    }
    output << endl;
    output << setfill('-') << setw(50) << "--" << endl;
    return output;
};