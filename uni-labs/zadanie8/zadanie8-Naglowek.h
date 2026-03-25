#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <random>
#include <vector>
#include <map>
#include <set>

using namespace std;

int WylosujLiczbe(int from, int to);
bool WalidacjaImieniaLubNazwiska(const string& s);
bool WalidacjaSlowa(const string& s);


//----------------------------------------------------------------------------------------------------------------------------
class Miejsce { //klasa bazowa
private:
	int numer_grupy;
public:
	Miejsce() {}; //(bez {})  // Konstruktor domyœlny (bez argumentów), który inicjalizuje wszystkie atrybuty jako puste stringi.
	Miejsce(const int& _numer_grupy)
		: numer_grupy(_numer_grupy) {};
	~Miejsce() {};
	int get_numer_grupy() {
		return numer_grupy;
	};
	virtual void Akcja() = 0; //polimorfizm 
};

//---------------------------------------------------------

class SalaGimnastyczna : public Miejsce { //dziedziczenie
private:
	friend istream& operator>>(istream& input, SalaGimnastyczna& sg) {
		input >> sg.trener >> sg.ilosc_lawek;
		return input;
	}
	string trener;
	int ilosc_lawek;
	vector<string> trening;
public:
	SalaGimnastyczna() {
		trening.resize(5);
	}
	~SalaGimnastyczna() {}
	/*
	friend istream& operator>>(istream& input, SalaGimnastyczna& sg) {
		input >> sg.trener >> sg.ilosc_lawek;

		sg.trening.resize(sg.ilosc_lawek);

		for (int i = 0; i < sg.ilosc_lawek; i++) {
			sg.trening[i] = "";
			input >> sg.trening[i];
		}
		return input;
	}*/
	void ZaplanujTrening();
	void WyswietlTrening();
	void Akcja() override { //polimorfizm 
		bool showMenu = true;
		size_t opcjasala{};
		do {
			system("cls");
			cout << "SALA GIMNASTYCZNA" << endl;
			cout << "1. Zaplanuj cwiczenia na dzisiejszy trening." << endl;
			cout << "2. Wyswietl dzisiejszy trening." << endl;
			cout << "0. Cofnij sie do menu dziedziczenie" << endl;
			cout << "Wybierasz: ";
			cin >> opcjasala;
			cin.ignore();
			system("cls");
			switch (opcjasala) {
			case 1: {
				system("cls");
				cout << "LISTA CWICZEN DO WYBORU: " << endl;
				cout << "Przysiady, Pompki, Deski," << endl;
				cout << "Bieg, Marsz, Szybki marsz," << endl;
				cout << "Podskoki, Sklony, Skakanie" << endl;
				cout << "Skip A, Skip B, Skip C, " << endl;
				cout << "Krazenie ramion, Krazenie bioder,..." << endl;
				ZaplanujTrening();
				cout << " " << endl;
				system("pause");
				break;
			}
			case 2: {
				system("cls");
				WyswietlTrening();
				cout << " " << endl;
				system("pause");
				break;
			}
			case 0:
				showMenu = false;
				break;
			}
		} while (showMenu == true);
	}
};

//---------------------------------------------------------
class SprzetSportowy { //klasa abstrakcyjna
public:
	virtual void WiecejInformacji() = 0;
};

//---------------------------------------------------------
class Kantorek : public SprzetSportowy { //dziedziczenie
private:
	string nazwa = "Kantorek";
	int ilosc_pilek;
	int ilosc_siatek;
	vector<string> pilki;
	vector<string> siatki;
public:
	Kantorek() {}
	Kantorek(const string& _nazwa, const int& _ilosc_pilek, const int& _ilosc_siatek, const vector<string>& _pilki, const vector<string>& _siatki)
		: nazwa(_nazwa), ilosc_pilek(_ilosc_pilek), ilosc_siatek(_ilosc_siatek), pilki(_pilki), siatki(_siatki) {}
	//Kantorek(const Kantorek& kan);
	~Kantorek() {}
	string get_nazwa() {
		return nazwa;
	}
	void DodajPilke(const string& pilka);
	void DodajSiatke(const string& siatka);
	void Wyswietl();
	void WiecejInformacji() override { //polimorfizm 
		DodajPilke("Pilka firmy Mikasa");
		DodajPilke("Pilka firmy Copaya");
		DodajPilke("Pilka firmy Molten");
		DodajSiatke("Siatka firmy Enero");
		DodajSiatke("Siatka firmy Decathlon");
		Wyswietl();
	};
};

