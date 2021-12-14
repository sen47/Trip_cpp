#include "Participant.h"

Participant::Participant(std::string name)
	:m_name{ name } {}

const char* Participant::getClassName()
{
	return m_className;
}
;

std::ostream& operator<<(std::ostream& out, const Participant& participant)
{
	out << participant.m_name;
	return out;
}
