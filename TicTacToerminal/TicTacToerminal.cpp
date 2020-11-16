// TicTacToerminal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Visualizer.h"
#include "Controller.h"

int main()
{
    std::cout << "Hello Tic-Tac-Toe players!\n";
	std::cout << "Decide who's player 1 and player 2, and enter n, the size of the grid\n" 
		      << "(for instance, enter 3 for a 3x3 grid)\n\n";
	
	int dim;

	std::cin >> dim;

	while (dim < 0 || dim > 6) {
		std::cout << "Please limit your grid size to 6x6, and enter a valid n.";
		std::cin >> dim;
	}

	Controller controller(dim);
	Visualizer viz(dim);
	std::vector<std::vector<char>> testElems = { {'x', 'o', 'x' }, 
												 {'o', 'x', 'o'}, 
												 {'o', 'o', 'o'} };

	int exitCondition = 0;
	int currentPlayer = 1;

	std::cout << "\nConvention: \n"
		<< "(0,0)-----> X \n"
		<< "| \n"
		<< "| \n"
		<< "| \n"
		<< "\\/ Y \n\n";

	while (!exitCondition) {

		std::cout << "\nCurrent state of the grid \n"
			      << "========================= \n";
		viz.render();

		std::cout << "Player " << currentPlayer << ": Enter location on grid.\n"
			<< "Format: Ycoordinate Xcoordinate \n";
		
		int valueY, valueX;
		
		std::cin >> valueY >> valueX;
		if (std::cin.fail())
		{
			std::cout << "Please enter valid integers only.\n";
		}
		//data type validation
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cin >> valueY >> valueX;
		}
		
		// validate and enter input
		int returnVal = (currentPlayer == 1) ? controller.insertDataPlayer1(valueY, valueX) :
			controller.insertDataPlayer2(valueY, valueX);

		// invalid input
		if (returnVal) {
			continue;
		}

		viz.updateData(controller.getScores());

		exitCondition = controller.checkVictory();
		
		if (exitCondition) {
			
			std::cout << "\nFinal state of the grid \n"
				      << "========================\n";

			viz.render();

			if (exitCondition == -1) {
				std::cout << "\n!!!!!!! IT'S A DRAW. PLAY A NEW GAME !!!!!!\n";
			}
			else {
				std::cout << "\nPLAYER " << exitCondition << " WON. CONGRATULATIONS!\n";
			}
		}
		else {
			currentPlayer = (currentPlayer == 1) ? 2 : 1;
		}
	}

	std::cout << "Press any key + Return to exit...\n";
	char c;
	std::cin >> c;
};

