#pragma once
#include<vector>
#include<string>
#include<iostream>

#include"Check.h"
#include"Participant.h"
#include"Spend.h"

//#define DEBUG

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
	void deleteParticipant(const int number);
	void deleteSpend(const int number);
	void showParticipants() const;
	void showSpends() const;

public:	

	void addToVector(const chooseVector& current);
	void chooseToDelete(const chooseVector& current);
	void showVector(const chooseVector& current) const;
	const char* getVectorName(const chooseVector& current) const;
	
	//////////////////////////////////////////////////////////////
	void distributePersonToSpend();
	//resetPersonOfSpend();

	void showPersonAndTheirSpend();

//private:
	std::vector<Participant>participants
#ifdef DEBUG
	{ Participant{"Aleks"},Participant{"James"},Participant{"Katy"},Participant{"Viktor"},Participant{"Amily"},Participant{"Anna"} }
#endif // DEBUG
	;
	std::vector<Spend>spends
#ifdef DEBUG
	{ Spend{"Food",1000},Spend{"Drinks",2000},Spend{"Gas",3000} }
#endif // DEBUG
	;
};