#include <numeric>
#include "Cell.h"

namespace ML2
{
	namespace Bases
	{
		double Cell::GetOutput()	// Could be parallellized
		{
			return m_activationFunction(GetSumWeightedInputs());
		}

		double Cell::GetSumWeightedInputs()
		{
			double sum = 0;

			for (int i = 0; i < m_inputCells.size(); i++)
				sum += m_inputCells[i]->GetOutput() * m_weights[i];

			return sum;
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