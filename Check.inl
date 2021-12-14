#include"Check.h"

template<typename T>
T Check::inputCheck(const char* output)
{
	T temp;
	while (true)
	{
		std::cout << output 
			<< "\n\nEnter: ";
		std::cin >> temp;
		std::cin.ignore(32767, '\n');
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
			return temp;
	}
}