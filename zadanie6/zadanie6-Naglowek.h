#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

int WylosujLiczbe(int from, int to);
void gen_data(size_t& ilosc);
size_t generujLiczbeLosowa(size_t begin, size_t end);
bool WalidacjaImieniaLubNazwiska(const string& s);
bool WalidacjaSlowa(const string& s);

//----------------------------------------------------------------------------------------------------------------------------
class Miejsce { //klasa abstrakcyjna
private:
	bool trening;
	int numer_sali;
public:
	Miejsce() {};
	Miejsce(bool& _trening, const int& _numer_sali)
		: trening(_trening), numer_sali(_numer_sali) {};
	~Miejsce() {};
	bool get_trening() {
		return trening;
	};
	int get_numer_sali() {
		return numer_sali;
	};
	void set_trening(bool value) {
		trening = value;
	}
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
	string* trening; 

public:
	SalaGimnastyczna() {
		trening = new string[5]; 
	}
	~SalaGimnastyczna() {
		delete[] trening;
	}
	void ZaplanujTrening();
	void WyswietlTrening();
	void Akcja() override { //polimorfizm 
		bool showMenu = true;
		SalaGimnastyczna salagimnastyczna;
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
				salagimnastyczna.ZaplanujTrening();
				cout << " " << endl;
				system("pause");
				break;
			}
			case 2: {
				system("cls");
				salagimnastyczna.WyswietlTrening();
				delete[] trening;
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

class Kantorek : public Miejsce { //dziedziczenie
private:
	string nazwa = "Kantorek";
	int ilosc_pilek;
	int ilosc_siatek;
	string* pilki;
	string* siatki;
public:
	Kantorek() {
		pilki = nullptr;
		siatki = nullptr;
	};
	Kantorek(const string& _nazwa, const int& _ilosc_pilek, const int& _ilosc_siatek)
		: nazwa(_nazwa), ilosc_pilek(_ilosc_pilek), ilosc_siatek(_ilosc_siatek) {
		pilki = new string[ilosc_pilek];
		siatki = new string[ilosc_siatek];
	}
	Kantorek(const Kantorek& kan);
	~Kantorek() {
		delete[] pilki;
		delete[] siatki;
	}
	string get_nazwa() {
		return nazwa;
	}
	void DodajPilke(const string& pilka);
	void DodajSiatke(const string& siatka);
	void Wyswietl();
	void Akcja() override { //polimorfizm 
		Kantorek kantorek;
		kantorek.DodajPilke("Pilka firmy Mikasa");
		kantorek.DodajPilke("Pilka firmy Copaya");
		kantorek.DodajPilke("Pilka firmy Molten");
		kantorek.DodajSiatke("Siatka firmy Enero");
		kantorek.DodajSiatke("Siatka firmy Decathlon");
		kantorek.Wyswietl();
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
	Kontener* kontenery[iloscKontenerow];

	Koszulka** koszulki;
public:
	Sklep() {};
	Sklep(int& _iloscKoszulek, Koszulka**& _koszulki) : iloscKoszulek(_iloscKoszulek), koszulki(_koszulki) {
		kontenery[0] = new Kontener(1);
		kontenery[1] = new Kontener(2);
		kontenery[2] = new Kontener(3);
		kontenery[3] = new Kontener(4);
		kontenery[4] = new Kontener(5);
	};
	~Sklep() {
		for (size_t i = 0; i < iloscKoszulek; i++) {
			delete koszulki[i];
		}
		delete[] koszulki;
		koszulki = nullptr;
		iloscKoszulek = 0;
	}
	int get_iloscKoszulek() {
		return iloscKoszulek;
	};
	Koszulka** get_koszulki() {
		return koszulki;
	};
	void DodajKoszulke();
	void WyswietlZamowioneKoszulki();
	void UsunKoszulke();
	void Akcja() override { //polimorfizm 
		bool showMenu = true;
		//Sklep sklep;
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
	int iloscNumerow[10];
public:
	LosoweId() {
		srand(time(0));
		for (int i = 0; i < 10; i++) {
			iloscNumerow[i] = rand() % 1000000;
		}
	}
	int& operator[](int index) { //przeciazenie [] operator
		if (index < 0 || index >= 10) {
			cout << "Blad." << endl;
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
	Id** ids = nullptr;

	void DodajId();

	friend istream& operator>>(istream& input, Zawodnik& z);
	friend ostream& operator<<(ostream& output, const Zawodnik& z);
	friend istream& operator>>(istream& input, Zawodnik::Id& i);
	friend ostream& operator<<(ostream& output, const Zawodnik::Id i);

public:
	Zawodnik();
	Zawodnik(const string& _imie, const string& _nazwisko, const string& _druzyna, int _dzien, int _miesiac, int _rok);
	Zawodnik(size_t& _iloscId, Id**& _id_s, const string& _imie, const string& _nazwisko, const string& _druzyna, int _dzien, int _miesiac, int _rok);
	Zawodnik(const Zawodnik& zaw);
	~Zawodnik();
	void Wyswietl();
	void WyswietlIds();
	string getPersonalia();
	string getDruzyne();
	int getDzien();
	int getMiesiac();
	int getRok();
	size_t getIloscIds();
	Id** getIds() {
		return ids;
	}
	void DodajIdKolejne() { return DodajId(); }
};

//-------------------------------------------------------------------------------------------------------------------

class Grupa {
	int IloscZawodnikow = 0;
	int maxIloscZawodnikow = 10;
	Zawodnik** zawodnicy = nullptr;
	Zawodnik* InicjalizujZawodnika();

	friend istream& operator>>(istream&, Grupa&);
	friend ostream& operator<<(ostream&, const Grupa&);

public:
	Grupa(int IloscZawodnikow);
	Grupa(const Grupa& grupa);
	~Grupa();

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

	Grupa& operator=(const Grupa&);
	Zawodnik& operator()(int index) {
		return *zawodnicy[index];
	};
	Zawodnik& operator[](int index) {
		return *zawodnicy[index];
	};

	void Dziedziczenie(Grupa& grupa);
};

//-------------------------------------------------------------------------------------------------------------------