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


double Identity_t::function(double x)
{
	return x;
}
double Identity_t::derivative(double x)
{
	return 1;
}

double Binary_t::function(double x)
{
	return x >= 0 ? 1 : 0;
}
double Binary_t::derivative(double x)
{
	return x == 0 ? 1 : 0;
}

double Sigmoid_t::function(double x)
{
	return 1 / (1 + exp(-x));
}
double Sigmoid_t::derivative(double x)
{
	return exp(x) / pow(exp(x) + 1, 2);
}

double SoftSign_t::function(double x)
{
	return x / (1 + abs(x));
}
double SoftSign_t::derivative(double x)
{
	return 1 / pow(1 + abs(x), 2);
}
