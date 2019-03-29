#include "HelperUtilities.h"

double ML2::HelperUtilities::Sum(std::vector<double> list)
{
	double sum = 0;

	for (const auto & e : list)
		sum += e;

	return sum;
}
