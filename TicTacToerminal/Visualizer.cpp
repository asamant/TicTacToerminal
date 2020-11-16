#include "Visualizer.h"
#include <vector>
#include <iostream>

/*
Update the backing fields with the appropriate data;
*/
void Visualizer::updateData(std::vector<std::vector<int>> dataToRender) {

	// Assumption: dimension is defined when the Visualizer object is created.
	for (int i = 0; i < this->dimension; i++) {
		for (int j = 0; j < this->dimension; j++) {
			this->currentData[i][j] = (dataToRender[i][j] == 1) ? 'x' :
				(dataToRender[i][j] == -1) ? 'o' : ' ';
		}
	}
}

/*
Print the grid and user values on the terminal
*/
void Visualizer::render() {

	std::cout << std::endl;

	// for every (y, x) in data field, fill (2y + 1, 4x + 2) in the graphics field
	for (int i = 0; i < this->dimension; i++) {
		for (int j = 0; j < this->dimension; j++) {
			gridElements[2 * i + 1][4 * j + 2] = this->currentData[i][j];
		}
	}
	
	// for every 2nth Y element, fill X vector with '-'
	// for every 4nth X element, fill Y vector with '|'
	
	for (int i = 0; i < this->gridElements.size(); i++) {
		std::vector<char> currentRow = this->gridElements[i];
		
		for (int j = 0; j < currentRow.size(); j++) {
			if (i % 2 == 0) {
				gridElements[i][j] = '-';
			}
			if (j % 4 == 0) {
				gridElements[i][j] = '|';
			}

			// Do the terminal printing
			std::cout << gridElements[i][j];
		}

		// New row
		std::cout << std::endl;
	}
}

Visualizer::Visualizer(int dim) { 
	this->dimension = dim;

	// initialize data for players as unfilled spaces
	for (int i = 0; i < dim; i++) {
		std::vector<char> vec;
		for (int j = 0; j < dim; j++) {
			vec.push_back(' ');
		}

		this->currentData.push_back(vec);
	}

	// Graphics part
	auto graphicsDimX = 4 * dim + 1; // for rendering on the terminal
	auto graphicsDimY = 2 * dim + 1;
	/*

	--------- - - - --> X
	| x | o |
	|---|---| - - -  
	|   | x | 
	|---|---| - - -
	|
	Y

	*/

	// add initial placeholders for visual grid
	for (int i = 0; i < graphicsDimY; i++) {
		std::vector<char> vec;
		for (int j = 0; j < graphicsDimX; j++) {
			vec.push_back(' ');
		}

		this->gridElements.push_back(vec);
	}
}

