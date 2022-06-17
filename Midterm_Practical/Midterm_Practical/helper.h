#pragma once
#include <iostream>

namespace ConsoleHelper
{
	void resetConsoleBuffer()
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
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

	int DisplayRandomQuestion(const char* questionList[], int numOfQuestions, const char* answerList[][4])
	{
		int randomIndex = rand() % numOfQuestions;
		std::cout << questionList[randomIndex] << std::endl << std::endl;
		for (int i = 0; i < sizeof(answerList[randomIndex]) / 8; i++)
		{
			std::cout << answerList[randomIndex][i] << std::endl;
		}

		return randomIndex;
	}

}
