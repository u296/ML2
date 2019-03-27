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

			virtual double GetValue();
			virtual double & operator[](const int index);
		protected:
			std::vector<Cell *> m_inputCells;
			std::vector<double> m_weights;
			double(*m_ActivationFunction)(double);
		};
	}
}