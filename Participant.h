#pragma once
#include<string>
#include<vector>

class Spend;

class Participant
{
public:
	Participant(std::string name);
private:
	std::string m_name;
	std::vector<Spend*>spends_of_participant;
};