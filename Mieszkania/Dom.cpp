#include "stdafx.h"
#include "Dom.h"


CDom::CDom()
{
	m_PowierzchniaOgrodu = 0;
}
void CDom::Print(ostream& sru)
{
	sru << "Jestem domem. Moj adres to " << m_Adres << ". Powiechdnia mojego ogrodu to " << m_PowierzchniaOgrodu << "\n";
}
void CDom::UstalDaneSpecyficzne()
{
	cout << "Podaj powierzchnie ogrodu:\n";
	cin >> m_PowierzchniaOgrodu;
}

CDom::~CDom()
{
}
