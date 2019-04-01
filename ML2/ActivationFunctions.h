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

namespace ML2
{
	namespace ActivationFunctions
	{
		struct Identity_t : ML2::Bases::ActivationFunction
		{
			double function(double x) override;
			double derivative(double x) override;
		};

		struct Binary_t : ML2::Bases::ActivationFunction
		{
			double function(double x) override;
			double derivative(double x) override;
		};

		struct Sigmoid_t : ML2::Bases::ActivationFunction
		{
			double function(double x) override;
			double derivative(double x) override;
		};

		struct SoftSign_t : ML2::Bases::ActivationFunction
		{
			double function(double x) override;
			double derivative(double x) override;
		};
	}
}

namespace ML2
{
	namespace ActivationFunctions
	{
		ML2::ActivationFunctions::Identity_t identity;
		ML2::ActivationFunctions::Binary_t binary;
		ML2::ActivationFunctions::Sigmoid_t sigmoid;
		ML2::ActivationFunctions::SoftSign_t softsign;
	}
}