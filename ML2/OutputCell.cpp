#include "OutputCell.h"

ML2::Cells::OutputCell::OutputCell(std::vector<Cell*> inputCells, std::vector<double> inputWeights, double outputWeight, double(*GroupingFunction)(std::vector<double>), double(*ActivationFunction)(double))
{
	m_inputCells = inputCells;
	m_inputWeights = inputWeights;
	m_outputWeight = outputWeight;
	m_GroupingFunction = GroupingFunction;
	m_ActivationFunction = ActivationFunction;
}

ML2::Cells::OutputCell::~OutputCell()
{
	for (int i = 0; i < m_inputCells.size(); i++)
	{
		delete m_inputCells[i];
	}
}
