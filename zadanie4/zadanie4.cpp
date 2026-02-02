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

//Damska Grupa Siatkarska "Volley"

int main() {
    bool displayMenu = true;
    const int maxIloscZawodnikow = 10;
    int iloscZawodnikow = WylosujLiczbe(1, maxIloscZawodnikow);
    Grupa Volley(iloscZawodnikow);
    int opcja = 0;
    do {
        system("cls");
        cout << "Co chcesz zrobic?" << endl;
        cout << "1. Dodac losowo zawodnika." << endl;
        cout << "2. Dodac numer id losowemu zawodnikowi." << endl;
        cout << "3. Wyswietlic zawodnikow." << endl;
        cout << "4. Wyswietlic losowego zawodnika." << endl;
        cout << "5. Wyswietlic zawodnikow z wybranej klasy." << endl;
        cout << "6. Edytuj losowego zawodnika." << endl;
        cout << "7. Usunac losowo zawodnika." << endl;
        cout << "8. Wyczyscic pamiec." << endl;
        cout << "9. Zakonczyc program." << endl;
        cout << "Wybierasz: ";
        cin >> opcja;
        cin.ignore();
        system("cls");
        switch (opcja) {
        case 1: {
            system("cls");
            Volley.DodajZawodnika();
            cout << " " << endl;
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            if (Volley.GetLiczbeZawodnikow() > 0) {
                Volley.WyswietlLosowegoZawodnika();
            }
            else {
                cout << "Blad. " << endl;
            }
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            cout << "Lista zawodnikow:" << endl;
            Volley.WyswietlWszystkichZawodnikow();
            cout << " " << endl;
            system("pause");
            break;
        }
        case 4: {
            system("cls");
            if (Volley.GetLiczbeZawodnikow() > 0) {
                Volley.WyswietlIdLosowegoZawodnika();
            }
            else {
                cout << "Blad. " << endl;
            }
            system("pause");
            break;
        }
        case 5: {
            system("cls");
            cout << "Mozliwosci: < 9, 9-10, 11-12, 13-14, 15-16, 17-18, 19-20, 20+, Pary, Rodziny, Studenci, Seniorzy. " << endl;
            cout << "Podaj nazwę klasy: ";
            string input;
            cin >> input;
            system("pause");
            break;
        }
        case 6: {
            system("cls");
            if (Volley.GetLiczbeZawodnikow() > 0)
            {
                string input;
                string przerwa = " ";
                cout << "Wpisz nowe: imie nazwisko druzyne: ";
                cin.get();
                getline(cin, input);

                string delimiter = " ";
                size_t pos = 0;
                string imie, nazwisko, druzyna;

                pos = input.find(delimiter);
                imie = input.substr(0, pos);
                input.erase(0, pos + delimiter.length());

                pos = input.find(delimiter);
                nazwisko = input.substr(0, pos);
                input.erase(0, pos + delimiter.length());

                druzyna = input;

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

                Zawodnik noweDaneZawodnika(imie, nazwisko, druzyna);
                Volley.Edytuj(noweDaneZawodnika);
                cout << "Zaktualizowano dane." << endl;
                cout << " " << endl;
                system("pause");
                break;
            }
            else {
                cout << "Nie ma dodanych zawodnikow." << endl;
                cout << " " << endl;
                system("pause");
            }
            break;
        }
        case 7: {
            system("cls");
            Volley.UsunLosowoZawodnika();
            cout << " " << endl;
            system("pause");
            break;
        }
        case 8: {
            system("cls");
            Volley.Wyczysc();
            displayMenu = false;
            cout << "Wyczyszczone." << endl;
            cout << " " << endl;
            system("pause");
            break;
        }
        case 9: {
            exit(0);
            break;
        }
        default:
            cout << "Blad." << endl;
            cout << " " << endl;
            break;
        }
    } while (true);
}