#include "Controller.h"


int Controller::insertDataPlayer1(int y, int x) {

	return this->insertData(y, x, 1);
}

int Controller::insertDataPlayer2(int y, int x) {

	return this->insertData(y, x, -1);
}

// Not the safest way to return a vector ref.
std::vector<std::vector<int>> Controller::getScores() {
	return this->scores;
}

int Controller::insertData(int y, int x, int value) {

	// First validate input
	if (y > this->dimension - 1 || x > this->dimension - 1 || y < 0 || x < 0) {
		std::cout << "\n!!!!! Please try again. Incorrect grid entry. !!!!!\n\n";
		return -1;
	}

	if (this->scores[y][x] != 0) {
		std::cout << "\n!!!!!! There's already an element there. Try another location! !!!!\n\n";
		return -1;
	}

	this->scores[y][x] = value;

	return 0;
}

int Controller::checkVictory(){
	
	int sumX = 0;
	int sumY = 0;
	int sumDiag1 = 0; // for each of the diagonals 
	int sumDiag2 = 0;
	int mult = 1; // to check if all elements are filled

	for (int i = 0; i < this->dimension; i++) {

		sumX = 0;
		sumY = 0;
		sumDiag1 += this->scores[i][i];

		int xcoordDiag = this->dimension - 1 - i;
		sumDiag2 += this->scores[i][xcoordDiag];

		auto row = this->scores[i];

		for (int j = 0; j < this->dimension; j++) {
			
			sumX += row[j];
			sumY += this->scores[j][i];

			// will be zero if any space is unfilled
			mult = mult * this->scores[j][i];
		}

		if (sumX == dimension || sumY == dimension || sumDiag1 == dimension || sumDiag2 == dimension) {
			return 1;
		}

		if (sumX == -dimension || sumY == -dimension || sumDiag1 == -dimension || sumDiag2 == -dimension) {
			return 2;
		}
	}

	if (mult) {
		return -1; // the game resulted in a draw!
	}

	return 0;
}

Controller::Controller(int dim) { 
	this->dimension = dim;

	for (int i = 0; i < dim; i++) {
		std::vector<int> vec(dim, 0); // initialize
		this->scores.push_back(vec);
	}
}
