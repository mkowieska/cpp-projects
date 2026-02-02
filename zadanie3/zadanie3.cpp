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

//Damska Grupa Siatkarska "Volley"

int main() {
    bool displayMenu = true;
    const size_t ilosc = 11;
    const int maxIloscZawodnikow = 10;
    int iloscZawodnikow = WylosujLiczbe(1, maxIloscZawodnikow);
    Zawodnik** zawodnicy = new Zawodnik * [ilosc];
    Grupa Volley(iloscZawodnikow);
    int opcja = 0;
    do {
        cout << "Co chcesz zrobic?" << endl;
        cout << "1. Dodac losowo zawodnika" << endl;
        cout << "2. Edytuj losowego zawodnika" << endl;
        cout << "3. Wyswietlic zawodnikow" << endl;
        cout << "4. Usunac losowo zawodnika" << endl;
        cout << "5. Wyczyscic pamiec" << endl;
        cout << "6. Zakonczyc program" << endl;
        cout << "Wybierasz: ";

        cin >> opcja;
        cin.ignore();
        switch (opcja) {
        case 1: {
            Volley.DodajZawodnika();
            cout << " " << endl;
            break;
        }
        case 2: {
            if (Volley.PobierzLiczbeZawodnikow() > 0)
            {
                string input;
                string przerwa = " ";
                cout << "Wpisz nowe imie i nazwisko: ";
                cin.get();
                getline(cin, input);

                string delimiter = " ";

                size_t pos = 0;
                string imie, nazwisko;

                //1
                pos = input.find(delimiter);
                imie = input.substr(0, pos);
                input.erase(0, pos + delimiter.length());

                //2
                pos = input.find(delimiter);
                nazwisko = input.substr(0, pos);
                input.erase(0, pos + delimiter.length());

                if (WalidacjaImieniaLubNazwiska(imie) == false)
                {
                    cout << "Imie nieprawidlowe." << endl;
                    cout << " " << endl;
                    break;
                }

                if (WalidacjaImieniaLubNazwiska(nazwisko) == false)
                {
                    cout << "Nazwisko nieprawidlowe." << endl;
                    cout << " " << endl;
                    break;
                }

                Zawodnik noweDaneZawodnika(imie, nazwisko);
                Volley.EdytujZawodnika(noweDaneZawodnika);
                cout << "Zaktualizowano dane." << endl;
                cout << " " << endl;
                break;
            }
            else {
                cout << "Nie ma dodanych zawodnikow." << endl;
                cout << " " << endl;
            }
            break;
        }
        case 3: {
             cout << "Lista zawodnikow:" << endl;
            Volley.WyswietlWszystkichZawodnikow();
            cout << " " << endl;
            break;
        }
        case 4:{
            Volley.UsunLosowoZawodnika();
            cout << " " << endl;
            break;
        }
        case 5: {
            Volley.Wyczysc();
            displayMenu = false;
            cout << "Wyczyszczone." << endl;
            cout << " " << endl;
            break;
        }
        case 6: {
            return 0;
            break;
        }
        default:
            cout << "Blad." << endl;
            cout << " " << endl;
            break;
        }
    } while (opcja != 7);
    return 0;
}