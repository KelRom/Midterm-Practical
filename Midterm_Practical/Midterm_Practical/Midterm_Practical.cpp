#include <iostream>
#include "Helper.h"

bool isCorrect(int questionsIndex, int userSelection);

int main()
{
	srand((unsigned int)time(NULL));
	const char* questions[] = { "What is the biggest state in the United States? ", 
								"Who painted the 'Mona Lisa' ? ", 
								"How many states border the Gulf of Mexico ?", 
								"What is the point of maximum distance in an orbit called?  " };
	
	const char* answers[][4] = { {"1. California", "2. Alaska", "3. Texas", "4. Montana"},
								 {"1. Leonardo DiCaprio", "2. Giovanna Garzoni", "3. Pablo Picasso", "4. Leonardo Da Vinci"},
								 {"1.   5", "2.   4", "3.   2", "4.   3"},
								 {"1. Oasis", "2. Periapsis", "3. Apoapsis", "4. Perigee"} };
	bool keepGoing = true;
	while (keepGoing)
	{
		int questionIndex = ConsoleHelper::DisplayRandomQuestion(questions, 4, answers);
		int userSelection = ConsoleHelper::ReadAndValidateInput("Choose an answer 1-4: ", 1, 4);
		bool isUserCorrect = isCorrect(questionIndex, userSelection);

		if (isUserCorrect)
			std::cout << "Good job! You got the answer right.";
		else
			std::cout << "I am sorry but that is not the correct answer.";

		int continueOrNot = ConsoleHelper::ReadAndValidateInput(" Press 1 to continue, Press 2 to quit: ", 1, 2);
		if (continueOrNot == 1)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	
	std::cout << "Thank you please come again! \n";
	system("pause");
}


bool isCorrect(int questionsIndex, int userSelection)
{
	bool correctOrNot = false;
	//all the condition in which the user is right
	if ((questionsIndex == 0 && userSelection == 2) ||
		(questionsIndex == 1 && userSelection == 4) ||
		(questionsIndex == 2 && userSelection == 1) ||
		(questionsIndex == 3 && userSelection == 3))
	{
		correctOrNot = true;
	}

	return correctOrNot;

}
