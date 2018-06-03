#include "stdafx.h"
#include "Czlowiek.h"


CCzlowiek::CCzlowiek()
{
	m_Nazwa = "Nie ustalono nazwy";
	m_Wiek = 0;
}

void CCzlowiek::UstalNazwe()
{
	cout << "Podaj nazwe\n";
	cin.ignore();
	getline(cin, m_Nazwa);
}
void CCzlowiek::UstalWiek()
{
	cout << "Podaj wiek\n";
	cin >> m_Wiek;
}
string CCzlowiek::PobierzNazwe()
{
	return m_Nazwa;
}
int CCzlowiek::PobierzWiek()
{
	return m_Wiek;
}
void CCzlowiek::print(ostream& sru)
{
	sru << "Jestem " <<m_Nazwa << " i mam " << m_Wiek << " lat.\n";
}
ostream& operator<<(ostream& sru, CCzlowiek* czlowiek)
{
	czlowiek->print(sru);
	return sru;
}
CCzlowiek::~CCzlowiek()
{
}
