#include "Cell.hpp"

double Cell::GetValue()
{
	std::vector<double> InputValues;
	for (const auto & InputCell : m_inputCells)
		InputValues.push_back(InputCell->GetValue());

	return m_ActivationFunction(m_GroupingFunction(InputValues));
}