//---------------------------------------------------------

class Kontener {
private:
	int nr_pudelka;
	static Kantorek kantorek; //deklaracja obiektu statycznego
public:
	Kontener(int _nr_pudelka) : nr_pudelka(_nr_pudelka) {};
	int get_nr() {
		return nr_pudelka;
	};
};

//Kantorek Kontener::kantorek;

//---------------------------------------------------------

class Sklep : public Miejsce { //dziedziczenie
private:
	class Koszulka {
	private:
		friend class Sklep;
		string pseudonim_w_druzynie;
		string nazwisko_zawodnika;
		bool stan_zamowienia;
	public:
		Koszulka() {};
		Koszulka(string& _nazwisko_zawodnika, string& _pseudonim_w_druzynie, bool& _stan_zamowienia)
			: nazwisko_zawodnika(_nazwisko_zawodnika), pseudonim_w_druzynie(_pseudonim_w_druzynie), stan_zamowienia(_stan_zamowienia) {};
		~Koszulka() {};
		string get_pseudonim_w_druzynie() {
			return pseudonim_w_druzynie;
		};
		string get_nazwisko_zawodnika() {
			return nazwisko_zawodnika;
		};
		bool get_stan_zamowienia() {
			return stan_zamowienia;
		};
	};

	int iloscKoszulek;
	static const int iloscKontenerow = 5;
	vector<Kontener*> kontenery;
	vector<Koszulka*> koszulki;

public:
	Sklep() : iloscKoszulek(0) {}
	Sklep(int& _numer_grupy, const int& _iloscKoszulek, const vector<Koszulka*>& _koszulki)
		: iloscKoszulek(_iloscKoszulek), koszulki(_koszulki), Miejsce(_numer_grupy) {
		for (int i = 1; i <= iloscKontenerow; i++) {
			kontenery.push_back(new Kontener(i));
		}
	}
	~Sklep() {
		for (auto koszulka : koszulki) {
			delete koszulka;
		}
		koszulki.clear();

		for (auto kontener : kontenery) {
			delete kontener;
		}
		kontenery.clear();
	}
	int get_iloscKoszulek() {
		return iloscKoszulek;
	};
	const vector<Koszulka*>& get_koszulki() const {
		return koszulki;
	}
	void DodajKoszulke();
	void WyswietlZamowioneKoszulki();
	void UsunKoszulke();
	void Akcja() override { //polimorfizm 
		bool showMenu = true;
		size_t opcjasklep{};
		do {
			system("cls");
			cout << "ZAMOWIENIA" << endl;
			cout << "1. Dodac koszulke." << endl;
			cout << "2. Wyswietlic zamowione koszulki." << endl;
			cout << "3. Usunac koszulke." << endl;
			cout << "0. Cofnij sie do menu dziedziczenie" << endl;
			cout << "Wybierasz: ";
			cin >> opcjasklep;
			cin.ignore();
			system("cls");
			switch (opcjasklep) {
			case 1: {
				system("cls");
				DodajKoszulke();
				cout << " " << endl;
				system("pause");
				break;
			}
			case 2: {
				system("cls");
				WyswietlZamowioneKoszulki();
				cout << " " << endl;
				system("pause");
				break;
			}
			case 3: {
				system("cls");
				UsunKoszulke();
				cout << " " << endl;
				system("pause");
				break;
			}
			case 0:
				showMenu = false;
				break;
			}
		} while (showMenu == true);
	};
};

//-------------------------------------------------------------------------------------------------------------------

class LosoweId {
private:
	vector<int> iloscNumerow;
public:
	LosoweId() {
		srand(time(0));
		iloscNumerow.resize(20);
		for (int i = 0; i < 20; i++) {
			iloscNumerow[i] = rand() % 19 + 1;
		}
	}
	int& operator[](int index) { // przeciazenie [] operator
		if (index < 0 || index >= 20) {
			cout << "Blad." << std::endl;
			static int n = 0;
			return n;
		}
		return iloscNumerow[index];
	}
};

