#pragma once

#include "Cell.hpp"

class HiddenCell : public Cell
{
public:
	HiddenCell(double(*GroupingFunction)(std::vector<double>), double(*ActivationFunction)(double), std::vector<Cell *> inputCells);
};