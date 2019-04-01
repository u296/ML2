#pragma once

#include <vector>

#include "Cell.h"

namespace ML2
{
	namespace Trainers
	{
		class BackpropagationTrainer;
	}

	namespace Bases
	{
		class Model
		{
		public:
			Model();
			virtual ~Model();

			virtual void SetInputVariables(std::vector<double *> inputVariables);
			virtual std::vector<double> Evaluate();
		protected:
			friend class ML2::Trainers::BackpropagationTrainer;

			std::vector<ML2::Bases::Cell *> m_inputLayer;
			std::vector<std::vector<ML2::Bases::Cell *>> m_hiddenLayers;
			std::vector<ML2::Bases::Cell *> m_outputLayer;

			virtual void Initialize(std::vector<double *> inputVariables, std::vector<int> modelShape, std::vector<ML2::Bases::ActivationFunction *> activationFunctions);
		};
	}
}