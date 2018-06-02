#include "stdafx.h"
#include "Wlasciciel.h"


CWlasciciel::CWlasciciel()
{
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

CWlasciciel::~CWlasciciel()
{
}
