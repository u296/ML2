#include "Cell.h"

namespace ML2
{
	namespace Cells
	{
		double Cell::GetValue()
		{
			std::vector<double> InputValues;

			InputValues.reserve(m_inputCells.size());

			for (int i = 0; i < m_inputCells.size(); i++)
				InputValues.emplace_back(m_inputCells[i]->GetValue() * m_inputWeights[i]);

			return m_ActivationFunction(m_GroupingFunction(InputValues)) * m_outputWeight;
		}

		std::vector<double> & Cell::GetInputWeights()
		{
			return m_inputWeights;
		}

		double & Cell::GetOutputWeight()
		{
			return m_outputWeight;
		}

		Cell::~Cell()
		{

		}
	}
}