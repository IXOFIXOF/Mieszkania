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

protected:
	string m_Nazwa;
	int m_Wiek;
};

