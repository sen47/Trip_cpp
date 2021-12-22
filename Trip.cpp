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

//////////////////////////////////////////////////////////
//public
void Trip::addToVector(const chooseVector& current) //choose in what vector will add
{
	std::string name = "";
	double sum = 0;
	int temp = 0;
	//std::cout << "0 - to go back\n";
	switch (current)
	{
	case chooseVector::Participant:

		name = Check<std::string>::inputCheck("Enter participant name");
		system("cls");
		/*if (!std::stoi(name)) //don't work exit of adding
			return;*/
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

////////////////////////////////////////////////////////////////////
void Trip::distributePersonToSpend()
{
	for (auto& el_sp : spends)
	{
		int index = 0;
		do
		{
			std::cout << "0 - to next\n";
			std::cout << "Choose participants of " << el_sp.getSpendName();
			int count = 0;

			for (auto& el_pt : participants)
			{
				++count;
				if (el_sp.isInParticipants(&el_pt))
					continue;
				std::cout << '\n' << count << " - " << el_pt.getParticipantName() << std::endl;
			}

			index = (Check<int>::inputCheck());
			if (index > 0 && index <= participants.size())
			{
				if (!participants[index - 1].addSpend(&el_sp)) //if add return 0, if not return 1
					el_sp.addParticipant(&participants[index - 1]);
			}
			system("cls");
		} while (index != 0);
	}
}

void Trip::showPersonAndTheirSpend()
{
	for (auto el : participants)
	{
		std::cout << "\n\n" << el.getParticipantName() << ":\n";
		el.showSpend();
	}
}
