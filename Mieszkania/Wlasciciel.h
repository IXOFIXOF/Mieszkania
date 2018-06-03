#pragma once
#include "Czlowiek.h"
class CWlasciciel : public CCzlowiek
{
public:
	CWlasciciel();
	CWlasciciel(CCzlowiek& Czlowiek);
	void UstalDochod( int n);
	int PobierzDochod();
	void print(ostream& sru) override;
	virtual ~CWlasciciel();
protected:
	int m_Dochod;
};

