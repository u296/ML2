#pragma once

#include "Model.cuh"

namespace ML2
{
	namespace Bases
	{
		class Trainer
		{
		public:
			Trainer(Model * model = nullptr);
			virtual ~Trainer();

			virtual void Attach(Model * model);
			virtual void Run();
		protected:
			Model * m_model;

			std::vector<std::vector<double>> *	m_trainingData;
			std::vector<double> *				m_trainingAnwsers;
			std::vector<std::vector<double>> *	m_testingData;
			std::vector<double> *				m_testingAnwsers;
		};
	}
}