#include "Participant.h"
#include"Spend.h"

Participant::Participant(const std::string name)
	:m_name{ name } {}

const std::string& Participant::getParticipantName() const
{
	return m_name;
}

const char* Participant::getClassName()
{
	return m_className;
}

void Participant::toClearSpendsOfParticipant()
{
	m_spends_of_participant.clear();
}

std::ostream& operator<<(std::ostream& out, const Participant& participant)
{
	out << participant.m_name;
	return out;
}

/////////////////////////////////////////////////////////
const int Participant::addSpend(const Spend* spend)
{
	for (auto& el : m_spends_of_participant)
		if (el == spend)
			return 1;
	m_spends_of_participant.emplace_back(spend);
	return 0;
}

void Participant::showSpend()
{
	double sum = 0;
	for (auto& el : m_spends_of_participant)
	{
		std::cout << el->getSpendName() << '\t' << std::fixed << std::setprecision(2) << el->getSpendSum() / static_cast<double>(el->m_participants_of_spend.size()) << '\n';
		sum += el->getSpendSum() / static_cast<double>(el->m_participants_of_spend.size());
	}
	std::cout << "\tSum: \t" << sum;
}
