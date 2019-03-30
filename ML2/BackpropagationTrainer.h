#pragma once

#include "Model.h"
#include "Trainer.h"

namespace ML2
{
	namespace Trainers
	{
		class BackpropagationTrainer : public ML2::Bases::Trainer
		{
		public:
			BackpropagationTrainer(ML2::Bases::Model * model);
			// Inherit destructor

			virtual void Run(int timesToRun) override;
			
		protected:
			virtual void OrganizeCells();
			virtual void ResetErrors();

			std::vector<ML2::Bases::Cell *> m_modelCells;
			bool m_cellsAreOrganized;
		};
	}
}