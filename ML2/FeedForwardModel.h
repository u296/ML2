#pragma once

#include "Model.h"

namespace ML2
{
	namespace Models
	{
		class FeedForwardModel : public ML2::Bases::Model
		{
		public:
			FeedForwardModel(std::vector<double *> inputVariables, std::vector<int> modelShape, std::vector<ML2::Bases::ActivationFunction *> activationFunctions);
			// Inherit destructor

		protected:
			virtual void Initialize(std::vector<double *> inputVariables, std::vector<int> modelShape, std::vector<ML2::Bases::ActivationFunction *> activationFunctions) override;
		};
	}
}