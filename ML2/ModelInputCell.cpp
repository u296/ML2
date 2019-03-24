#include "ModelInputCell.hpp"

ModelInputCell::ModelInputCell(double(*GroupingFunction)(std::vector<double>), double(*ActivationFunction)(double), double * inputVariable)
{
	m_GroupingFunction = GroupingFunction;
	m_ActivationFunction = ActivationFunction;
	m_inputVariable = inputVariable;
}

double ModelInputCell::GetValue()
{
	return m_ActivationFunction(m_GroupingFunction({ *m_inputVariable }));
}
