#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<cassert>

#include"Participant.h"
#include"Spend.h"
#include"Check.h"
#define DEBUG
#ifdef DEBUG
#define NL std::cout<<std::endl;
#endif // DEBUG

enum uAnswer
{
	Exit, New, Next
};

enum class chooseVector
{
	Participant, Spend, MaxChoose
};

int baseMenu(const char* whatAdd);
void addParticipant(std::vector<Participant>& participants);
void addSpending(std::vector<Spend>& spends);
void addToVector(const chooseVector current, std::vector<Participant>&participants, std::vector<Spend>&spends);
const char* getVectorName(chooseVector current);

int main()
{	
	std::vector<Participant>participants;
	std::vector<Spend>spends;
	int answer=0;
	chooseVector currentVector{ chooseVector::Participant };
	while (currentVector<chooseVector::MaxChoose)
	{
		answer = baseMenu(getVectorName(currentVector));
		switch (answer)
		{
		case uAnswer::New:
			addToVector(currentVector, participants, spends);
			break;
		case uAnswer::Next:
		{
			int temp = static_cast<int>(currentVector);
			++temp;
			currentVector = static_cast<chooseVector>(temp);
			break;
		}
		case uAnswer::Exit:
			exit(0);
			break;
		}
	}
	
	for (auto el : participants)
		std::cout << el << std::endl;
	
	NL NL;

	for (auto el : spends)
		std::cout << el << std::endl;

	return 0;
}

int baseMenu(const char* whatAdd)
{
	int answer;
	do
	{
		std::cout << "Enter \" 1 \" to add new " << whatAdd
			<< "\nEnter \" 2 \" to go to next menu"
			<< "\nEnter \" 0 \" to exit";
		answer = Check::inputCheck<int>(); //checking input value, for match data type

		system("cls");

		if (answer < 0 || answer>2) //checking input value, for possible value
			std::cout << "Try again\n";

	} while (answer < 0 || answer > 2);
	
	return answer;
}

void addToVector(const chooseVector current, std::vector<Participant>& participants, std::vector<Spend>& spends)
{
	switch (current)
	{
	case chooseVector::Participant:
		addParticipant(participants);
		break;
	case chooseVector::Spend:
		addSpending(spends);
		break;
	}
}

const char* getVectorName(chooseVector current)
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

void addParticipant(std::vector<Participant>& participants)
{
	Participant temp;
	temp.setName();
	system("cls");
	participants.emplace_back(temp);
}

void addSpending(std::vector<Spend>& spends)
{
	Spend temp;
	temp.setName();
	temp.setSum();
	system("cls");
	spends.emplace_back(temp);
}