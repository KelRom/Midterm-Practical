#include <iostream>

void DisplayRandomQuestion(const char* questionList[], int numOfQuestions, const char* answerList[][4]);

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

	DisplayRandomQuestion(questions, 4, answers);
	system("pause");
}

void DisplayRandomQuestion(const char* questionList[], int numOfQuestions, const char* answerList[][4])
{

	//this will getting the number of questions from the array. dividing by size of void* because it is dependent on if running in 64 or 32 bit.
	int randomIndex = rand() % numOfQuestions;
	std::cout << questionList[randomIndex] << std::endl << std::endl;
	for (int i = 0; i < sizeof(answerList[randomIndex]) / 8; i++)
	{
		std::cout << answerList[randomIndex][i] << std::endl;
	}
}
