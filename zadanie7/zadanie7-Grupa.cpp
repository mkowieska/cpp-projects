#include "Nag³ówek77.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


istream& operator>>(istream& input, Grupa& V) {
    for (int i = 0; i < V.IloscZawodnikow; i++) {
        Zawodnik* zawodnik = V.InicjalizujZawodnika();
        input >> *zawodnik;
        V.zawodnicy.push_back(zawodnik); //dodaje nowy element na koñcu kontenera vector
    }

    return input;
}

ostream& operator<<(ostream& output, const Grupa& V) {
    output << setfill('-') << setw(50) << "--" << endl;
    output << "Zawodnicy" << endl;
    output << setfill('-') << setw(50) << "--" << endl;
    output << "Liczba zawodnikow: " << V.zawodnicy.size() << endl;
    output << setfill('-') << setw(50) << "--" << endl;
    for (const auto& zawodnik : V.zawodnicy) {
        output << zawodnik << endl;
    }
    output << endl;
    output << setfill('-') << setw(50) << "--" << endl;
    return output;
}