#pragma once
#include <vector>
namespace ML2
{
	namespace Bases
	{
		class Cell
		{
		public:
			Cell();
			virtual ~Cell();

			virtual double GetOutput();
			virtual double GetOutputInput();
			virtual double & operator[](const int index);
			virtual std::vector<Cell *> & GetInputCells();
			virtual std::vector<double> & GetWeights();
			virtual double & GetBias();
			virtual double & GetError();
		protected:
			std::vector<Cell *> m_inputCells;
			std::vector<double> m_weights;
			double m_bias;
			double(*m_activationFunction)(double);
			double m_error;
		};
	}
}