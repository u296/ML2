#pragma once

namespace ML2
{
	namespace Bases
	{
		struct ActivationFunction
		{
			virtual double function(double x);
			virtual double derivative(double x);
			double operator()(double x);
		};
	}
}

static struct Identity : ML2::Bases::ActivationFunction
{
	double function(double x) override;
	double derivative(double x) override;
};

static struct Binary : ML2::Bases::ActivationFunction
{
	double function(double x) override;
	double derivative(double x) override;
};

static struct Sigmoid : ML2::Bases::ActivationFunction
{
	double function(double x) override;
	double derivative(double x) override;
};

static struct SoftSign : ML2::Bases::ActivationFunction
{
	double function(double x) override;
	double derivative(double x) override;
};

namespace ML2
{
	namespace ActivationFunctions
	{
		Identity identity;
		Binary binary;
		Sigmoid sigmoid;
		SoftSign softsign;
	}
}