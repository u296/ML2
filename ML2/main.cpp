#include <stdlib.h>
#include <iostream>
#include <vector>

#include "ML2.h"

int main()
{
	double in1 = 69;
	double in2 = 420;
	double in3 = 666;
	double in4 = -333;
	double in5 = 21;

	ML2::Model * model = new ML2::Model(
		{ &in1, &in2, &in3, &in4, &in5 },
		{ 5,35,5,2 },
		{ ML2::GroupingFunctions::Average, ML2::GroupingFunctions::Average, ML2::GroupingFunctions::Average, ML2::GroupingFunctions::Average, ML2::GroupingFunctions::Average },
		{ ML2::ActivationFunctions::SoftSign,ML2::ActivationFunctions::SoftSign,ML2::ActivationFunctions::SoftSign,ML2::ActivationFunctions::SoftSign,ML2::ActivationFunctions::SoftSign }
	);

	std::vector<double> t = model->Evaluate();
	
	std::cout << t[0] << std::endl;

	delete model;

	std::cout << "End of program. Press return to continue.";
	std::cin.get();
	return EXIT_SUCCESS;
}