#include "wyslac-Naglowek5.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <random>
using namespace std;

Zawodnik::Zawodnik() {}
Zawodnik::Zawodnik(const string& _imie, const string& _nazwisko, const string& _druzyna, int _dzien, int _miesiac, int _rok)
    : imie(_imie), nazwisko(_nazwisko), druzyna(_druzyna), dzien(_dzien), miesiac(_miesiac), rok(_rok) {}
Zawodnik::Zawodnik(size_t& _iloscId, Id**& _id_s, const string& _imie, const string& _nazwisko, const string& _druzyna, int _dzien, int _miesiac, int _rok)
    : iloscId(_iloscId), ids(_id_s), imie(_imie), nazwisko(_nazwisko), druzyna(_druzyna), dzien(_dzien), miesiac(_miesiac), rok(_rok) {}


Zawodnik::Zawodnik(const Zawodnik& zaw) {
    imie = zaw.imie;
    nazwisko = zaw.nazwisko;
    druzyna = zaw.druzyna;
    dzien = zaw.dzien;
    miesiac = zaw.miesiac;
    rok = zaw.rok;
}


Zawodnik::~Zawodnik() {
    for (size_t i = 0; i < iloscId; i++)
    {
        delete ids[i];
    }
    delete[] ids;
    ids = nullptr;
    iloscId = 0;

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
    string personalia = imie + nazwisko;
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

//ZADEKLAROWANE W GRUPIE

int Grupa::getLiczbeZawodnikow() {
    return IloscZawodnikow;
}

void Grupa::DodajZawodnika() {
    if (IloscZawodnikow < maxIloscZawodnikow) {
        Zawodnik** temp = new Zawodnik * [IloscZawodnikow + 1];

        for (size_t i = 0; i < IloscZawodnikow; i++) {
            temp[i] = zawodnicy[i];
        }
        delete[] zawodnicy;
        zawodnicy = temp;

        zawodnicy[IloscZawodnikow] = InicjalizujZawodnika();

        ++IloscZawodnikow;
        cout << "Zawodnik dodany." << endl;

    }
    else {
        cout << "Blad." << endl;
    }
}

void Grupa::WyswietlWszystkichZawodnikow() {
    if (IloscZawodnikow < 1) {
        cout << "Brak zawodnikow." << endl;
        return;
    }
    for (size_t i = 0; i < IloscZawodnikow; i++) {
        if (nullptr != zawodnicy[i]) {
            zawodnicy[i]->Wyswietl();
        }
        else {
            break;
        }
    }
}

void Grupa::Lista(const string& druzyna) {
    for (size_t i = 0; i < IloscZawodnikow; i++) {
        if (nullptr != zawodnicy[i] && zawodnicy[i]->getDruzyne() == druzyna) {
            zawodnicy[i]->Wyswietl();
        }
    }
}

void Grupa::Edytuj(const Zawodnik& nowyZawodnik) {
    int losowyIndex = WylosujLiczbe(0, IloscZawodnikow - 1);

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
        zawodnicy[losowyIndex] = nullptr;
        --IloscZawodnikow;
        cout << "Zawodnik usuniety." << endl;
        cout << "Aktualna ilosc zawodnikow: " << IloscZawodnikow << endl;
    }
    else {
        cout << "Blad." << endl;
    }
}