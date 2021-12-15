#include "Participant.h"

Participant::Participant(std::string name)
	:m_name{ name } {}

const char* Participant::getClassName()
{
	return m_className;
}

void Participant::setName()
{
	m_name = Check::inputCheck<std::string>("Enter participant name");
}

std::ostream& operator<<(std::ostream& out, const Participant& participant)
{
	out << participant.m_name;
	return out;
}