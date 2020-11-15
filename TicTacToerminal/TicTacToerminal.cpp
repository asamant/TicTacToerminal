// TicTacToerminal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Visualizer.h"

int main()
{
    std::cout << "Hello World!\n";

	Visualizer viz(3);
	std::vector<std::vector<char>> testElems = { {'x', 'o', 'x' }, 
												 {'o', 'x', 'o'}, 
												 {'o', 'o', 'o'} };

	viz.updateData(testElems);

	viz.render();
};

