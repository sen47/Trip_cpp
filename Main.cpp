#include<iostream>
#include<string>
#include<vector>
#include<functional>
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
	Exit, New, Next
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
	

	return 0;
}

int baseMenu(const char* whatAdd, const chooseVector current, const Trip& trip)
{
	int answer;
	do
	{
		std::cout << "Enter \" 1 \" to add new " << whatAdd
			<< "\nEnter \" 2 \" to go to next menu"
			<< "\nEnter \" 0 \" to exit";
		
		trip.showVector(current);
		
		answer = Check::inputCheck<int>(); //checking input value, for match data type

		system("cls");

		if (answer < 0 || answer>2) //checking input value, for possible value
			std::cout << "Try again\n";

	} while (answer < 0 || answer > 2);
	
	return answer;
}