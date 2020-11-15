#pragma once
#include <vector>

class Visualizer
{
public:
	int dimension;

	void updateData(std::vector<std::vector<char>>);
	void render();
	Visualizer(int dim);

private:
	std::vector<std::vector<char>> currentData; // to store players' inputs
	std::vector<std::vector<char>> gridElements; // backing fields for displaying data on terminal
	void updateVisualElements();
};

