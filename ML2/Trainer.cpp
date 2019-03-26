#include "Trainer.h"

ML2::Trainer::Trainer(Model * model)
{
	Attach(model);
}

ML2::Trainer::~Trainer()
{
}

void ML2::Trainer::Attach(Model * model)
{
	m_model = model;
}

void ML2::Trainer::Run()
{
}
