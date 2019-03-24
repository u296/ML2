#pragma once

#include "Cell.h"

namespace ML2
{
	namespace Cells
	{
		class ModelInputCell : public ML2::Cells::Cell
		{
		public:
			ModelInputCell(double * inputVariable, std::vector<double> inputWeights, double outputWeight, double(*GroupingFunction)(std::vector<double>), double(*ActivationFunction)(double));
			~ModelInputCell();

			virtual double GetValue() override;
		protected:
			double * m_inputVariable;
		};
	}
}