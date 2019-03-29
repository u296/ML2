#include <numeric>
#include "Cell.h"

namespace ML2
{
	namespace Bases
	{
		double Cell::GetOutput()
		{
			return m_activationFunction(GetOutputInput());
		}

		double Cell::GetOutputInput()
		{
			double sum = 0;

			for (int i = 0; i < m_inputCells.size(); i++)
				sum += m_inputCells[i]->GetOutput() * m_weights[i];

			return sum + m_bias;
		}

		double & Cell::operator[](const int index)
		{
			return m_weights[index];
		}

		std::vector<Cell*>& Cell::GetInputCells()
		{
			return m_inputCells;
		}

		std::vector<double>& Cell::GetWeights()
		{
			return m_weights;
		}

		double & Cell::GetBias()
		{
			return m_bias;
		}

		double & Cell::GetError()
		{
			return m_error;
		}

		Cell::Cell()
		{
		}

		Cell::~Cell()
		{

		}
	}
}