#include "Check.h"

Bad_trip::Bad_trip(const char* info) :m_info{ info } {}

const char* Bad_trip::what() const noexcept
{
	return m_info.c_str();
}
