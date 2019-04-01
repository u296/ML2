#pragma once
#include <vector>
namespace ML2
{
	namespace Bases
	{
		struct CostFunction
		{
			virtual double operator()(std::vector<double> realOutput, std::vector<double> expectedOutput);
			virtual double operator()(double realOutput, double expectedOutput);
			virtual double D_cost_realOutput(double realOutput, double expectedOutput);
			virtual double GetExpectedOutput(double cost, double realOutput);
		};
	}

	namespace CostFunctions
	{
		struct MeanSquaredError_t : ML2::Bases::CostFunction
		{
			double operator()(std::vector<double> realOutput, std::vector<double> expectedOutput) override;
			double operator()(double realOutput, double expectedOutput) override;
			double D_cost_realOutput(double realOutput, double expectedOutput) override;
			double GetExpectedOutput(double cost, double realOutput) override;
		};

		MeanSquaredError_t meanSquaredError;
	}
}