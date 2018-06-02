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


CCzlowiek::~CCzlowiek()
{
}
