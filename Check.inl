#include"Check.h"

//template<typename T>
//T Check<T>::inputCheck(const char* output)
//{
//	T temp;
//	while (true)
//	{
//		std::cout << output 
//			<< "\n\nEnter: ";
//		std::cin >> temp;
//		std::cin.ignore(32767, '\n');
//		if (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(32767, '\n');
//			std::cout << "Try again!";
//		}
//		else
//			return temp;
//	}
//}
//
//template<>
//std::string Check<std::string>::inputCheck(const char* output)
//{
//	std::string temp;
//	while (true)
//	{
//		std::cout << output
//			<< "\n\nEnter: ";
//		std::getline(std::cin, temp);
//		//std::cin.ignore(32767, '\n');
//		if (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(32767, '\n');
//			std::cout << "Try again!";
//		}
//		else
//			return temp;
//	}
//}