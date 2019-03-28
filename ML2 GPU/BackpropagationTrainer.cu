#include "BackpropagationTrainer.cuh"

namespace ML2
{
	namespace Trainers
	{
		BackpropagationTrainer::BackpropagationTrainer(ML2::Bases::Model * model)
		{
			Attach(model);
		}
		void BackpropagationTrainer::Run()
		{
		}
	}
}