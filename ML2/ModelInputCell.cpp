#include "ModelInputCell.h"

ML2::Cells::ModelInputCell::ModelInputCell(double * inputVariable, std::vector<double> inputWeights, double outputWeight, double(*GroupingFunction)(std::vector<double>), double(*ActivationFunction)(double))
{
	m_inputVariable = inputVariable;
	m_inputWeights = inputWeights;
	m_outputWeight = outputWeight;
	m_GroupingFunction = GroupingFunction;
	m_ActivationFunction = ActivationFunction;
}

ML2::Cells::ModelInputCell::~ModelInputCell()
{

}

double ML2::Cells::ModelInputCell::GetValue()
{
	return m_ActivationFunction(m_GroupingFunction({ *m_inputVariable * m_inputWeights[0] })) * m_outputWeight;
}