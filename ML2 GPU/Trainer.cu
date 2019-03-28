#include "Trainer.cuh"

namespace ML2
{
	namespace Bases
	{
		Trainer::Trainer(Model * model)
		{
			Attach(model);
		}

		Trainer::~Trainer()
		{
		}

		void Trainer::Attach(Model * model)
		{
			m_model = model;
		}

		void Trainer::Run()
		{
		}
	}
}