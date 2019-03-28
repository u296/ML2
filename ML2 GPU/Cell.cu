#include <numeric>
#include "Cell.cuh"

namespace ML2
{
	namespace Bases
	{
		double Cell::GetValue()	// Could be parallellized
		{
			std::vector<double> inputValues;

			inputValues.reserve(m_inputCells.size());

			for (int i = 0; i < m_inputCells.size(); i++)
				inputValues.emplace_back(m_inputCells[i]->GetValue() * m_weights[i]);

			double sum = 0;

			for (const auto & e : inputValues)
				sum += e;

			return m_activationFunction(sum);
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