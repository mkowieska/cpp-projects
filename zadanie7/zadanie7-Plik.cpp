#include "Nag³ówek77.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Grupa::ZapisDanychDoPliku(Grupa& Vzapis) {
	fstream plik{};
	plik.open("Baza.txt");
	if (!plik.is_open()) {
		cout << "Blad. Plik. " << endl;
		return;
	}
	plik << Vzapis;
	plik.close();
}

string Grupa::OdczytDanychZPliku(const string& nazwapliku) {
	ifstream file(nazwapliku);
	string content;
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			content += line + "\n";
		}
		file.close();
	}
	else {
		content = "Blad. Plik.\n";
	}
	return content;
}