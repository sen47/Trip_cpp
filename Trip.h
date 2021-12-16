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
protected:
	void addParticipant(const std::string name);
	void addSpend(const std::string name, const double sum);
	void showParticipants() const;
	void showSpends() const;
public:	
	const char* getVectorName(chooseVector current) const;
	void addToVector(const chooseVector current);
	void showVector(const chooseVector current) const;
	void deleteParticipant(const int number);
	void deleteSpend(const int number);
	void chooseToDelete(const chooseVector& current);
	//distributePersonToSpend();
	//resetPersonOfSpend();

//private:
	std::vector<Participant>participants;
	std::vector<Spend>spends;
};