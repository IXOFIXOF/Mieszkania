#include "stdafx.h"
#include "Lokator.h"


CLokator::CLokator()
{
}
CLokator::CLokator(CCzlowiek& Czlowiek)
{
	m_Nazwa = Czlowiek.PobierzNazwe();
	m_Wiek = Czlowiek.PobierzWiek();
	m_iCzynsz = 0;
}
void CLokator::UstalCzynsz()
{
	cout << "Podaj wysokosc czynszu dla tego lokatora\n";
		cin >> m_iCzynsz;
}
int CLokator::PobierzCzynsz()
{
	return m_iCzynsz;
}

void CLokator::print(ostream& sru)
{
	sru << "Jestem lokatorem. Mam na imie " << m_Nazwa <<" Moj czynsz to "<<m_iCzynsz<< endl;
}
CLokator::~CLokator()
{
}
