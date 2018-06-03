#pragma once

class CCzlowiek
{
public:
	CCzlowiek();
	virtual ~CCzlowiek();

	void UstalNazwe();
	void UstalWiek();
	string PobierzNazwe();
	int PobierzWiek();
	virtual void print(ostream& sru);
	friend ostream& operator<<(ostream& sru, CCzlowiek* Czlowiek);
protected:
	string m_Nazwa;
	int m_Wiek;
};

