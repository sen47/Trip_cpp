#include "Spend.h"

Spend::Spend(const std::string name, double sum)
	:m_name{ name }, m_sum{ sum }{}

const std::string& Spend::getSpendName() const
{
	return m_name;
}

double Spend::getSpendSum() const
{
	return m_sum;
}

const char* Spend::getClassName()
{
	return m_className;
}

void Spend::toClearParticipantsOfSpend()
{
	m_participants_of_spend.clear();
}

std::ostream& operator<<(std::ostream& out, const Spend& spend)
{
	out << spend.m_name << ' ' << spend.m_sum;
	return out;
}

//////////////////////////////////////////////////////////
void Spend::addParticipant(const Participant* participant)
{
	m_participants_of_spend.emplace_back(participant);
}

bool Spend::isInParticipants(Participant* participant) const
{
	for (auto el : m_participants_of_spend)
		if (el == participant)
			return true;
	return false;
}
