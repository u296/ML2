#pragma once

#include "Model.h"

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
			virtual void Run(int timesToTrain);
		protected:
			Model * m_model;

			std::vector<std::vector<double *>>	m_trainingData;
			std::vector<std::vector<double>>	m_trainingAnwsers;
			std::vector<std::vector<double *>>	m_testingData;
			std::vector<std::vector<double>>    m_testingAnwsers;

			int m_currentTrainingDataIndex;
		};
	}
}