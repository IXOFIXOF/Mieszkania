#pragma once
#include "Czlowiek.h"
class CLokator : public CCzlowiek
{
public:
	CLokator();
	virtual ~CLokator();
	void UstalCzynsz();
	int PobierzCzynsz();
protected:
	int m_iCzynsz;
};

