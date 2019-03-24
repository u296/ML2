#include "GroupingFunctions.h"

double ML2::GroupingFunctions::Average(std::vector<double> values)
{
	return Sum(values) / values.size();
}

double ML2::GroupingFunctions::Sum(std::vector<double> values)
{
	double sum = 0;
	for (const auto & e : values)
		sum += e;
	return sum;
}
