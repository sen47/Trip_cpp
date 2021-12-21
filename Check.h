#pragma once
#include<iostream>
#include<string>
#include<exception>

template<typename T>
class Check
{
public:
	//checking input value, for match data type
	static T inputCheck(const char* output = "")
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
				std::cout << "Try again!";
			}
			else
				return temp;
		}
	}
};

template<>
class Check<std::string>
{
public:
	//checking input value, for match data type
	static std::string inputCheck(const char* output = "")
	{
		std::string temp;
		while (true)
		{
			std::cout << output
				<< "\n\nEnter: ";
			std::getline(std::cin, temp);
			//std::cin.ignore(32767, '\n');
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Try again!";
			}
			else
				return temp;
		}
	}
};

//#include"Check.inl"

class Bad_trip :public std::exception
{
public:
	Bad_trip(const char* info);
	const char* what()const noexcept override;
private:
	std::string m_info;
};