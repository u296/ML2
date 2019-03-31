#include <cmath>

#include "ActivationFunctions.h"

namespace ML2
{
	namespace Bases
	{
		double ActivationFunction::function(double)
		{
			return 0.0;
		}

		double ActivationFunction::derivative(double)
		{
			return 0.0;
		}

		double ActivationFunction::operator()(double x)
		{
			return function(x);
		}
	}
}

double Identity::function(double x)
{
	return x;
}
double Identity::derivative(double x)
{
	return 1;
}

double Binary::function(double x)
{
	return x >= 0 ? 1 : 0;
}
double Binary::derivative(double x)
{
	return x == 0 ? 1 : 0;
}

double Sigmoid::function(double x)
{
	return 1 / (1 + exp(-x));
}
double Sigmoid::derivative(double x)
{
	return exp(x) / pow(exp(x) + 1, 2);
}

double SoftSign::function(double x)
{
	return x / (1 + abs(x));
}
double SoftSign::derivative(double x)
{
	return 1 / pow(1 + abs(x), 2);
}

namespace ML2
{
	namespace ActivationFunctions
	{
		
	}
}
