#pragma once

#include "Cell.cuh"
namespace ML2
{
	namespace Cells
	{
		class OutputCell : public ML2::Bases::Cell
		{
		public:
			OutputCell(std::vector<ML2::Bases::Cell *> inputCells, std::vector<double> inputWeights, double(*ActivationFunction)(double));
		};
	}
}