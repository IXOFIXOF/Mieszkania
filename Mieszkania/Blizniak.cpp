#include "stdafx.h"
#include "Blizniak.h"


CBlizniak::CBlizniak()
{
	m_Powierzchna = 0;
}
void CBlizniak::UstalDaneSpecyficzne()
{
	cout << "Podaj powierzchnie domu\n";
	cin >> m_Powierzchna;
}
void CBlizniak::Print(ostream& sru)
{
	sru << "Jestem blizniakiem. Moj adres to " << m_Adres << ". Moja powierzchnia to " << m_Powierzchna<<" ";
	if (m_Wlasciciel != nullptr)
	{
		sru << "Moj wlasciciel to " << m_Wlasciciel->PobierzNazwe() << ".\n";
	}
	else
	{
		sru << "Nie mam wlasciciela.\n";
	}
}
CBlizniak::~CBlizniak()
{
}
