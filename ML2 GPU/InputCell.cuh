#pragma once

#include "Cell.cuh"

namespace ML2
{
	namespace Cells
	{
		class InputCell : public ML2::Bases::Cell
		{
		public:
			InputCell(double * inputVariable);
			~InputCell();

			virtual double GetValue() override;
		protected:
			double * m_inputVariable;
		};
	}
}