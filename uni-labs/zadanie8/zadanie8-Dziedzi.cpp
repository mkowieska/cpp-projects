#include "Naglowek8.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-------------------------------------------------------------------------------------------------------------------
//SALA GIMNASTYCZNA

void SalaGimnastyczna::ZaplanujTrening() {
	cout << "Podaj numer grupy: ";
	int numer_grupy;
	cin >> numer_grupy;
	cin.ignore();

	cout << "Ile chcesz wpisac cwiczen? " << endl;
	string liczbacwiczen;
	getline(cin, liczbacwiczen);

	int liczba_cwiczen = stoi(liczbacwiczen);
	cout << "Podaj cwiczenia oddzielone przecinkami: " << endl;
	string lista_cwiczen;
	getline(cin, lista_cwiczen);

	trening.resize(liczba_cwiczen);

	string tymczasowy;
	size_t pozycja = 0;
	int index = 0;

	while ((pozycja = lista_cwiczen.find(',')) != string::npos && index < liczba_cwiczen) {
		tymczasowy = lista_cwiczen.substr(0, pozycja);
		trening[index++] = tymczasowy;
		lista_cwiczen.erase(0, pozycja + 1);
	}

	if (!lista_cwiczen.empty() && index < liczba_cwiczen) {
		trening[index++] = lista_cwiczen;
	}

	if (index == liczba_cwiczen) {
		cout << "Cwiczenia na dzisiejszy trening grupy " << get_numer_grupy() << ":" << endl;
		for (int i = 0; i < liczba_cwiczen; i++) {
			cout << trening[i] << endl;
		}
	}
	else {
		cout << "Blad." << endl;
	}
}

void SalaGimnastyczna::WyswietlTrening() {
	cout << "Cwiczenia w czasie dzisiejszego treningu w sali gimnastycznej: ";
	bool first = true;
	for (const string& cwiczenie : trening) {
		if (!cwiczenie.empty()) {
			if (!first) {
				cout << ", ";
			}
			cout << cwiczenie;
			first = false;
		}
	}
	cout << endl;
	cout << "Numer grupy: " << get_numer_grupy() << endl;
	cout << endl;
}

//-------------------------------------------------------------------------------------------------------------------
//KANTOREK
/*
Kantorek::Kantorek(const Kantorek& kan) {
	nazwa = kan.nazwa;
	ilosc_pilek = kan.ilosc_pilek;
	ilosc_siatek = kan.ilosc_siatek;

	pilki = new string[ilosc_pilek];
	siatki = new string[ilosc_siatek];

	for (int i = 0; i < ilosc_pilek; i++) {
		pilki[i] = kan.pilki[i];
	}
	for (int i = 0; i < ilosc_siatek; i++) {
		siatki[i] = kan.siatki[i];
	}
}*/
void Kantorek::DodajPilke(const string& pilka) {
	pilki.push_back(pilka);
	ilosc_pilek++;
}

void Kantorek::DodajSiatke(const string& siatka) {
	siatki.push_back(siatka);
	ilosc_siatek++;
}

void Kantorek::Wyswietl() {
	cout << "Wszystkie rodzaje pilek: " << endl;
	for (int i = 0; i < ilosc_pilek; i++) {
		cout << pilki[i];
		if (i != ilosc_pilek - 1) {
			cout << ", ";
		}
	}
	cout << endl << endl;
	cout << "Wszystkie rodzaje siatki: " << endl;
	for (int i = 0; i < ilosc_siatek; i++) {
		cout << siatki[i];
		if (i != ilosc_siatek - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}

//-------------------------------------------------------------------------------------------------------------------
//SKLEP

void Sklep::DodajKoszulke() {
	string wpisany_nazw_w_druzynie;
	string wpisane_pseudo_zawodnika;
	bool aktualny_stan_zamowienia = true;

	cout << "Wpisz pseudonim zawodnika: ";
	cin >> wpisane_pseudo_zawodnika;
	if (WalidacjaSlowa(wpisane_pseudo_zawodnika) == false) {
		cout << "Blad. Nazwisko." << endl;
		return;
	}
	cout << "Wpisz nazwisko w druzynie: ";
	cin >> wpisany_nazw_w_druzynie;
	if (WalidacjaSlowa(wpisany_nazw_w_druzynie) == false) {
		cout << "Blad. Druzyna." << endl;
		return;
	}

	koszulki.push_back(new Koszulka(wpisany_nazw_w_druzynie, wpisane_pseudo_zawodnika, aktualny_stan_zamowienia)); //dodawanie do kontenera
	iloscKoszulek++;
}

void Sklep::WyswietlZamowioneKoszulki() {
	int counter = 0;
	for (int i = 0; i < iloscKoszulek; i++) {
		if (koszulki[i]->stan_zamowienia == true) {
			cout << "Pseudonim w druzynie: " << koszulki[i]->pseudonim_w_druzynie << endl;
			cout << "Nazwisko zawodnika: " << koszulki[i]->nazwisko_zawodnika << endl;
			counter++;
		}
	}
}

void Sklep::UsunKoszulke() {
	if (iloscKoszulek < 1) {
		cout << "Blad. Pusto." << endl;
		return;
	}
	string wpisany_pseudonim_w_druzynie_do_usuniecia;
	string wpisane_nazwisko_zawodnika_do_usuniecia;

	cout << "Wpisz psuednim w druzynie: ";
	cin >> wpisany_pseudonim_w_druzynie_do_usuniecia;
	cout << "Wpisz nazwisko zawodnika: ";
	cin >> wpisane_nazwisko_zawodnika_do_usuniecia;

	for (int i = 0; i < iloscKoszulek; i++) {
		if (koszulki[i]->pseudonim_w_druzynie == wpisany_pseudonim_w_druzynie_do_usuniecia) {
			if (koszulki[i]->nazwisko_zawodnika == wpisane_nazwisko_zawodnika_do_usuniecia) {
				delete koszulki[i];
				koszulki[i] = nullptr;
				koszulki[i] = koszulki[iloscKoszulek - 1];
				koszulki[iloscKoszulek - 1] = nullptr;
				--iloscKoszulek;
				cout << "Usunieto koszulke." << endl;
				cout << "Aktualna ilosc koszulek: " << iloscKoszulek << endl;
			}
			else {
				cout << "Blad. Nie ma takiego nazwiska." << endl << endl;
				return;
			}
		}
		else {
			cout << "Blad. Nie ma takiej druzyny. " << endl;
			return;
		}
	}
}