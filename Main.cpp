#include<iostream>
#include<string>
#include<vector>
//#include<functional>
#include<cassert>

#include"Participant.h"
#include"Spend.h"
#include"Check.h"
#include"Trip.h"
#define DEBUG
#ifdef DEBUG
#define NL std::cout<<std::endl;
#endif // DEBUG

enum uAnswer
{
	Exit, New, Delete, Next, Back, uAnswerMax
};

int baseMenu(const char* whatAdd, const chooseVector current, const Trip& trip);

int main()
{	
	Trip trip;
	int answer=0;
	chooseVector currentVector{ chooseVector::Participant };
	
	while (currentVector<chooseVector::MaxChoose)
	{
		answer = baseMenu(trip.getVectorName(currentVector), currentVector, trip);

		switch (answer)
		{
		case uAnswer::New:
			trip.addToVector(currentVector);
			break;
		case uAnswer::Delete:
			trip.chooseToDelete(currentVector);
			break;
		case uAnswer::Next:
		{
			int temp = static_cast<int>(currentVector);
			++temp;
			currentVector = static_cast<chooseVector>(temp);
			break;
		}
		case uAnswer::Back:
		{
			int temp = static_cast<int>(currentVector);
			--temp;
			if (temp < 0)
				break;
			currentVector = static_cast<chooseVector>(temp);
			break;
		}
		case uAnswer::Exit:
			exit(0);
			break;
		}
	}

	return 0;
}

int baseMenu(const char* whatAdd, const chooseVector current, const Trip& trip)
{
	int answer;
	do
	{
		std::cout << "Enter \" 1 \" to add new " << whatAdd
			<< "\nEnter \" 2 \" to delete element"
			<< "\nEnter \" 3 \" to go to next menu"
			<< "\nEnter \" 4 \" to go to previous menu"
			<< "\nEnter \" 0 \" to exit";
		
		trip.showVector(current);
		
		answer = Check<int>::inputCheck(); //checking input value, for match data type

		system("cls");

		if (answer < 0 || answer >= uAnswerMax) //checking input value, for possible value
			std::cout << "Try again\n";

	} while (answer < 0 || answer >= uAnswerMax);
	
	return answer;
}