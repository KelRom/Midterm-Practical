#include <iostream>

int DisplayRandomQuestion(const char* questionList[], int numOfQuestions, const char* answerList[][4]);
int ReadAndValidateInput(const char* message, int minSelection, int maxSelection);
void resetConsoleBuffer();
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
		int questionIndex = DisplayRandomQuestion(questions, 4, answers);
		int userSelection = ReadAndValidateInput("Choose an answer 1-4: ", 1, 4);
		bool isUserCorrect = isCorrect(questionIndex, userSelection);

		if (isUserCorrect)
			std::cout << "Good job! You got the answer right.";
		else
			std::cout << "I am sorry but that is not the correct answer.";

		int continueOrNot = ReadAndValidateInput(" Press 1 to continue, Press 2 to quit: ", 1, 2);
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

//will return a number to be able to see later what question was used.
int DisplayRandomQuestion(const char* questionList[], int numOfQuestions, const char* answerList[][4])
{

	//this will getting the number of questions from the array. dividing by size of void* because it is dependent on if running in 64 or 32 bit.
	int randomIndex = rand() % numOfQuestions;
	std::cout << questionList[randomIndex] << std::endl << std::endl;
	for (int i = 0; i < sizeof(answerList[randomIndex]) / 8; i++)
	{
		std::cout << answerList[randomIndex][i] << std::endl;
	}

	return randomIndex;
}

int ReadAndValidateInput(const char* message, int minSelection, int maxSelection)
{
	int answerSelection = 0;

	while (true)
	{
		std::cout << message;
		std::cin >> answerSelection;
		if (std::cin.fail() || (answerSelection < minSelection || answerSelection > maxSelection))
		{
			resetConsoleBuffer();
			std::cout << "\nYour input was not valid" << std::endl;
		}
			
		else
			break;
	}

	resetConsoleBuffer();
	return answerSelection;
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
void resetConsoleBuffer()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}