#pragma once
#include<string>
#include<vector>

class Participant;

class Spend
{
public:
	Spend(std::string name, double sum);
private:
	std::string m_name;
	double m_sum;
	std::vector<Participant*>participants_of_spend;
};