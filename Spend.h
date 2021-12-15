#pragma once
#include<string>
#include<vector>
#include"Check.h"

class Participant;

class Spend
{
	friend std::ostream& operator <<(std::ostream& out, const Spend& spend);
public:
	Spend(std::string name = "", double sum = 0);
	static const char* getClassName();
	void setName();
	void setSum();
private:
	std::string m_name;
	double m_sum;
	std::vector<Participant*>participants_of_spend;
	static constexpr const char* m_className{ "Spend" };
};