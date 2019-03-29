#include <cmath>
#include "CostFunctions.h"

namespace ML2
{
	namespace CostFunctions
	{

		double MeanSquaredError(std::vector<double> realOutput, std::vector<double> expectedOutput)
		{
			double cost = 0;

			for (int i = 0; i < realOutput.size(); i++)
				cost += pow(expectedOutput[i] - realOutput[i], 2);

			return cost;
		}
		double MeanSquaredError(double realOutput, double expectedOutput)
		{
			return pow(expectedOutput - realOutput, 2);
		}
	}
}