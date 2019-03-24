#include <math.h>

#include "ActivationFunctions.h"

double ML2::ActivationFunctions::Identity(double x)
{
	return x;
}

double ML2::ActivationFunctions::Binary(double x)
{
	if (x >= 0)
		return 1;
	return 0;
}

double ML2::ActivationFunctions::Sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}

double ML2::ActivationFunctions::SoftSign(double x)
{
	return x / (1 + abs(x));
}