#pragma once
#include <vector>
#include <string>
#include <iostream>

class Controller
{
public:

	Controller(int dim);
	int insertDataPlayer1(int y, int x);
	int insertDataPlayer2(int y, int x);
	std::vector<std::vector<int>> getScores();
	int checkVictory(); // Return 1 if player 1 won, 2 if player 2 won, -1 for a draw, 0 otherwise

private:
	int insertData(int y, int x, int value); // value = 1 for Player 1, -1 for Player 2
	int dimension;
	std::vector<std::vector<int>> scores; // Store 1 for player 1, -1 for player 2
};

