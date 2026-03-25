#include "Naglowek8.h"
#include <iostream>;
#include <iomanip>;
#include <string>;
#include <sstream>;
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//Damska Grupa Siatkarska "Volley"

int main() {
    string NazwaPliku = "Baza.txt";
    const int maxIloscZawodnikow = 10;
    int iloscZawodnikow = WylosujLiczbe(1, maxIloscZawodnikow);
    Miejsce* miejsce;
    SprzetSportowy* sprzet = new Kantorek(); //wskaznik na obiekt klasy pochodnej
    Grupa Volley(iloscZawodnikow);
    LosoweId listanr;
    size_t opcja{};
    do {
        system("cls");
        cout << setfill('=') << setw(50) << "==" << endl;
        cout << setfill(' ') << setw((50 - 17) / 2) << "" << "Co chcesz zrobic?" << setw((50 - 17) / 2) << "" << endl;
        cout << setfill('=') << setw(50) << "==" << endl;
        cout << setfill('-') << setw(50) << "--" << endl;
        cout << setfill(' ') << setw((50 - 9) / 2) << "" << "ZAWODNICY" << setw((50 - 9) / 2) << "" << endl;
        cout << setfill('-') << setw(50) << "--" << endl;
        cout << "1. Dodac losowo zawodnika." << endl;
        cout << "2. Wyswietlic zawodnikow." << endl;
        cout << "3. Wyswietl przykladowe numery zawodnikow." << endl;
        cout << "4. Wyswietlic zawodnikow z wybranej druzyny." << endl;
        cout << "5. Edytowac losowego zawodnika." << endl;
        cout << "6. Usunac losowo zawodnika." << endl;
        cout << setfill('-') << setw(50) << "--" << endl;
        cout << setfill(' ') << setw((50 - 15) / 2) << "" << "DZIALANIA NA ID" << setw((50 - 15) / 2) << "" << endl;
        cout << setfill('-') << setw(50) << "--" << endl;
        cout << "7. Dodac numer id losowemu zawodnikowi." << endl;
        cout << "8. Wyswietlic id wybranego zawodnika." << endl;
        cout << setfill('-') << setw(50) << "--" << endl;
        cout << setfill(' ') << setw((50 - 4) / 2) << "" << "PLIK" << setw((50 - 4) / 2) << "" << endl;
        cout << setfill('-') << setw(50) << "--" << endl;
        cout << "9. Zapisac do pliku." << endl;
        cout << "10. Odczytac z pliku." << endl;
        cout << setfill('-') << setw(50) << "--" << endl;
        cout << setfill(' ') << setw((50 - 14) / 2) << "" << "DZIEDZICZENIE" << setw((50 - 14) / 2) << "" << endl;
        cout << setfill('-') << setw(50) << "--" << endl;
        cout << "11. Zamowienia w sklepie." << endl;
        cout << "12. Trening na sali gimnastycznej." << endl;
        cout << "13. Sklad kantorka." << endl;
        cout << setfill('-') << setw(50) << "--" << endl;
        cout << setfill('=') << setw(50) << "==" << endl;
        cout << "0. Zakonczyc program." << endl;
        cout << setfill('=') << setw(50) << "==" << endl;
        cout << setfill('=') << setw(50) << "==" << endl;
        cout << setfill(' ') << setw((50 - 11) / 2) << "" << "Wybierasz: ";

        cin >> opcja;
        cin.ignore();
        system("cls");
        switch (opcja) {
            //ZAWODNICY
        case 1: {
            system("cls");
            Volley.DodajZawodnika();
            cout << " " << endl;
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            cout << setfill('=') << setw(50) << "==" << endl;
            cout << "Lista zawodnikow:" << endl;
            cout << setfill('=') << setw(50) << "==" << endl;
            Volley.WyswietlWszystkichZawodnikow();
            cout << setfill('=') << setw(50) << "==" << endl;
            cout << " " << endl;
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            int i;
            cout << "Podaj liczbe zawodnikow: ";
            cin >> i;
            cout << "Przykladowe numery zawodnikow: ";
            for (int j = 0; j < i; j++) {
                cout << listanr[j] << " ";
            }
            cout << endl;
            system("pause");
            break;
        }
        case 4: {
            system("cls");
            cout << setfill('-') << setw(50) << "--" << endl;
            cout << "Opcje: " << endl;
            cout << " <9, 9-10 , 11-12 , 13-14 , 15-16 , 17-18 ," << endl;
            cout << " 19-20 , 20+, 20, Pary, Studenci(20-24) ." << endl;
            cout << setfill('-') << setw(50) << "--" << endl;
            cout << "Podaj nazwe druzyny: ";
            string input;
            cin >> input;
            Volley.Lista(input);
            system("pause");
            break;
        }
        case 5: {
            system("cls");
            Volley.EdytujDaneZawodnika(Volley);
            break;
        }
        case 6: {
            system("cls");
            Volley.UsunLosowoZawodnika();
            cout << " " << endl;
            system("pause");
            break;
        }
              //ID
        case 7: {
            system("cls");
            if (Volley.getLiczbeZawodnikow() > 0) {
                Volley.DodajIdLosowemuZawodnikowi(Volley);
            }
            else {
                cout << "Blad. " << endl;
            }
            system("pause");
            break;
        }
        case 8: {
            system("cls");
            Volley.WyswietlIdLosowegoZawodnika();
            cout << " " << endl;
            system("pause");
            break;
        }
              //PLIK
        case 9: {
            system("cls");
            Volley.ZapisDanychDoPliku(Volley);
            cout << " " << endl;
            system("pause");
            break;
        }
        case 10: {
            system("cls");
            string content = Volley.OdczytDanychZPliku("Baza.txt");
            cout << content;
            cout << " " << endl;
            system("pause");
            break;
        }
        case 11: {
            system("cls");
            miejsce = new Sklep();
            miejsce->Akcja();
            delete miejsce;
            cout << " " << endl;
            system("pause");
            break;
        }
        case 12: {
            system("cls");
            miejsce = new SalaGimnastyczna();
            miejsce->Akcja();
            cout << " " << endl;
            system("pause");
            delete miejsce;
            break;
        }
        case 13: {
            system("cls");
            sprzet->WiecejInformacji();
            delete sprzet;
            cout << " " << endl;
            system("pause");
            break;
        }
        case 0: {
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