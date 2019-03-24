#include "Cell.h"

double ML2::Cells::Cell::GetValue()
{
	std::vector<double> InputValues;
	for (int i = 0; i < m_inputCells.size(); i++)
		InputValues.push_back(m_inputCells[i]->GetValue() * m_inputWeights[i]);

	return m_ActivationFunction(m_GroupingFunction(InputValues)) * m_outputWeight;
}

ML2::Cells::Cell::~Cell()
{
	for (int i = 0; i < m_inputCells.size(); i++)
	{
		delete m_inputCells[i];
	}
}
