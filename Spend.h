#pragma once
#include<string>
#include<vector>
#include"Check.h"

class Participant;

class Spend
{
	friend std::ostream& operator <<(std::ostream& out, const Spend& spend);
public:
	Spend(const std::string name, double sum = 0);
	static const char* getClassName();
private:
	std::string m_name;
	double m_sum;
	std::vector<Participant*>participants_of_spend;
	static constexpr const char* m_className{ "Spend" };
};