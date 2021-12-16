#include "Spend.h"

Spend::Spend(const std::string name, double sum)
	:m_name{ name }, m_sum{ sum }{};

const char* Spend::getClassName()
{
	return m_className;
}

std::ostream& operator<<(std::ostream& out, const Spend& spend)
{
	out << spend.m_name << ' ' << spend.m_sum;
	return out;
}
