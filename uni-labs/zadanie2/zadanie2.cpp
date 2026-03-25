#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <ctype.h>
#include <locale>
#include <stdexcept>
#include <random>
#include <random>

#include "Nagłówek3.h"
import <cstdlib>;
import <iostream>;
import <string>;
import <sstream>;
import <ctype.h>;
import <random>;
import <locale>;

//Damska Grupa Siatkarska "Volley"

using namespace std;

int main() {
    bool displayMenu = true;
    const size_t ilosc = 100;
    Zawodnik** zawodnicy = new Zawodnik * [ilosc];
    Grupa Volley;
    int liczbaZawodnikow = 0;

    int opcja = 0;
    do {
        cout << "Co chcesz zrobic?" << endl;
        cout << "1. Stworz strukture" << endl;
        cout << "2. Zainicjalizowac zawodnika" << endl;
        cout << "3. Dodac losowo zawodnika" << endl;
        cout << "4. Edytuj losowego zawodnika" << endl;
        cout << "5. Wyswietlic zawodnikow" << endl;
        cout << "6. Usunac losowo zawodnika" << endl;
        cout << "7. Wyczyscic pamiec" << endl;
        cout << "8. Zakonczyc program" << endl;
        cout << "9. Usunac strukture" << endl;
        cout << "Wybierasz: ";

        cin >> opcja;
        cin.ignore();
        switch (opcja) {
        case 1: {
            if (Volley.zawodnicy == nullptr) {
                Stworz(Volley.zawodnicy, Volley.iloscZawodnikow);
            }
            cout << "Zawodnik stworzony." << endl;
            cout << " " << endl;
            break;
        }
        case 2: {
            Inicjalizuj(Volley.zawodnicy, Volley.iloscZawodnikow);
            cout << " " << endl;
            break;
        }
        case 3: {
            Dodaj(Volley.zawodnicy, Volley.iloscZawodnikow);
            cout << "Zawodnik dodany." << endl;
            cout << " " << endl;
            break;
        }
        case 4:
        {
            if (Volley.iloscZawodnikow > 0)
            {
                int losowyIndex = WylosujLiczbe(0, Volley.iloscZawodnikow);
                Zawodnik* losowyZawodnik = Volley.zawodnicy[losowyIndex];

                if (nullptr == losowyZawodnik)
                {
                    cout << "Zawodnik usuniety." << endl;
                    cout << " " << endl;
                    break;
                }

                string inp;
                cout << "Wpisz nowe imie i nazwisko: ";
                cin.get();
                getline(cin, inp);

                stringstream input_stringstream(inp);
                string words[2]; 
                int i = 0;

                while ((i < 2) && (input_stringstream >> words[i]))
                {
                    i++;
                }

                if (i == 2)
                {
                    Zawodnik noweDaneZawodnika;
                    if (WalidacjaImieniaLubNazwiska(words[0]) == false)
                    {
                        cout << "Imie nieprawidlowe" << endl;
                        cout << " " << endl;
                        break;
                    }

                    noweDaneZawodnika.imie = words[0];

                    if (WalidacjaImieniaLubNazwiska(words[1]) == false)
                    {
                        cout << "Nazwisko nieprawidlowe." << endl;
                        cout << " " << endl;
                        break;
                    }

                    noweDaneZawodnika.nazwisko = words[1];

                    *losowyZawodnik = noweDaneZawodnika;
                    cout << "Zaktualizowano dane."<< endl;
                    cout << " " << endl;
                    break;
                }
                else
                {
                    cout << "Blad." << endl;
                    cout << " " << endl;
                }
            }
            else
            {
                cout << "Nie ma dodanych zawodnikow." << endl;
                cout << " " << endl;
            }
        }
        case 5: {
            cout << "Lista zawodnikow:" << endl;
            Wyswietl(Volley.zawodnicy, Volley.iloscZawodnikow);
            cout << " " << endl;
            break;
        }
        case 6: {
            int index = WylosujLiczbe(0, (Volley.iloscZawodnikow - 1));
            Usun(Volley.zawodnicy, Volley.iloscZawodnikow, index);
            cout << "Zawodnik usuniety." << endl;
            cout << " " << endl;
            break;
        }
        case 7: {
            Wyczysc(Volley);
            displayMenu = false;
            cout << "Wyczyszczone." << endl;
            cout << " " << endl;
            break;
        }
        case 8: {
            return 0;
            break;
        }
        case 9: {
            Usun(Volley.zawodnicy, Volley.iloscZawodnikow);
            break;
        }
        default:
            cout << "Blad, nie ma takiej opcji." << endl;
            break;
        }
    } while (opcja != 11);
    return 0;
}