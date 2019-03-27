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
			BackpropagationTrainer(ML2::Bases::Model * model = nullptr);
			// Inherit destructor

			virtual void Run() override;
		protected:
		};
	}
}