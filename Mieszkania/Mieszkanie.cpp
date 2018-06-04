#include "stdafx.h"
#include "Mieszkanie.h"


CMieszkanie::CMieszkanie()
{
	m_Adres = "Nie podano adresu";
	m_Wlasciciel = nullptr;
}
string CMieszkanie::PobierzAdres()
{
	return m_Adres;
}
CWlasciciel* CMieszkanie::PobierzWlasciciela()
{
	return m_Wlasciciel;
}
void CMieszkanie::UstalAdres()
{
	cout << "Podaj adres\n";
	cin.ignore();
	getline(cin, m_Adres);
}
void CMieszkanie::Print(ostream& sru)
{
	sru << "Jestem mieszkaniem. Moj adres to " << m_Adres << ". Mam " << m_Lokatorzy.size() << " lokatorow. ";
	if (m_Wlasciciel != nullptr)
	{
		sru << "Moj wlasciciel to " << m_Wlasciciel->PobierzNazwe() << ".\n";
	}
	else
	{
		sru << "Nie mam wlasciciela.\n";
	}
}
ostream& operator<<(ostream& sru, CMieszkanie* Mieszkanie)
{
	Mieszkanie->Print(sru);
	return sru;
}
CMieszkanie& operator+(CMieszkanie& Mieszkanie, CLokator* Lokator)
{
	if (Mieszkanie.m_Wlasciciel != nullptr)
	{
		Mieszkanie.m_Lokatorzy.push_back(Lokator);
		Lokator->UstalCzynsz();
		Mieszkanie.m_Wlasciciel->UstalDochod(Lokator->PobierzCzynsz());
	}

	return Mieszkanie;
}
CMieszkanie& operator+(CMieszkanie& Mieszkanie, CWlasciciel* Wlasciciel)
{
	Mieszkanie.m_Wlasciciel = Wlasciciel;
	Mieszkanie.m_Wlasciciel->UstalDochod( Mieszkanie.UstalSumeCzynszu());
	if (Mieszkanie.m_Wlasciciel != nullptr)
	{
		cout << "Wlasciciel mieszkania zostal zmieniony\n";
	}

	return Mieszkanie;
}
CMieszkanie& operator-(CMieszkanie& Mieszkanie, CLokator* Lokator)
{
	if (Mieszkanie.m_Wlasciciel != nullptr)
	{
		Mieszkanie.m_Wlasciciel->UstalDochod(Lokator->PobierzCzynsz() * -1);
	}
	vector<CLokator*>::iterator it = find(Mieszkanie.m_Lokatorzy.begin(), Mieszkanie.m_Lokatorzy.end(), Lokator);
	Mieszkanie.m_Lokatorzy.erase(it);
	return Mieszkanie;
}
CMieszkanie& operator-(CMieszkanie& Mieszkanie, CWlasciciel* Wlasciciel)
{
	Mieszkanie.m_Wlasciciel = nullptr;
	return Mieszkanie;
}
void CMieszkanie::UstalDaneSpecyficzne()
{

}
CLokator* CMieszkanie::PobierzLokatora(int n)
{
	return m_Lokatorzy[n];
}
void CMieszkanie::WyswietlLokatorow()
{
	int licznik = 1;
	vector<CLokator*>::iterator it;
	it = m_Lokatorzy.begin();
	while (it != m_Lokatorzy.end())
	{
		cout << licznik << ". " << (*it)->PobierzNazwe() << endl;
		it++; licznik++;
	}
}
int CMieszkanie::UstalSumeCzynszu()
{
	int licznik = 0;
	vector<CLokator*>::iterator it;
	it = m_Lokatorzy.begin();
	while (it != m_Lokatorzy.end())
	{
	   licznik += (*it)->PobierzCzynsz();
	   it++;
	}
	return licznik;
}

CMieszkanie::~CMieszkanie()
{
}

