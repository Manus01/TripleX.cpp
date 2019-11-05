// TripleX.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	//print welcome messages to the terminal
	std::cout << "\n\nWelcome, please follow the instructions to start hacking level " << Difficulty;
	std::cout << "\nEnter the correct code to continue\n\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	//declare 3 number code
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProd = CodeA * CodeB * CodeC;

	//print code sum and prod to the terminal
	std::cout << std::endl;
	std::cout << "+There are 3 numbers in the code";
	std::cout << "\n+These 3 numbers add-up to: " << CodeSum;
	std::cout << "\n+If you multiply these 3 numbers: " << CodeProd;

	//store players guess
	int GuessA, GuessB, GuessC;

	//extract player guess
	std::cout << "\nEnter your guess... " << std::endl;
	std::cin >> GuessA >> GuessB >> GuessC;

	//calculate players' guess sum & prod
	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	//check if CodeSum = GuessSum and if CodeProd = GuessProduct
	if (CodeSum == GuessSum && CodeProd == GuessProduct)
	{
		std::cout << "Congratulations you have hacked level " << Difficulty;
		std::cout << std::endl;
		return true;
	}
	else {
		std::cout << "Oops wrong answer...try again level" << Difficulty;
		std::cout << std::endl;
		return false;
	}
}

int main()
{	
	srand(time(NULL)); //create new random sequence based on the time of day

	int LevelDifficulty = 1;
	const int MaxLevelDifficulty = 5;

	while (LevelDifficulty <= MaxLevelDifficulty) //loop game until all levels are completed
	{

		bool blevelcomplete = PlayGame(LevelDifficulty);
		std::cin.clear(); //clears any error
		std::cin.ignore();//discards the buffer

		if (blevelcomplete)
		{
			//todo increase the level difficulty
			++LevelDifficulty;
		}
	}

	std::cout << "\n **** You are a master hacker! ****" << std::endl;

	return 0;
}
