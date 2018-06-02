#pragma once
#include "Mieszkanie.h"
class CBlizniak : public CMieszkanie
{
public:
	CBlizniak();
	virtual ~CBlizniak();
	void UstalDaneSpecyficzne() override;
protected:
	void Print(ostream& sru) override;
	int m_Powierzchna;
};

