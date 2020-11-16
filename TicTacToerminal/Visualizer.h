#pragma once
#include <vector>

class Visualizer
{
public:
	void updateData(std::vector<std::vector<int>>);
	void render();
	Visualizer(int dim);

private:
	int dimension;
	std::vector<std::vector<char>> currentData; // to store players' inputs
	std::vector<std::vector<char>> gridElements; // backing fields for displaying data on terminal
};

