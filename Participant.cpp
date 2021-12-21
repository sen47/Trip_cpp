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
void Participant::addSpend(const Spend* spend)
{
	m_spends_of_participant.emplace_back(spend);
}

void Participant::showSpend()
{
	for (auto& el : m_spends_of_participant)
	{
		std::cout << el->getClassName() << '\t' << el->getSpendSum() / static_cast<double>(el->m_participants_of_spend.size()) << '\n';
	}
}
