#pragma once
#include <vector>
#include "ActivationFunctions.h"
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
			virtual ML2::Bases::ActivationFunction * GetActivationFunction();
		protected:
			std::vector<Cell *> m_inputCells;
			std::vector<double> m_weights;
			double m_bias;
			ML2::Bases::ActivationFunction * m_activationFunction;
			double m_error;
		};
	}
}