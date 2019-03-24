#include "HiddenCell.h"

ML2::Cells::HiddenCell::HiddenCell(std::vector<Cell*> inputCells, std::vector<double> inputWeights, double outputWeight, double(*GroupingFunction)(std::vector<double>), double(*ActivationFunction)(double))
{
	m_inputCells = inputCells;
	m_inputWeights = inputWeights;
	m_outputWeight = outputWeight;
	m_GroupingFunction = GroupingFunction;
	m_ActivationFunction = ActivationFunction;
}
