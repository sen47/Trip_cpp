#include "Trip.h"
#include"Participant.h"
#include"Spend.h"

void Trip::addParticipant(const std::string name)
{
	participants.emplace_back(name);
}

void Trip::addSpend(const std::string name, const double sum)
{
	spends.emplace_back(name, sum);
}

const char* Trip::getVectorName(chooseVector current) const
{
	switch (current)
	{
	case chooseVector::Participant:
		return Participant::getClassName();
		break;
	case chooseVector::Spend:
		return Spend::getClassName();
		break;
	}
}

void Trip::addToVector(const chooseVector current) //choose in what vector will add
{
	std::string name = "";
	double sum = 0;
	switch (current)
	{
	case chooseVector::Participant:

		name = Check::inputCheck<std::string>("Enter participant name");
		system("cls");
		addParticipant(name);
		break;

	case chooseVector::Spend:

		name = Check::inputCheck<std::string>("Enter name of spend");
		sum = Check::inputCheck<double>("\nEnter spend sum");
		system("cls");
		addSpend(name, sum);
		break;
	}
}

void Trip::showVector(const chooseVector current) const
{
	switch (current)
	{
	case chooseVector::Participant:
		showParticipants();
		break;
	case chooseVector::Spend:
		showSpends();
		break;
	}
}

void Trip::showParticipants() const
{
	if (!participants.size())
		return;
	std::cout << "\n\nParticipants:\n";
	for (const auto& el : participants)
		std::cout << el << std::endl;
}

void Trip::showSpends() const
{
	if (!spends.size())
		return;
	std::cout << "\n\nSpends:\n";
	for (const auto& el : spends)
		std::cout << el << std::endl;
}

void Trip::deleteParticipant(const int number)
{
	if (!number || number > participants.size())
		throw("Try delete zero element or participants size is less");
	auto el = participants.begin();
	for (int i = 1; i < number; ++i, ++el)
		;
	participants.erase(el);
}

void Trip::deleteSpend(const int number)
{
	if (!number || number > spends.size())
		throw("Try delete zero element or spends size is less");
	auto el = spends.begin();
	for (int i = 1; i < number; ++i, ++el)
		;
	spends.erase(el);
}
