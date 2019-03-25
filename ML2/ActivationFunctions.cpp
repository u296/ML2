#include <math.h>

#include "ActivationFunctions.h"
namespace ML2
{
	namespace ActivationFunctions
	{
		double Identity(double x)
		{
			return x;
		}

		double Binary(double x)
		{
			if (x >= 0)
				return 1;
			return 0;
		}

		double Sigmoid(double x)
		{
			return 1 / (1 + exp(-x));
		}

		double SoftSign(double x)
		{
			return x / (1 + fabs(x));
		}
	}
}