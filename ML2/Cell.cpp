#include "Cell.h"

double ML2::Cells::Cell::GetValue()
{
	std::vector<double> InputValues;
	for (int i = 0; i < m_inputCells.size(); i++)
		InputValues.push_back(m_inputCells[i]->GetValue() * m_inputWeights[i]);

	return m_ActivationFunction(m_GroupingFunction(InputValues)) * m_outputWeight;
}

std::vector<double> & ML2::Cells::Cell::GetInputWeights()
{
	return m_inputWeights;
}

double & ML2::Cells::Cell::GetOutputWeight()
{
	return m_outputWeight;
}

ML2::Cells::Cell::~Cell()
{
	
}
