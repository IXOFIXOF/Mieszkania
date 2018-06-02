#pragma once
#include "Lokator.h"
#include "Wlasciciel.h"
class CMieszkanie
{
public:
	CMieszkanie();
	virtual ~CMieszkanie();
	string PobierzAdres();
	void UstalAdres();
	CWlasciciel* PobierzWlasciciela();
	virtual void UstalDaneSpecyficzne();
	friend ostream& operator<<(ostream& sru, CMieszkanie* Mieszkanie);
	friend CMieszkanie& operator+(CMieszkanie& Mieszkanie, CLokator* Lokator);
	friend CMieszkanie& operator+(CMieszkanie& Mieszkanie, CWlasciciel* Wlasciciel);
	friend CMieszkanie& operator-(CMieszkanie& Mieszkanie, CLokator* Lokator);
	friend CMieszkanie& operator-(CMieszkanie& Mieszkanie, CWlasciciel* Wlasciciel);
protected:
	string m_Adres;
	vector<CLokator*> m_Lokatorzy;
	CWlasciciel* m_Wlasciciel;
	virtual void Print(ostream& sru);
};

