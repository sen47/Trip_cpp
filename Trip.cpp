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

void Trip::addToVector(const chooseVector current)
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

void Trip::deleteParticipant(const int number)
{
}

void Trip::deleteSpend(const int number)
{
}
