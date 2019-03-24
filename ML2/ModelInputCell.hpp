#pragma once

#include "Cell.hpp"

class ModelInputCell : public Cell
{
public:
	ModelInputCell(double(*GroupingFunction)(std::vector<double>), double(*ActivationFunction)(double), double * inputVariable);
	~ModelInputCell();

	double GetValue() override;
private:
	double * m_inputVariable;
};