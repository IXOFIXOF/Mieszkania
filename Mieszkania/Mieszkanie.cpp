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

	return Mieszkanie;
}
CMieszkanie& operator+(CMieszkanie& Mieszkanie, CWlasciciel* Wlasciciel)
{

	return Mieszkanie;
}
CMieszkanie& operator-(CMieszkanie& Mieszkanie, CLokator* Lokator)
{

	return Mieszkanie;
}
CMieszkanie& operator-(CMieszkanie& Mieszkanie, CWlasciciel* Wlasciciel)
{

	return Mieszkanie;
}
void CMieszkanie::UstalDaneSpecyficzne()
{

}


CMieszkanie::~CMieszkanie()
{
}

