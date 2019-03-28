#include <numeric>
#include "InputCell.h"

namespace ML2
{
	namespace Cells
	{
		InputCell::InputCell(double * inputVariable)
			: m_inputVariable(inputVariable)
		{
			
		}

		InputCell::~InputCell()
		{

		}

		double InputCell::GetOutput()
		{
			return *m_inputVariable;
		}
	}
}
