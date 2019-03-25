#pragma once

#include <vector>

#include "Cell.h"

namespace ML2
{
	class Model
	{
	public:
		Model(std::vector<double *> inputVariables, std::vector<int> modelShape, std::vector<double(*)(std::vector<double>)> groupingFunctions, std::vector<double(*)(double)> activationFunctions);
		virtual ~Model();
		
		ML2::Cells::Cell operator[](int index) const;	// getter
		ML2::Cells::Cell & operator[](int index);		// setter

		virtual std::vector<double> Evaluate();
	protected:
		std::vector<ML2::Cells::Cell *> m_inputLayer;
		std::vector<std::vector<ML2::Cells::Cell *>> m_hiddenLayers;
		std::vector<ML2::Cells::Cell *> m_outputLayer;
	};
}