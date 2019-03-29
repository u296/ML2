#include "OutputCell.h"

namespace ML2
{
	namespace Cells
	{
		OutputCell::OutputCell(std::vector<ML2::Bases::Cell *> inputCells, std::vector<double> weights, double bias, double(*activationFunction)(double))
		{
			m_inputCells			= inputCells;
			m_weights				= weights;
			m_bias					= bias;
			m_activationFunction	= activationFunction;
		}
	}
}