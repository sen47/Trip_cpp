#include "Trip.h"

//////////////////////////////////////////////////////////
//protected
void Trip::addParticipant(const std::string name)
{
	participants.emplace_back(name);
}

void Trip::addSpend(const std::string name, const double sum)
{
	spends.emplace_back(name, sum);
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

void Trip::showParticipants() const
{
	if (!participants.size())
		return;
	int i = 1;
	std::cout << "\n\nParticipants:\n";
	for (const auto& el : participants)
	{
		std::cout << i << " - " << el << std::endl;
		++i;
	}
}

void Trip::showSpends() const
{
	if (!spends.size())
		return;
	int i = 1;
	std::cout << "\n\nSpends:\n";
	for (const auto& el : spends)
	{
		std::cout << i << " - " << el << std::endl;
		++i;
	}
}

/////////////////////////////////////////////////////////
//public
void Trip::addToVector(const chooseVector& current) //choose in what vector will add
{
	std::string name = "";
	double sum = 0;
	switch (current)
	{
	case chooseVector::Participant:

		name = Check<std::string>::inputCheck("Enter participant name");
		system("cls");
		addParticipant(name);
		break;

	case chooseVector::Spend:

		name = Check<std::string>::inputCheck("Enter name of spend");
		sum = Check<double>::inputCheck("\nEnter spend sum");
		system("cls");
		addSpend(name, sum);
		break;
	default:
		throw("Try to add element in non-existant vector");
	}
}

void Trip::chooseToDelete(const chooseVector& current)
{
	int number = 0;
	std::cout << "0 - to go back";
	switch (current)
	{
	case chooseVector::Participant:
		if (!participants.size())
			break;
		showParticipants();
		number = Check<int>::inputCheck("Enter number need to delete");
		if (!number)
			break;
		deleteParticipant(number);
		break;
	case chooseVector::Spend:
		if (!spends.size())
			break;
		showSpends();
		number = Check<int>::inputCheck("Enter number need to delete");
		if (!number)
			break;
		deleteSpend(number);
		break;
	default:
		throw("Try to delete element of non-existant vector");
	}
	system("cls");
}

void Trip::showVector(const chooseVector& current) const
{
	switch (current)
	{
	case chooseVector::Participant:
		showParticipants();
		break;
	case chooseVector::Spend:
		showSpends();
		break;
	default:
		throw("Try to show non-existant vector");
	}
}

const char* Trip::getVectorName(const chooseVector& current) const
{
	switch (current)
	{
	case chooseVector::Participant:
		return Participant::getClassName();
		break;
	case chooseVector::Spend:
		return Spend::getClassName();
		break;
	default:
		throw("Try to get name non-existant vector");
	}
}