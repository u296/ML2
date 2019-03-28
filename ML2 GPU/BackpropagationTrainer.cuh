#pragma once

#include "Model.cuh"
#include "Trainer.cuh"

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