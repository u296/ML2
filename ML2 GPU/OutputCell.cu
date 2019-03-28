#include "OutputCell.cuh"

namespace ML2
{
	namespace Cells
	{
		OutputCell::OutputCell(std::vector<ML2::Bases::Cell *> inputCells, std::vector<double> weights, double(*activationFunction)(double))
		{
			m_inputCells = inputCells;
			m_weights = weights;
			m_activationFunction = activationFunction;
		}
	}
}