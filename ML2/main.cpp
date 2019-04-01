#include <stdlib.h>
#include <iostream>
#include <vector>

#include "FeedForwardModel.h"
#include "BackpropagationTrainer.h"

int main()
{
	
	
	double da0 = 1;
	double da1 = 0;
	double da2 = 1;
	double da3 = 0;
	double da4 = 1;
	double da5 = 0;
	double da6 = 1;
	double da7 = 0;
	double da8 = 1;
	double da9 = 0;

	std::vector<std::vector<double *>> trainingData = 
	{	
	{	&da0},
	{	&da1},
	{	&da2},
	{	&da3},
	{	&da4},
	{	&da5},
	{	&da6},
	{	&da7},
	{	&da8},
	{	&da9},
	};

	std::vector<std::vector<double>> trainingAnwsers =
	{
		{0},
		{1},
		{0},
		{1},
		{0},
		{1},
		{0},
		{1},
		{0},
		{1},
	};

	ML2::Models::FeedForwardModel * model = new ML2::Models::FeedForwardModel(
		{nullptr},
		{1, 1, 1},
		{&ML2::ActivationFunctions::sigmoid, &ML2::ActivationFunctions::sigmoid}
	);

	ML2::Trainers::BackpropagationTrainer * trainer = new ML2::Trainers::BackpropagationTrainer(
		model,
		&ML2::CostFunctions::meanSquaredError,
		0.1,
		trainingData,
		trainingAnwsers
	);

	trainer->Run(5);

	double k = 1;

	std::vector<double *> l = { &k };

	model->SetInputVariables(l);

	std::cout << model->Evaluate()[0];

	delete trainer;
	delete model;
	
	
	std::cout << "End of program. Press return to continue.";
	std::cin.get();
	return EXIT_SUCCESS;
}