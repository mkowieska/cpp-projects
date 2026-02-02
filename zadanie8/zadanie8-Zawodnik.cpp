#include "Naglowek8.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <vector>

using namespace std;


Zawodnik::Zawodnik(const Zawodnik& zaw) {
    imie = zaw.imie;
    nazwisko = zaw.nazwisko;
    druzyna = zaw.druzyna;
    dzien = zaw.dzien;
    miesiac = zaw.miesiac;
    rok = zaw.rok;
}


istream& operator>>(istream& input, Zawodnik& z) {
    input >> z.imie >> z.nazwisko >> z.druzyna >> z.dzien >> z.miesiac >> z.rok >> z.iloscId;
    return input;
}

ostream& operator<<(ostream& output, const Zawodnik& z) {
    output << z.imie << " " << z.nazwisko << " " << z.druzyna << " " << z.dzien << "." << z.miesiac << "." << z.rok << "." << " " << z.iloscId;
    return output;
}

void Zawodnik::Wyswietl() {
    cout << endl;
    cout << setfill('-') << setw(50) << "--" << endl;
    cout << "Zawodnik" << endl;
    cout << setfill('-') << setw(50) << "--" << endl;
    cout << "Imie: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    cout << "Druzyna: " << druzyna << endl;
    cout << "Data urodzenia: " << dzien << "." << miesiac << "." << rok << endl;
    cout << setfill('-') << setw(50) << "--" << endl;
    /*
    if (iloscId > 0) {
        cout << "ID zawodnika: ";
        for (size_t i = 0; i < iloscId; i++) {
            cout << ids[i]->getNumer();
            if (i < iloscId - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << setfill('-') << setw(50) << "--" << endl;
    }
    */
}


string Zawodnik::getPersonalia() {
    string personalia = imie + " " + nazwisko;
    return personalia;
};

string Zawodnik::getDruzyne() {
    return druzyna;
}

int Zawodnik::getDzien() {
    return dzien;
}

int Zawodnik::getMiesiac() {
    return miesiac;
}

int Zawodnik::getRok() {
    return rok;
}

size_t Zawodnik::getIloscIds() {
    return iloscId;
}


//-------------------------------------------------------------------------------------------------------------------
//ZADEKLAROWANE W GRUPIE

int Grupa::getLiczbeZawodnikow() {
    return static_cast<int>(zawodnicy.size());
}

void Grupa::DodajZawodnika() {
    if (IloscZawodnikow < maxIloscZawodnikow) {
        zawodnicy.push_back(InicjalizujZawodnika());
        ++IloscZawodnikow;
        cout << "Zawodnik dodany." << endl;
    }
    else {
        cout << "Blad. Limit zawodnikow zostal osiagniety." << endl;
    }
}

void Grupa::WyswietlWszystkichZawodnikow() {
    if (zawodnicy.empty()) {
        cout << "Brak zawodnikow." << endl;
        return;
    }

    for (const auto& zawodnik : zawodnicy) {
        if (nullptr != zawodnik) {
            zawodnik->Wyswietl();
        }
        else {
            break;
        }
    }
}

void Grupa::Lista(const string& druzyna) {
    for (const auto& zawodnik : zawodnicy) {
        if (nullptr != zawodnik && zawodnik->getDruzyne() == druzyna) {
            zawodnik->Wyswietl();
        }
    }
}

void Grupa::Edytuj(const Zawodnik& nowyZawodnik) {
    if (zawodnicy.empty()) {
        cout << "Blad." << endl;
        return;
    }

    int losowyIndex = WylosujLiczbe(0, zawodnicy.size() - 1);
    if (nullptr != zawodnicy[losowyIndex]) {
        delete zawodnicy[losowyIndex];
        zawodnicy[losowyIndex] = new Zawodnik(nowyZawodnik);
    }
    else {
        cout << "Blad." << endl;
    }
}

void Grupa::EdytujDaneZawodnika(Grupa& Volley) {
    if (IloscZawodnikow > 0) {
        string input;
        string przerwa = " ";
        cout << "Wpisz nowe: imie nazwisko druzyne dzien miesiac rok: ";
        cin.get();
        getline(cin, input);

        string delimiter = " ";
        size_t pos = 0;
        string imie, nazwisko, druzyna, dzien_, miesiac_, rok_;

        pos = input.find(delimiter);
        imie = input.substr(0, pos);
        input.erase(0, pos + delimiter.length());

        pos = input.find(delimiter);
        nazwisko = input.substr(0, pos);
        input.erase(0, pos + delimiter.length());

        pos = input.find(delimiter);
        druzyna = input.substr(0, pos);
        input.erase(0, pos + delimiter.length());

        pos = input.find(delimiter);
        dzien_ = input.substr(0, pos);
        input.erase(0, pos + delimiter.length());

        pos = input.find(delimiter);
        miesiac_ = input.substr(0, pos);
        input.erase(0, pos + delimiter.length());

        rok_ = input;

        if (WalidacjaImieniaLubNazwiska(imie) == false) {
            cout << "Imie nieprawidlowe." << endl;
            cout << " " << endl;
            return;
        }

        if (WalidacjaImieniaLubNazwiska(nazwisko) == false) {
            cout << "Nazwisko nieprawidlowe." << endl;
            cout << " " << endl;
            return;
        }

        int dzien, miesiac, rok;
        try {
            dzien = stoi(dzien_);
            miesiac = stoi(miesiac_);
            rok = stoi(rok_);
        }
        catch (const exception& e) {
            cout << "Nieprawidlowy format daty." << endl;
            cout << " " << endl;
            return;
        }

        Zawodnik noweDaneZawodnika(imie, nazwisko, druzyna, dzien, miesiac, rok);
        Volley.Edytuj(noweDaneZawodnika);
    }
}

void Grupa::UsunLosowoZawodnika() {
    if (IloscZawodnikow < 1) {
        cout << "Nie ma osob." << endl;
        return;
    }

    int losowyIndex = WylosujLiczbe(0, IloscZawodnikow - 1);

    if (nullptr != zawodnicy[losowyIndex]) {
        delete zawodnicy[losowyIndex];
        zawodnicy.erase(zawodnicy.begin() + losowyIndex);
        --IloscZawodnikow;
        cout << "Zawodnik usuniety." << endl;
        cout << "Aktualna ilosc zawodnikow: " << IloscZawodnikow << endl;
    }
    else {
        cout << "Blad." << endl;
    }
}