#include<iostream>
#include<string>
#include<vector>

#include"Participant.h"
#include"Spend.h"
#include"Check.h"

enum uAnswer
{
	Exit, New, Next
};

int addMenu(const char* whatAdd);

int main()
{
	std::vector<Participant>participants;
	
	std::cout << addMenu(Participant::getClassName());
	
	/*participants.emplace_back(Check::inputCheck<std::string>("Enter name"));
	std::cout << participants[0] << std::endl;*/

	return 0;
}

int addMenu(const char* whatAdd)
{
	int answer;
	do
	{
		std::cout << "Enter \" 1 \" to add new " << whatAdd
			<< "\nEnter \" 2 \" to go to next menu"
			<< "\nEnter \" 0 \" to exit";
		answer = Check::inputCheck<int>();

		system("cls");

		if (answer < 0 || answer>2)
			std::cout << "Try again!\n";

	} while (answer < 0 || answer > 2);
	
	return answer;
}