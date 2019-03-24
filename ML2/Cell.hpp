#pragma once
#include <vector>

class Cell
{
public:
	virtual double GetValue();
private:
	std::vector<Cell *> InputCells;
	double(*ActivationFunction)(double);
};