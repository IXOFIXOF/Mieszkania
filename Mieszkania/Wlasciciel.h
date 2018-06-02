#pragma once
#include "Czlowiek.h"
class CWlasciciel : public CCzlowiek
{
public:
	CWlasciciel();
	void UstalDochod( int n);
	int PobierzDochod();
	virtual ~CWlasciciel();
protected:
	int m_Dochod;
};

