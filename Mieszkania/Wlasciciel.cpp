#include "stdafx.h"
#include "Wlasciciel.h"


CWlasciciel::CWlasciciel()
{
	m_Dochod = 0;
}

CWlasciciel::CWlasciciel(CCzlowiek& Czlowiek)
{
	m_Nazwa = Czlowiek.PobierzNazwe();
	m_Wiek = Czlowiek.PobierzWiek();
	m_Dochod = 0;
}
int CWlasciciel::PobierzDochod()
{
	return m_Dochod;
}
void CWlasciciel::UstalDochod( int n )
{
	m_Dochod += n;
}
void CWlasciciel::print(ostream& sru)
{
	sru << "Jestem " << m_Nazwa << " i mam " << m_Wiek << " lat. "
		<< "Moj dochod miesieczny to " << m_Dochod << endl;
}
CWlasciciel::~CWlasciciel()
{
}
