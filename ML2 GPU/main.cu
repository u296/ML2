#include <cuda_runtime.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "ML2.cuh"

int main()
{
	double in1 = 69;
	double in2 = 420;
	double in3 = 666;
	double in4 = -333;
	double in5 = 21;

	ML2::Models::FeedForwardModel * model = new ML2::Models::FeedForwardModel(
		{ &in1, &in2, &in3, &in4, &in5 },
		{ 1,5,5,4 },
		{ ML2::ActivationFunctions::SoftSign,ML2::ActivationFunctions::SoftSign,ML2::ActivationFunctions::SoftSign,ML2::ActivationFunctions::SoftSign,ML2::ActivationFunctions::SoftSign }
	);

	std::vector<double> t = model->Evaluate();
	
	for (int i = 0; i < t.size(); i++)
		std::cout << t[i] << std::endl;

	delete model;

	std::cout << "End of program. Press return to continue.";
	std::cin.get();
	return EXIT_SUCCESS;
}