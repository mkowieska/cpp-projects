#include "Naglowek8.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

istream& operator>>(istream& input, Zawodnik::Id& i) {
    input >> i.numer;
    return input;

}

ostream& operator<<(ostream& output, const Zawodnik::Id i) {
    output << i.numer;
    return output;
}

void Zawodnik::DodajId() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis(1, 100);
    int id = dis(gen);

    ids.push_back(Id(id));
    iloscId++;
}


//-------------------------------------------------------------------------------------------------------------------
//ZADEKLAROWANE W ZAWODNIK

void Zawodnik::WyswietlIds() {
    for (const auto& id : ids) {
        cout << "Numer: " << id.getNumer() << endl;
    }
}


//-------------------------------------------------------------------------------------------------------------------
//ZADEKLAROWANE W GRUPIE
// OPERATOR []

void Grupa::DodajIdLosowemuZawodnikowi(Grupa& Volley) {
    int losIndex = WylosujLiczbe(0, Volley.IloscZawodnikow - 1);
    Volley.zawodnicy[losIndex]->DodajIdKolejne();
}

void Grupa::WyswietlIdLosowegoZawodnika() {
    int losIndex = WylosujLiczbe(0, IloscZawodnikow - 1);
    zawodnicy[losIndex]->Wyswietl();
    zawodnicy[losIndex]->WyswietlIds();
}