#pragma once

#include "Cell.h"

namespace ML2
{
	namespace Cells
	{
		class InputCell : public ML2::Bases::Cell
		{
		public:
			InputCell(double * inputVariable);
			~InputCell();

			virtual double GetOutput() override;

			virtual void Attach(double * inputVariable);
		protected:
			double * m_inputVariable;
		};
	}
}