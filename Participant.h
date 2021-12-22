#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<iomanip>

class Spend;

class Participant
{
	friend std::ostream& operator <<(std::ostream& out, const Participant& participant);
public:
	Participant(const std::string name);
	const std::string& getParticipantName() const;
	static const char* getClassName();
	void toClearSpendsOfParticipant();
	/////////////////////////////////////////
	//const Participant* operator[]
	const int addSpend(const Spend* spend);
	void showSpend();
private:
	std::string m_name;
	std::vector<const Spend*>m_spends_of_participant;
	static constexpr const char* m_className{ "Participant" };
};