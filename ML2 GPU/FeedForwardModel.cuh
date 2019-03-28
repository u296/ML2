#pragma once

#include "Model.cuh"

namespace ML2
{
	namespace Models
	{
		class FeedForwardModel : public ML2::Bases::Model
		{
		public:
			FeedForwardModel(std::vector<double *> inputVariables, std::vector<int> modelShape, std::vector<double(*)(double)> activationFunctions);
			// Inherit destructor

		protected:
			virtual void Initialize(std::vector<double *> inputVariables, std::vector<int> modelShape, std::vector<double(*)(double)> activationFunctions) override;
		};
	}
}