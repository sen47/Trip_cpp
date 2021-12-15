#include "Spend.h"

Spend::Spend(std::string name, double sum)
	:m_name{ name }, m_sum{ sum }{}

const char* Spend::getClassName()
{
	return m_className;
}

void Spend::setName()
{
	m_name = Check::inputCheck<std::string>("Enter name of spend");
}

void Spend::setSum()
{
	m_sum = Check::inputCheck<double>("\nEnter spend sum");
}

std::ostream& operator<<(std::ostream& out, const Spend& spend)
{
	out << spend.m_name << ' ' << spend.m_sum;
	return out;
}
