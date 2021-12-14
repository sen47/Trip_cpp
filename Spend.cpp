#include "Spend.h"

Spend::Spend(std::string name, double sum)
	:m_name{ name }, m_sum{ sum }{}

const char* Spend::getClassName()
{
	return m_className;
}
;