//-------------------------------------------------------------------------------------------------------------------

class Zawodnik {
	string imie;
	string nazwisko;
	string druzyna;
	int dzien;
	int miesiac;
	int rok;
	class Id {
		friend class Zawodnik;
		int numer = 0;
		friend istream& operator>>(istream& input, Zawodnik::Id& i);
		friend ostream& operator<<(ostream& output, const Zawodnik::Id i);

	public:
		Id() {};
		~Id() {};
		Id(int nr) : numer(nr) {};
		int getNumer() const {
			return numer;
		}
	};
	size_t iloscId = 0;
	vector<Id> ids;

	void DodajId();

	friend istream& operator>>(istream& input, Zawodnik& z);
	friend ostream& operator<<(ostream& output, const Zawodnik& z);
	friend istream& operator>>(istream& input, Zawodnik::Id& i);
	friend ostream& operator<<(ostream& output, const Zawodnik::Id i);

public:
	Zawodnik();
	Zawodnik(const string& _imie, const string& _nazwisko, const string& _druzyna, int _dzien, int _miesiac, int _rok)
		: imie(_imie), nazwisko(_nazwisko), druzyna(_druzyna), dzien(_dzien), miesiac(_miesiac), rok(_rok) {
	}
	Zawodnik(const Zawodnik& zaw);
	void Wyswietl();
	void WyswietlIds();
	string getPersonalia();
	string getDruzyne();
	int getDzien();
	int getMiesiac();
	int getRok();
	size_t getIloscIds();
	vector<Id>& getIds() {
		return ids;
	}
	void DodajIdKolejne() { return DodajId(); }
};

//-------------------------------------------------------------------------------------------------------------------

class Grupa {

	int IloscZawodnikow = 0;

	int maxIloscZawodnikow = 21;

	vector<Zawodnik*> zawodnicy;

	map<long, Trener*> trenerzy = {};

	Zawodnik* InicjalizujZawodnika();

	vector <Miejsce*> miejsca;

	/*
	int iloscPrzedmiotow = 5;
	std::map<Przedmiot*, int, MyCompare> lekcje = {};

	Sala** sale = nullptr;
	Sala* inicjalizujSale(set<long>& usedSalaNumbers);

	Biblioteka* biblioteka;
	Biblioteka* inicjalizujBiblioteke(set<long>& usedSalaNumbers);
	*/

	friend istream& operator>>(istream&, Grupa&);
	friend ostream& operator<<(ostream&, const Grupa&);

public:
	Grupa(int _IloscZawodnikow) {
		for (int i = 0; i < _IloscZawodnikow; i++) {
			zawodnicy.push_back(InicjalizujZawodnika());
		}
	}

	Grupa(const Grupa& Volley) {
		maxIloscZawodnikow = Volley.maxIloscZawodnikow;

		for (size_t i = 0; i < Volley.zawodnicy.size(); i++) {
			zawodnicy.push_back(new Zawodnik(*Volley.zawodnicy[i]));
		}
	}

	~Grupa() {
		for (size_t i = 0; i < zawodnicy.size(); i++) {
			delete zawodnicy[i];
		}
	}
	int getLiczbeZawodnikow();
	void DodajZawodnika();
	void WyswietlWszystkichZawodnikow();
	void Lista(const string& druzyna);
	void UsunLosowoZawodnika();
	void Edytuj(const Zawodnik& nowy);
	void EdytujDaneZawodnika(Grupa& Volley);

	void DodajIdLosowemuZawodnikowi(Grupa& Volley);
	void WyswietlIdLosowegoZawodnika();

	void ZapisDanychDoPliku(Grupa& Vzapis);
	//void WyswietlZawartosciPliku(const string& Vnazwapliku);
	string OdczytDanychZPliku(const string& nazwapliku);

	//Grupa& operator=(const Grupa&);
	Grupa& operator=(const Grupa& other) {
		if (this == &other)
			return *this;
		zawodnicy = other.zawodnicy;
		return *this;
	}

	Zawodnik& operator()(int index) {
		return *zawodnicy[index];
	}

	const Zawodnik& operator()(int index) const {
		return *zawodnicy[index];
	}

	void Dziedziczenie(Grupa& grupa);
};

//-------------------------------------------------------------------------------------------------------------------