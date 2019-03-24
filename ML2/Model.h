#pragma once

#include <vector>

#include "Cell.h"

namespace ML2
{
	class Model
	{
	public:
	private:
		Model();
		Model();
	protected:
		void CreateModel(
			std::vector<int> modelSize,													// 2d map of model
			std::vector<std::vector<std::vector<double>>> inputWeights,					// inputweights for every cell
			std::vector<std::vector<double>> outputWeights,								// outputweight for every cell
			std::vector<std::vector<double(*)(std::vector<double>)>> groupingFunctions,	// grouping function for every cell
			std::vector<std::vector<double(*)(double)>> activationFunctions				// activation function for every cell
		);


	};
}