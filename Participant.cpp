#include "Participant.h"

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