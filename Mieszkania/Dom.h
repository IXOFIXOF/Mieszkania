#pragma once
#include "Mieszkanie.h"
class CDom : public CMieszkanie
{
public:
	CDom();
	virtual ~CDom();
	void UstalDaneSpecyficzne() override;
protected:
	int m_PowierzchniaOgrodu;
	void Print(ostream& sru) override;
};

