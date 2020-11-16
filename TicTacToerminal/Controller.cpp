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
		std::cout << "Please try again. Incorrect grid entry.\n";
		return -1;
	}

	if (this->scores[y][x] != 0) {
		std::cout << "There's already an element there. Try another location! \n";
		return -1;
	}

	this->scores[y][x] = value;

	return 0;
}

int Controller::checkVictory(){
	
	int sumX = 0;
	int sumY = 0;
	int sumDiag = 0;

	for (int i = 0; i < this->dimension; i++) {

		sumX = 0;
		sumY = 0;
		sumDiag += scores[i][i];

		auto row = this->scores[i];

		for (int j = 0; j < this->dimension; j++) {
			sumX += row[j];
			sumY += this->scores[j][i];
		}

		if (sumX == dimension || sumX == -dimension || sumY == dimension || sumY == -dimension
			|| sumDiag == dimension || sumDiag == -dimension) {
			return (sumX == dimension || sumY == dimension || sumDiag == dimension) ? 1 : 2;
		}
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
