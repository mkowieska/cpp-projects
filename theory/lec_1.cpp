#include <iostream>
using namespace std;
//#include "Nagłówek.h"

//Definicja typu wlasnego
struct Osoba { //deklaracja typu
    // poczatek de nicji typu
    string imie; // atrybut (zmienna skladowa struktury)
    string nazwisko;
    int wiek;
    char plec;
    int pesel;
};

void print(const Osoba&); // prototypy funkcji globalnych
void print(const Osoba*);

// Definicje funkcji
// Funkcje przeladowane sa to funkcje, ktore maja taka sama nazwe lecz roznia sie sygnaturami.
struct Osoba;
void przeladowana(int i);
void przeladowana(int i, float j) {}
void przeladowana(int i, float j[]) {}
void przeladowana(int i, int j) {}
void przeladowana(int i, Osoba* Osoba) {}
void przeladowana(Osoba* Osoba, int i) {}
void przeladowana(Osoba*& Osoba, int i = 0) {} //Funkcje nie moga sie roznic tylko domyslnym argumentem

int potega2(int x) {
    cout << "x do drugiej liczby " << x << "typu integer jest ";
    return x * x;
}
double potega2(double y) {
    cout << "y do drugiej liczby " << y << "typu double jest ";
    return y * y;
}

void print(const Osoba& t) { // nie mozna zmienic wartosc obiektu t typu Osoba
    cout <<
        "imie : " << t.imie << "\t" <<
        "nazwisko : " << t.nazwisko << "\t" <<
        "wiek : " << t.wiek << "\t" <<
        "plec: " << t.plec << "\t" << endl;
}
void print(const Osoba* t) { // nie mozna zmienic przez wskaznik t obiekt typu Osoba
    cout <<
        "imie : " << t->imie << "\t" <<
        "nazwisko : " << t->nazwisko << "\t" <<
        "wiek : " << t->wiek << "\t" <<
        "plec: " << t->plec << "\t" << endl;
}

void dodaj(Osoba*& a, int& size) {
    Osoba* temp = new Osoba[size + 1]; // 1. Stworz nowatabele
    for (int i = 0;i < size; i++) temp[i] = a[i]; //2. Skopiujdane
    delete[] a; // 3. Usun stara tabele
    a = temp; // 4. Teraz mamy nowy adres
    ++size; // 5. oraz nowy rozmiar tablicy
}
//void foo() {
//    Osoba* a; int size{ 10 };
//        . . .
//        . . .
//        . . .
//        dodaj(a, size);
//}

//Macierz obiektow
void stworz(Osoba**& osoby, int size) {
    osoby = new Osoba * [size]; //1. stworz tablice wskaznikow
    // 2. Stworz kolumny macierzy obiektow
    for (int i = 0;i < size; i++)
        osoby[i] = new Osoba[size];//Po new uzyte samo Osoba bez gwiazdki, wiec nie jest wskaznikiem, lecz wartoscia
}
void usun(Osoba**& osoby, int& size) {
    for (int i = 0; i < size; i++) delete[] osoby[i];
    delete[] osoby;
    osoby = nullptr;
    size = 0;
}
void zainicjuj(Osoba**& osoby, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0;j < size; j++) osoby[i][j].wiek = i + j;
}
//Zeruj wskaznikow gdy jest to tylko mozliwe
void pokaz(Osoba** osoby, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            print(osoby[i][j]);
        }
        cout << endl;
    }
}

//Macierz wskaznikow na obiekty
void stworz(Osoba***& osoby, int size) {
    osoby = new Osoba * *[size];
    for (int i = 0;i < size; i++)
        osoby[i] = new Osoba * [size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            osoby[i][j] = new Osoba;
    }
}
void zainicjuj(Osoba*** osoby, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            osoby[i][j]->wiek = i + j;
        }
}

//Macierz wskaznikow
void pokaz(Osoba*** osoby, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            print(osoby[i][j]);
        }
        cout << endl;
    }
}

int main() {
    cout << "Hello, Programowanie 2!" << endl;
    cout << potega2(3) << endl;
    cout << potega2(3.14) << endl;

    //Definicja funkcji globalnych
    Osoba osoba1, osoba2;
    osoba1.imie = "Jan";
    osoba1.nazwisko = "Kowalski";
    osoba1.wiek = 19;
    osoba1.plec = 'K';
    osoba1.pesel = 12345678900;
    cout << "Wyswielanie przy uzyciu referencji" << endl;
    print(osoba1);
    cout << "Wyswielanie przy uzyciu wskaznika" << endl;
    print(&osoba1);

    // Sterta(ang. heap) jest rodzaj pamieci dostepnej dla programu i mogaca byc mu przydzielona do wykorzystania podczas wykonania. Ten rodzaj pamieci moze reprezentowac tylko zmienna typu wskaznikowego
    Osoba* o1;o1 = new Osoba; o1->wiek = 18;
    delete o1; //operator zwalniania pamieci

    //Tablica obiektow na stercie
    Osoba* o2{ nullptr };
    o2 = new Osoba[10];// tablica lub pojemnik obiektow na sterci
    for (int i = 0; i < 10; i++) {
        o2[i].wiek = 18 + 2 * i;
    }
    for (int i = 0; i < 10; i++) print(o2[i]);
    delete[] o2; // zwalnianie pamieci pod tablice
    o2 = nullptr;

    //Tablica wskaznikow na stercie
    cout << "Tablica dynamiczna wskaznikow na obiekty" << endl;
    Osoba** o3 = new Osoba * [10]; // Etap 1. Przydziel pamiec pod caly pojemnik
    for (int i = 0; i < 10; i++) o3[i] = new Osoba; // Etap2. Przydziel pamiec dla kazdego obiektu
    for (int i = 0; i < 10; i++) o3[i]->wiek = 18 + 2 * i;
    for (int i = 0; i < 10; i++) print(o3[i]);
    for (int i = 0; i < 10; i++) delete o3[i]; // Usun kazdy obiekt
    delete[] o3; // Usun caly pojemni

    //Macierz obiektow
    Osoba** osoby; int size{ 10 };
    stworz(osoby, size);
    zainicjuj(osoby, size);
    pokaz(osoby, size);
    usun(osoby, size);
    if (osoby == nullptr)
        cout << "Nie mam nic" << endl;

    //Macierz wskaźników
    Osoba*** osoby; int size{ 10 };
    stworz(osoby, size);
    zainicjuj(osoby, size);
    pokaz(osoby, size);

    return 0;
}

