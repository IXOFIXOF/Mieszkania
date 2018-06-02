// Mieszkania.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Blizniak.h"
#include "Blok.h"
#include "Czlowiek.h"
#include "Dom.h"
#include "Lokator.h"
#include "Mieszkanie.h"
#include "Wlasciciel.h"
/*Zalozenia:
Jedno mieszkanie moze miec jednego wlasciciela
Jeden wlasciciel moze byc wlascicielem kilku mieszkan
Jeden lokator moze byc przypisany do jednego mieszkania*/
CMieszkanie* DodajMieszkanie();
CCzlowiek*   DodajCzlowieka();
void WyswietlDomy();
void WyswietlNieprzypisanychLudzi();
int main()
{
	vector<CMieszkanie*> Mieszkania;
	vector<CCzlowiek*> Ludzie;



	
	std::cout << "Klasy bazowe mieszkania, ludzie i klasy pochodne blok, dom, bli�niak, w�a�ciciel,"
		<<" lokator itd. Przeci��y� operator strumienia i dodawania i odejmowania z do mieszkania"
		<<" lokator�w i w�a�cicieli i par� wed�ug w�asnego pomys�u.\n";
	std::cin.get();
    return 0;
}

