#pragma once

#include "Cell.h"
namespace ML2
{
	namespace Cells
	{
		class HiddenCell : public ML2::Cells::Cell
		{
		public:
			HiddenCell(std::vector<Cell *> inputCells, std::vector<double> inputWeights, double outputWeight, double(*GroupingFunction)(std::vector<double>), double(*ActivationFunction)(double));
		};
	}
}