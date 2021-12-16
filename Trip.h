#pragma once
#include<vector>
#include<string>

#include"Check.h"

enum class chooseVector
{
	Participant, Spend, MaxChoose
};

class Participant;
class Spend;

class Trip
{
public:
	void addParticipant(const std::string name);
	void addSpend(const std::string name, const double sum);
	void addToVector(const chooseVector current);
	void deleteParticipant(const int number);
	void deleteSpend(const int number);
	//distributePersonToSpend();
	//resetPersonOfSpend();
//private:
	std::vector<Participant>participants;
	std::vector<Spend>spends;
};