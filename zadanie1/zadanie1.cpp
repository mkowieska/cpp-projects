#include <string>
#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <random>
#include "Naglowek.h"

//Damska Grupa Siatkarska Akademii "Arcos"

int main() {
    bool displayMenu = true;
    srand(time(nullptr));
    Akademia Arcos;
    int opcja = 0;
    do {
        std::cout << "Co chcesz zrobic?" << std::endl;
        std::cout << "1. Dodac zawodnika" << std::endl;
        std::cout << "2. Stworz tablice zawodnika" << std::endl;
        std::cout << "3. Usunac zawodnika" << std::endl;
        std::cout << "4. Wyswietlic zawodnika" << std::endl;
        std::cout << "5. Wyczyscic pamiec" << std::endl;
        std::cout << "6. Zakonczyc program" << std::endl;
        std::cout << "7. Stworz akademie" << std::endl;
        std::cout << "Wybierasz: ";

        std::cin >> opcja;
        std::cin.ignore();
        switch (opcja) {
        case 1: {
            if (Arcos.iloscZawodnikow < Arcos.maxIloscZawodnikow) {
                if (nullptr == Arcos.zawodnicy) {
                    Stworz(Arcos.zawodnicy, Arcos.maxIloscZawodnikow);
                }
                Inicjalizuj(&(Arcos.zawodnicy[Arcos.iloscZawodnikow]), 1);
                Arcos.iloscZawodnikow++;
                std::cout << "Zawodnik dodany." << std::endl;
            }
            else {
                std::cout << "Nie mozna dodac wiecej zawodnikow." << std::endl;
            }
            std::cout << " " << std::endl;
            break;
        }
        case 2: {
            if (nullptr == Arcos.zawodnicy) {
                int iloscZawodnikow = (rand() % Arcos.maxIloscZawodnikow) + 1;
                Stworz(Arcos.zawodnicy, Arcos.iloscZawodnikow);
            }
            std::cout << "Poprawnie wykonana operacja." << std::endl;
            std::cout << " " << std::endl;
            break;
        }
        case 3: {
            Usun(Arcos.zawodnicy, Arcos.iloscZawodnikow);
            Arcos.iloscZawodnikow = 0;
            std::cout << "Zawodnik usuniety." << std::endl;
            std::cout << " " << std::endl;
            break;
        }
        case 4: {
            std::cout << "Lista zawodnikow:" << std::endl;
            Wyswietl(Arcos.zawodnicy, Arcos.iloscZawodnikow);
            std::cout << " " << std::endl;
            break;
        }
        case 5: {
            Wyczysc(Arcos);
            displayMenu = false;
            std::cout << "Wyczyszczone." << std::endl;
            std::cout << " " << std::endl;
            break;
        }
        case 6: {
            return 0;
            break;
        }
        case 7: {
            Akademia* Arcos = nullptr;
            Stworz(Arcos);
            break;
        }
        default:
            std::cout << "Blad, nie ma takiej opcji." << std::endl;
            break;
        }
    } while (opcja != 9);
    return 0;
}