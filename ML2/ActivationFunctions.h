#pragma once

namespace ML2
{
	namespace Bases
	{
		typedef struct ActivationFunction
		{
			virtual double function(double x);
			virtual double derivative(double x);
			double operator()(double x);
		} ActivationFunction;
	}
}


typedef struct Identity_t : ML2::Bases::ActivationFunction
{
	double function(double x) override;
	double derivative(double x) override;
} Identity_t;

typedef struct Binary_t : ML2::Bases::ActivationFunction
{
	double function(double x) override;
	double derivative(double x) override;
} Binary_t;

typedef struct Sigmoid_t : ML2::Bases::ActivationFunction
{
	double function(double x) override;
	double derivative(double x) override;
} Sigmoid_t;

typedef struct SoftSign_t : ML2::Bases::ActivationFunction
{
	double function(double x) override;
	double derivative(double x) override;
} SoftSign_t;


namespace ML2
{
	namespace ActivationFunctions
	{
		Identity_t identity;
		Binary_t binary;
		Sigmoid_t sigmoid;
		SoftSign_t softsign;
	}
}