#include "stdafx.h"
#include "Lokator.h"


CLokator::CLokator()
{
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

CLokator::~CLokator()
{
}
