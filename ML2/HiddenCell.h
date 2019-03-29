#pragma once

#include "Cell.h"
namespace ML2
{
	namespace Cells
	{
		class HiddenCell : public ML2::Bases::Cell
		{
		public:
			HiddenCell(std::vector<ML2::Bases::Cell *> inputCells, std::vector<double> weights, double bias, double(*activationFunction)(double));
		};
	}
}
