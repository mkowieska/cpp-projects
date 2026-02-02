#include "Naglowek6.h"
#include <iostream>
#include <string>
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

    cout << "Id stworzony. " << endl;
    iloscId++;
}


//-------------------------------------------------------------------------------------------------------------------
//ZADEKLAROWANE W ZAWODNIK

void Zawodnik::WyswietlIds() {
    for (size_t i = 0; i < iloscId; i++) {
        if (ids[i] != nullptr) {
            cout << "Numer: " << ids[i]->getNumer() << endl;
        }
        else {
            cout << "Blad. " << endl;
        }
    }
}


//-------------------------------------------------------------------------------------------------------------------
//ZADEKLAROWANE W GRUPIE
// OPERATOR []

void Grupa::DodajIdLosowemuZawodnikowi(Grupa& Volley) {  
    int losIndex = WylosujLiczbe(0, Volley.getLiczbeZawodnikow() - 1);
    Volley[losIndex];
    Volley[losIndex].DodajIdKolejne();
}

void Grupa::WyswietlIdLosowegoZawodnika() {
    int losIndex = WylosujLiczbe(0, IloscZawodnikow - 1);
    zawodnicy[losIndex]->Wyswietl();
    zawodnicy[losIndex]->WyswietlIds();
}