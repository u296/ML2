#pragma once

#include <vector>

#include "Cell.cuh"

namespace ML2
{
	namespace Bases
	{
		class Model
		{
		public:
			Model();
			virtual ~Model();

			virtual std::vector<double> Evaluate();
		protected:
			friend class Trainer;

			std::vector<ML2::Bases::Cell *> m_inputLayer;
			std::vector<std::vector<ML2::Bases::Cell *>> m_hiddenLayers;
			std::vector<ML2::Bases::Cell *> m_outputLayer;

			virtual void Initialize(std::vector<double *> inputVariables, std::vector<int> modelShape, std::vector<double(*)(double)> activationFunctions);
		};
	}
}