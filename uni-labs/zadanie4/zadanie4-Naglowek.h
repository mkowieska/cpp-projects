#pragma once
#include <string>;
#include <iostream>;
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int WylosujLiczbe(int from, int to);

class Zawodnik {
    string imie;
    string nazwisko;
	string druzyna;
    class Id  {
		friend class Zawodnik;
		int wartosc = 0; 
	public:
		Id() {};
		~Id() {};
		Id(int wart) : wartosc(wart)
		{};
		int getWartosc() const {
			return wartosc;
		}
	};
	size_t iloscId = 0;
	Id** ids = nullptr;
	
	void DodajId();
public:
	Zawodnik(); 
	Zawodnik(const string& _imie, const string& _nazwisko, const string& _druzyna); 
	Zawodnik(size_t& _iloscId, Id**& _id_s, const string& _imie, const string& _nazwisko, const string& _druzyna);
	//Zawodnik(const Zawodnik& zaw);
	~Zawodnik();
	void Wyswietl();
	string GetDruzyne(); 
	size_t GetIloscIds();
	Id** GetIds(){
		return ids;
	}
	void DodajIdKolejne()
	{
		return DodajId();
	}
	void WyswietlIds();
};

class Grupa {
    int maxIloscZawodnikow = 10;
    int IloscZawodnikow = WylosujLiczbe(0, maxIloscZawodnikow);
    Zawodnik** zawodnicy = nullptr;
    Zawodnik* InicjalizujZawodnika(); //obiekt
public:
    //size_t ilosc{};
	Grupa(int ilosc);
	Grupa(const Grupa& grupa);
	~Grupa(); //destruktor 
	void DodajZawodnika();
	void WyswietlWszystkichZawodnikow();
	void WyswietlLosowegoZawodnika();
	void UsunLosowoZawodnika();
	void Edytuj(const Zawodnik& nowyZawodnik);
	int GetLiczbeZawodnikow();
	void Wyczysc();

	void WyswietlIdLosowegoZawodnika();
	void Lista(const string& druzyna);
};

void gen_data(size_t& ilosc);
size_t generujLiczbeLosowa(size_t begin, size_t end);
bool WalidacjaImieniaLubNazwiska(const string& s);
bool WalidacjaSlowa(const string& s);

//void usun(Zawodnik*& zawodnik);
//void usun(Zawodnik*& zawodnik, const size_t ilosc);
//void usun(Zawodnik**& zawodnicy, size_t& ilosc);
//void usun(Zawodnik**& wszyscy, size_t& ilosc, size_t index);