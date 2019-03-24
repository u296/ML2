#include <stdlib.h>
#include <iostream>
#include <vector>

#include "ML2.h"

int main()
{
	double inOne = 26;
	double inTwo = 69420;

	ML2::Cells::ModelInputCell * inCellOne = new ML2::Cells::ModelInputCell(
		&inOne,
		{ 1.0 },
		1.0,
		ML2::GroupingFunctions::Sum,
		ML2::ActivationFunctions::Identity
	);

	ML2::Cells::ModelInputCell * inCellTwo = new ML2::Cells::ModelInputCell(
		&inTwo,
		{ 1.0 },
		1.0,
		ML2::GroupingFunctions::Sum,
		ML2::ActivationFunctions::Identity
	);

	ML2::Cells::HiddenCell * hCellOneOne = new ML2::Cells::HiddenCell(
		{inCellOne, inCellTwo},
		{1, 1},
		1.0,
		ML2::GroupingFunctions::Average,
		ML2::ActivationFunctions::Identity
	);

	ML2::Cells::OutputCell * oCellOne = new ML2::Cells::OutputCell(
		{ hCellOneOne },
		{ 1 },
		1.0,
		ML2::GroupingFunctions::Average,
		ML2::ActivationFunctions::Identity
	);

	std::cout << oCellOne->GetValue() << std::endl;

	delete oCellOne;
	delete hCellOneOne;
	delete inCellOne;
	delete inCellTwo;

	std::cout << "End of program. Press return to continue.";
	std::cin.get();
	return EXIT_SUCCESS;
}