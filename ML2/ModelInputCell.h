#pragma once

#include "Cell.h"

namespace ML2
{
	namespace Cells
	{
		class ModelInputCell : public ML2::Cells::Cell
		{
		public:
			ModelInputCell(double * inputVariable, double inputWeight, double outputWeight, double(*GroupingFunction)(std::vector<double>), double(*ActivationFunction)(double));
			ModelInputCell(double * inputVariable, std::vector<double> inputWeight, double outputWeight, double(*GroupingFunction)(std::vector<double>), double(*ActivationFunction)(double));
			~ModelInputCell();

			double GetValue() override;
		protected:
			double * m_inputVariable;
			double m_inputWeight;
		};
	}
}