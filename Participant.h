#pragma once
#include<string>
#include<vector>
#include<iostream>

class Spend;

class Participant
{
	friend std::ostream& operator <<(std::ostream& out, const Participant& participant);
public:
	Participant(std::string name);
	static const char* getClassName();
private:
	std::string m_name;
	std::vector<Spend*>spends_of_participant;
	static constexpr const char* m_className{ "Participant" };
};