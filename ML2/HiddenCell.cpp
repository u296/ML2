#include "HiddenCell.h"

namespace ML2
{
	namespace Cells
	{
		ML2::Cells::HiddenCell::HiddenCell(std::vector<ML2::Bases::Cell *> inputCells, std::vector<double> weights, double bias, ML2::Bases::ActivationFunction * activationFunction)
		{
			m_inputCells			= inputCells;
			m_weights				= weights;
			m_bias					= bias;
			m_activationFunction	= activationFunction;
		}
	}
}
