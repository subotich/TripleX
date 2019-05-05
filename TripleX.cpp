// TripleX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>

int randomise()
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, 9);

	return dis(gen);
}

void PrintIntroduction(int Difficulty)
{
	std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
	std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	// Generate Code
	const int CodeA = randomise() % Difficulty + Difficulty;
	const int CodeB = randomise() % Difficulty + Difficulty;
	const int CodeC = randomise() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	// Print CodeSum and CodeProduct to the terminal
	std::cout << "+ There are 3 numbers in the code";
	std::cout << "\n+ The codes add-up to: " << CodeSum;
	std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

	// Store player guess
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	// Check if the players guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
		return true;
	}
	else
	{
		std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
		return false;
	}
}

int main()
{
	int LevelDifficulty = 3;
	int const MaxDifficulty = 7;

	while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // Clears any errors
		std::cin.ignore(); // Discards the buffer

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}
	std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
