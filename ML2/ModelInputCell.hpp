#pragma once

#include "Cell.hpp"

class ModelInputCell : public Cell
{
public:
	ModelInputCell(double * inputVariable);
	~ModelInputCell();

	double GetValue() override;
private:
	double * m_inputVariable;
};