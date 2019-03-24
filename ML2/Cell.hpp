#pragma once
#include <vector>

class Cell
{
public:
	virtual double GetValue();
protected:
	std::vector<Cell *> m_inputCells;
	double(*m_GroupingFunction)(std::vector<double>);
	double(*m_ActivationFunction)(double);
};