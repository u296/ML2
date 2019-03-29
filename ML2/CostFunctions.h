#pragma once
#include <vector>

namespace ML2
{
	namespace CostFunctions
	{
		double MeanSquaredError(std::vector<double> realOutput, std::vector<double> expectedOutput);
		double MeanSquaredError(double realOutput, double expectedOutput);
	}
}