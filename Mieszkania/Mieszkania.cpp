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
Jeden lokator moze byc przypisany do jednego mieszkania
Ka¿dy czlowiek moze stac sie albo wlascicielem, albo lokatorem
Kazdy czlowiek w danej chwili moze byc albo wlascicielem, albo lokatorem*/
CMieszkanie* DodajMieszkanie();
CCzlowiek*   DodajCzlowieka();
void DodajWlascicielaDoMieszkania(vector<CMieszkanie*>& Mieszkania, vector<CCzlowiek*>& Ludzie);
void DodajLokatoraDoMieszkania(vector<CMieszkanie*>& Mieszkania, vector<CCzlowiek*>& Ludzie);
void UsunWlascicielaZMieszkania(vector<CMieszkanie*>& Mieszkania, vector<CCzlowiek*>& Ludzie);
void UsunLokatoraZMieszkania(vector<CMieszkanie*>& Mieszkania, vector<CCzlowiek*>& Ludzie);
void WyswietlDomy(vector<CMieszkanie*> Mieszkania );
void WyswietlLudzi(vector<CCzlowiek*> Ludzie);
int main()
{
	vector<CMieszkanie*> Mieszkania;
	vector<CCzlowiek*> Ludzie;
	int wybor = 0;
	do
	{
		cout << "1. Dodaj mieszkanie\n2. Dodaj czlowieka\n3. Dodaj wlasciciela do mieszkania\n"
			<< "4. Dodaj lokatora do mieszkania\n5. Usun wlasciciela z mieszkania\n6. Usun lokatora z mieszkania\n"
			<<"7. Wyswietl Domy\n8. Wyswietl ludzi\n9. Koniec\n";
		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			Mieszkania.push_back(DodajMieszkanie());
			system("cls");
			break;
		}
		case 2:
		{
			Ludzie.push_back(DodajCzlowieka());
			system("cls");
			break;
		}
		case 3:
		{
			DodajWlascicielaDoMieszkania(Mieszkania, Ludzie);
			system("cls");
			break;
		}
		case 4:
		{
			DodajLokatoraDoMieszkania(Mieszkania, Ludzie);
			system("cls");
			break;
		}
		case 5:
		{
			UsunWlascicielaZMieszkania(Mieszkania, Ludzie);
			system("cls");
			break;
		}
		case 6:
		{
			UsunLokatoraZMieszkania(Mieszkania, Ludzie);
			system("cls");
			break;
		}
		case 7:
		{
			WyswietlDomy( Mieszkania );
			break;
		}
		case 8:
		{
			WyswietlLudzi( Ludzie );
			break;
		}
		default:
			break;
		}
	} while (wybor != 9);


	
	std::cout << "Klasy bazowe mieszkania, ludzie i klasy pochodne blok, dom, bliŸniak, w³aœciciel,"
		<<" lokator itd. Przeci¹¿yæ operator strumienia i dodawania i odejmowania z do mieszkania"
		<<" lokatorów i w³aœcicieli i parê wed³ug w³asnego pomys³u.\n";
	std::cin.get();
    return 0;
}
CMieszkanie* DodajMieszkanie()
{
	CMieszkanie* DoDodania = nullptr;
	cout << "1. Blizniak\n2. Blok\n3. Dom\n4. Mieszkanie\n";
	int wybor = 0;
	cin >> wybor;
	switch (wybor)
	{
	case 1: DoDodania = new CBlizniak; break;
	case 2: DoDodania = new CBlok; break;
	case 3: DoDodania = new CDom; break;
	case 4: DoDodania = new CMieszkanie; break;
	default:
		break;
	}
	DoDodania->UstalAdres();
	DoDodania->UstalDaneSpecyficzne();

	return DoDodania;
}
CCzlowiek* DodajCzlowieka()
{
	CCzlowiek* DoDodania = nullptr;
	DoDodania = new CCzlowiek;
	DoDodania->UstalNazwe();
	DoDodania->UstalWiek();

	return DoDodania;
}
void WyswietlDomy(vector<CMieszkanie*> Mieszkania)
{
	vector<CMieszkanie*> ::iterator it;
	it = Mieszkania.begin();
	if (it == Mieszkania.end())
	{
		cout << "Brak mieszkan na liscie\n";
	}
	else
	{
		while (it != Mieszkania.end())
		{
			cout << *it;
			it++;
		}
	}
}
void WyswietlLudzi(vector<CCzlowiek*> Ludzie)
{
	vector<CCzlowiek*> ::iterator it;
	it = Ludzie.begin();
	if (it == Ludzie.end())
	{
		cout << "Brak ludzi na liscie\n";
	}
	else
	{
		while (it != Ludzie.end())
		{
			cout << *it;
			it++;
		}
	}
}
void DodajWlascicielaDoMieszkania(vector<CMieszkanie*>& Mieszkania, vector<CCzlowiek*>& Ludzie)
{
	vector<CMieszkanie*> ::iterator itMieszkania = Mieszkania.begin();
	vector<CCzlowiek*> ::iterator itLudzie = Ludzie.begin();
	CWlasciciel* NowyWlasciciel = nullptr;
	int KtoreMieszkanie = 0;
	int KtoryCzlowiek = 0;
	int licznik = 1;
	while (itMieszkania != Mieszkania.end())
	{
		cout << licznik << ". " << *itMieszkania;
		licznik++; itMieszkania++;
	}
	cin >> KtoreMieszkanie;
	licznik = 1;
	while (itLudzie != Ludzie.end())
	{
		cout << licznik << ". " << *itLudzie;
		licznik++; itLudzie++;
	}
	cin >> KtoryCzlowiek;
	NowyWlasciciel = new CWlasciciel(*Ludzie[KtoryCzlowiek - 1]);
	delete Ludzie[KtoryCzlowiek - 1];
	Ludzie[KtoryCzlowiek - 1] = NowyWlasciciel;
	*Mieszkania[KtoreMieszkanie - 1] = *Mieszkania[KtoreMieszkanie - 1] + NowyWlasciciel;
}
void DodajLokatoraDoMieszkania(vector<CMieszkanie*>& Mieszkania, vector<CCzlowiek*>& Ludzie)
{
	vector<CMieszkanie*> ::iterator itMieszkania = Mieszkania.begin();
	vector<CCzlowiek*> ::iterator itLudzie = Ludzie.begin();
	CLokator* NowyLokator = nullptr;
	int KtoreMieszkanie = 0;
	int KtoryCzlowiek = 0;
	int licznik = 1;
	while (itMieszkania != Mieszkania.end())
	{
		cout << licznik << ". " << *itMieszkania;
		licznik++; itMieszkania++;
	}
	cin >> KtoreMieszkanie;
	if (Mieszkania[KtoreMieszkanie - 1]->PobierzWlasciciela() != nullptr)
	{
		licznik = 1;
		while (itLudzie != Ludzie.end())
		{
			cout << licznik << ". " << *itLudzie;
			licznik++; itLudzie++;
		}
		cin >> KtoryCzlowiek;
		NowyLokator = new CLokator(*Ludzie[KtoryCzlowiek - 1]);
		delete Ludzie[KtoryCzlowiek - 1];
		Ludzie[KtoryCzlowiek - 1] = NowyLokator;
		*Mieszkania[KtoreMieszkanie - 1] = *Mieszkania[KtoreMieszkanie - 1] + NowyLokator;
	}
	else
	{
		cout << "To mieszkanie nie ma wlasciciela![enter]" << endl;
		cin.ignore();
		cin.get();
	}

}
void UsunWlascicielaZMieszkania(vector<CMieszkanie*>& Mieszkania, vector<CCzlowiek*>& Ludzie)
{
	vector<CMieszkanie*> ::iterator itMieszkania = Mieszkania.begin();
	vector<CCzlowiek*> ::iterator itLudzie = Ludzie.begin();
	CCzlowiek* OdTerazTylkoCzlowiek;
	int KtoreMieszkanie = 0;
	int KtoryCzlowiek = 0;
	int licznik = 1;
	while (itMieszkania != Mieszkania.end())
	{
		cout << licznik << ". " << *itMieszkania;
		licznik++; itMieszkania++;
	}
	cin >> KtoreMieszkanie;
	CWlasciciel* Wlasciciel = Mieszkania[KtoreMieszkanie - 1]->PobierzWlasciciela();
	itLudzie = find(Ludzie.begin(), Ludzie.end(), Wlasciciel);
	OdTerazTylkoCzlowiek = new CCzlowiek(*Wlasciciel);
	KtoryCzlowiek = distance(Ludzie.begin(), itLudzie);
	Ludzie[KtoryCzlowiek] = OdTerazTylkoCzlowiek;
	*Mieszkania[KtoreMieszkanie - 1] = *Mieszkania[KtoreMieszkanie - 1] - Wlasciciel;
	delete Wlasciciel;
}
void UsunLokatoraZMieszkania(vector<CMieszkanie*>& Mieszkania, vector<CCzlowiek*>& Ludzie)
{
	vector<CMieszkanie*> ::iterator itMieszkania = Mieszkania.begin();
	vector<CCzlowiek*> ::iterator itLudzie = Ludzie.begin();
	int KtoreMieszkanie = 0;
	int KtoryCzlowiek = 0;
	int licznik = 1;
	while (itMieszkania != Mieszkania.end())
	{
		cout << licznik << ". " << *itMieszkania;
		licznik++; itMieszkania++;
	}
	cin >> KtoreMieszkanie;
	Mieszkania[KtoreMieszkanie - 1]->WyswietlLokatorow();
	cin >> KtoryCzlowiek;
	CLokator* Lokator = Mieszkania[KtoreMieszkanie - 1]->PobierzLokatora(KtoryCzlowiek - 1);
	CCzlowiek* OdTerazTylkoCzlowiek = new CCzlowiek(*Lokator);
	itLudzie = find(Ludzie.begin(), Ludzie.end(), Lokator);
	KtoryCzlowiek = distance(Ludzie.begin(), itLudzie);
	Ludzie[KtoryCzlowiek] = OdTerazTylkoCzlowiek;
	*Mieszkania[KtoreMieszkanie - 1] = *Mieszkania[KtoreMieszkanie - 1] - Lokator;
	delete Lokator;
}