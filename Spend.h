#pragma once
#include<string>
#include<vector>
#include<iostream>

class Participant;

class Spend
{
	friend std::ostream& operator <<(std::ostream& out, const Spend& spend);
public:
	Spend(const std::string name, double sum = 0);
	const std::string& getSpendName() const;
	const double& getSpendSum() const;
	static const char* getClassName();
	void toClearParticipantsOfSpend();
private:
	std::string m_name;
	double m_sum;
	std::vector<Participant*>m_participants_of_spend;
	static constexpr const char* m_className{ "Spend" };
};