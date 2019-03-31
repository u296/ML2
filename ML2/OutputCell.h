#pragma once

#include "Cell.h"
namespace ML2
{
	namespace Cells
	{
		class OutputCell : public ML2::Bases::Cell
		{
		public:
			OutputCell(std::vector<ML2::Bases::Cell *> inputCells, std::vector<double> weights, double bias, ML2::Bases::ActivationFunction * activationFunction);
		};
	}
}