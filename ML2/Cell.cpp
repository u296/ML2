#include <numeric>
#include "Cell.h"

namespace ML2
{
	namespace Bases
	{
		double Cell::GetValue()
		{
			std::vector<double> inputValues;

			inputValues.reserve(m_inputCells.size());

			for (int i = 0; i < m_inputCells.size(); i++)
				inputValues.emplace_back(m_inputCells[i]->GetValue() * m_weights[i]);

			double sum = 0;

			for (const auto & e : inputValues)
				sum += e;

			return m_ActivationFunction(sum);
		}

		double & Cell::operator[](const int index)
		{
			return m_weights[index];
		}

		Cell::Cell()
		{
		}

		Cell::~Cell()
		{

		}
	}
}