#pragma once
#include <vector>
namespace ML2
{
	namespace Cells
	{
		class Cell
		{
		public:
			virtual double GetValue();
			~Cell();
		protected:
			std::vector<Cell *> m_inputCells;
			std::vector<double> m_inputWeights;

			double(*m_GroupingFunction)(std::vector<double>);
			double(*m_ActivationFunction)(double);
			double m_outputWeight;
		};
	}
}