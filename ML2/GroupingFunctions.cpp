#include "GroupingFunctions.h"

namespace ML2
{
	namespace GroupingFunctions
	{
		double Average(std::vector<double> values)
		{
			return Sum(values) / values.size();
		}

		double Sum(std::vector<double> values)
		{
			double sum = 0;
			for (const auto & e : values)
				sum += e;
			return sum;
		}
	}
}