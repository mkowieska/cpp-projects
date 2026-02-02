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
import <sstream>;

#include "Naglowek-trzecie.h"

using namespace std;

string imiona[] = {
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
string nazwiska[] = {
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

int WylosujLiczbe(int from, int to) { 
    random_device random; //generuje losowe liczby
    default_random_engine engine{ random() }; // sluzy do generowania sekwencji liczb pseudolosowych
    uniform_int_distribution <unsigned> zawodnik(from, to); //sluzy do generowania liczb z równomiernym rozk³adem prawdopodobieñstwa z zakresu od "from" do "to"
    return zawodnik(engine);
}
void gen_data(size_t& ilosc) {
    static random_device rd;
    static default_random_engine dfe(rd());
    static uniform_int_distribution<int> rozmiar(10, 50);
    ilosc = rozmiar(dfe);
}

size_t generujLiczbeLosowa(size_t begin, size_t end) {
    static random_device seed;     // ziarno poczatkowe
    static mt19937 engine(seed()); // generator
    static uniform_int_distribution<size_t> uniformDist(begin, end);
    return uniformDist(engine);
}

Zawodnik::Zawodnik(const string& Imie, const string& Nazwisko) :imie(Imie), nazwisko(Nazwisko){}//konstruktor

Grupa::Grupa(int IloscZawodnikow){ //tablica wskaźników do obiektów klasy 
    iloscZawodnikow = IloscZawodnikow;
    zawodnicy = new Zawodnik * [IloscZawodnikow];

    for (size_t i = 0; i < IloscZawodnikow; i++){
        zawodnicy[i] = InicjalizujZawodnika();
    }
}

Grupa::~Grupa() { //Destruktor, jest on wywoływany automatycznie, gdy obiekt tej klasy przestaje istnieć, nastepuje dealokowanie pamieci
    for (size_t i = 0; i < iloscZawodnikow; i++) {
        delete zawodnicy[i];
    }
    delete[] zawodnicy;
    cout << "Destruktor wywolany." << endl;
}

Zawodnik* Grupa::InicjalizujZawodnika() {
    int iloscImion = sizeof(imiona) / sizeof(imiona[0]);
    int iloscNazwisk = sizeof(nazwiska) / sizeof(nazwiska[0]);

    int ImieIndex = WylosujLiczbe(0, iloscImion - 1);
    int NazwiskoIndex = WylosujLiczbe(0, iloscNazwisk - 1);

    Zawodnik* newZawodnik = new Zawodnik(imiona[ImieIndex], nazwiska[NazwiskoIndex]);
    return newZawodnik;
}

void Zawodnik::Wyswietl() {
    cout << " " << endl;
    cout << "Imie: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
}

void Grupa::DodajZawodnika() {
    if (iloscZawodnikow < maxIloscZawodnikow) {
        Zawodnik** temp = new Zawodnik * [iloscZawodnikow + 1];

        for (size_t i = 0; i < iloscZawodnikow; i++) {
            temp[i] = zawodnicy[i];
        }
        delete[] zawodnicy;
        zawodnicy = temp;

        zawodnicy[iloscZawodnikow] = InicjalizujZawodnika();

        ++iloscZawodnikow;
        cout << "Zawodnik dodany." << endl;

    }
    else {
        cout << "Blad." << endl;
    }
}

void Grupa::EdytujZawodnika(const Zawodnik& nowyZawodnik) {
    int losowyIndex = WylosujLiczbe(0, iloscZawodnikow - 1);

    if (nullptr != zawodnicy[losowyIndex]) {
        delete zawodnicy[losowyIndex];
        zawodnicy[losowyIndex] = new Zawodnik(nowyZawodnik);
    }
    else {
        cout << "Blad." << endl;
    }
}
void Grupa::WyswietlWszystkichZawodnikow(){
    for (size_t i = 0; i < iloscZawodnikow; i++){
        if (nullptr != zawodnicy[i]){
            zawodnicy[i]->Wyswietl();
        }
        else{
            cout << "Brak zawodnikow." << endl;
            break;
        }
    }
}

void Grupa::UsunLosowoZawodnika(){
    int losowyIndex = WylosujLiczbe(0, iloscZawodnikow - 1);

    if (nullptr != zawodnicy[losowyIndex]){
        delete zawodnicy[losowyIndex];
        zawodnicy[losowyIndex] = nullptr;
        --iloscZawodnikow;
        cout << "Zawodnik usuniety." << endl;
        cout << iloscZawodnikow << endl;
    }
    else{
        cout << "Blad." << endl;
    }
}

void Grupa::Wyczysc() {
    if (zawodnicy != nullptr) {
        for (int i = 0; i < iloscZawodnikow; i++) {
            delete zawodnicy[i];
        }
        delete[] zawodnicy;
        zawodnicy = nullptr;
        iloscZawodnikow = 0;
    }
}

int Grupa::PobierzLiczbeZawodnikow() {
    return iloscZawodnikow;
}

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