#include <numeric>
#include "InputCell.cuh"

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

		double InputCell::GetValue()
		{
			return *m_inputVariable;
		}
	}
}
