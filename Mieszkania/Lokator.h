#pragma once
#include "Czlowiek.h"
class CLokator : public CCzlowiek
{
public:
	CLokator();
	CLokator(CCzlowiek& Czlowiek);
	virtual ~CLokator();
	void UstalCzynsz();
	int PobierzCzynsz();
protected:
	int m_iCzynsz;
	void print(ostream& sru) override;
};

