#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

int WylosujLiczbe(int from, int to);

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
		int IloscNumerow[15];
		friend istream& operator>>(istream& input, Zawodnik::Id& i);
		friend ostream& operator<<(ostream& output, const Zawodnik::Id i);
	public:
		Id() {};
		~Id() {};
		Id(int nr) : numer(nr) {};
		int getNumer() const {
			return numer;
		}
		void incrementNumer() {
			numer++;
		}
		int getIloscNumerow(int index) const {
			return IloscNumerow[index];
		}
		void setIloscNumerow(int index, int value) {
			IloscNumerow[index] = value;
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

class ListaZawodnikow {
private:
	int iloscNumerow[15];
public:
	ListaZawodnikow() {
		srand(time(0));
		for (int i = 0; i < 15; i++) {
			iloscNumerow[i] = rand() % 1000000;
		}
	}
	int& operator[](int index) { //przeciazenie [] operator
		if (index < 0 || index >= 15) {
			cout << "Blad." << endl;
		}
		return iloscNumerow[index];
	}
};

class Grupa {
	int IloscZawodnikow = 0; // = WylosujLiczbe(0, maxIloscZawodnikow);
	int maxIloscZawodnikow = 20;

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
};

void gen_data(size_t& ilosc);
size_t generujLiczbeLosowa(size_t begin, size_t end);
bool WalidacjaImieniaLubNazwiska(const string& s);
bool WalidacjaSlowa(const string& s);