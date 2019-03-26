#pragma once

#include "Model.h"

namespace ML2
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

		std::vector<double> * m_trainingData;
		std::vector<double> * m_trainingLabels;
		std::vector<double> * m_testingData;
		std::vector<double> * m_testingLabels;
	};
}