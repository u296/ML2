#pragma once

#include "Cell.cuh"
namespace ML2
{
	namespace Cells
	{
		class HiddenCell : public ML2::Bases::Cell
		{
		public:
			HiddenCell(std::vector<ML2::Bases::Cell *> inputCells, std::vector<double> weights, double(*activationFunction)(double));
		};
	}
}
