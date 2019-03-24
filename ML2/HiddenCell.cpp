#include "HiddenCell.hpp"

HiddenCell::HiddenCell(double(*GroupingFunction)(std::vector<double>), double(*ActivationFunction)(double), std::vector<Cell*> inputCells)
{
	m_GroupingFunction = GroupingFunction;
	m_ActivationFunction = ActivationFunction;
	m_inputCells = inputCells;
}
