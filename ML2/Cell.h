#pragma once
#include <vector>
namespace ML2
{
	namespace Cells
	{
		class Cell
		{
		public:
			~Cell();

			virtual double GetValue();
			virtual std::vector<double> & GetInputWeights();
			virtual double & GetOutputWeight();
		protected:
			std::vector<Cell *> m_inputCells;
			std::vector<double> m_inputWeights;

			double(*m_GroupingFunction)(std::vector<double>);
			double(*m_ActivationFunction)(double);
			double m_outputWeight;
		};
	}
}