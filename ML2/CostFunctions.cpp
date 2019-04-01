#include <cmath>
#include "CostFunctions.h"

namespace ML2
{
	namespace Bases
	{
		double CostFunction::operator()(std::vector<double> realOutput, std::vector<double> expectedOutput)
		{
			return 0;
		}

		double CostFunction::operator()(double realOutput, double expectedOutput)
		{
			return 0;
		}

		double CostFunction::D_cost_realOutput(double realOutput, double expectedOutput)
		{
			return 0;
		}

		double CostFunction::GetExpectedOutput(double cost, double realOutput)
		{
			return 0;
		}
	}
	namespace CostFunctions
	{
		double MeanSquaredError_t::operator()(std::vector<double> realOutput, std::vector<double> expectedOutput)
		{
			double cost = 0;

			for (int i = 0; i < realOutput.size(); i++)
				cost += pow(expectedOutput[i] - realOutput[i], 2);

			return cost;
		}

		double MeanSquaredError_t::operator()(double realOutput, double expectedOutput)
		{
			return pow(expectedOutput - realOutput, 2);
		}

		double MeanSquaredError_t::D_cost_realOutput(double realOutput, double expectedOutput)
		{
			return 2 * (realOutput - expectedOutput);
		}

		double MeanSquaredError_t::GetExpectedOutput(double cost, double realOutput)
		{
			return sqrt(cost) + realOutput;
		}

	}
}



