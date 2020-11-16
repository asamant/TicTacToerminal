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
		<< "(0,0) \n"
		<< "|-----> X \n"
		<< "| \n"
		<< "| \n"
		<< "\\/ Y \n\n";

	while (!exitCondition) {

		std::cout << "Current state of the grid: \n";
		viz.render();

		std::cout << "Player " << currentPlayer << ": Enter location on grid.\n"
			<< "Y coordinate: ";
		
		int valueY, valueX;
		
		std::cin >> valueY;
		std::cout << "X coordinate: ";
		std::cin >> valueX;

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
			std::cout << "Player " << exitCondition << " won. Congratulations!";

			viz.render();
		}
		else {
			currentPlayer = (currentPlayer == 1) ? 2 : 1;
		}
	}
};

