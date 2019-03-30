#pragma once

#include "Model.h"
#include "Trainer.h"
#include "CostFunctions.h"

namespace ML2
{
	namespace Trainers
	{
		class BackpropagationTrainer : public ML2::Bases::Trainer
		{
		public:
			BackpropagationTrainer(ML2::Bases::Model * model, ML2::Bases::CostFunction * costFunction);
			// Inherit destructor

			virtual void Run(int timesToRun) override;
			
		protected:
			virtual void OrganizeCells();
			virtual void ResetErrors();

			std::vector<ML2::Bases::Cell *> m_modelCells;
			bool m_cellsAreOrganized;

			ML2::Bases::CostFunction * m_costFunction;
		};
	}
}