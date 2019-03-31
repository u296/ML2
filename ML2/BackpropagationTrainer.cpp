#include "BackpropagationTrainer.h"
#include "HelperUtilities.h"
#include "Cell.h"

namespace ML2
{
	namespace Trainers
	{
		BackpropagationTrainer::BackpropagationTrainer(
			ML2::Bases::Model * model,
			ML2::Bases::CostFunction * costFunction,
			double learningRate,
			std::vector<std::vector<double *>> trainingData,
			std::vector<std::vector<double>> trainingAnwsers
		)
			: m_costFunction(costFunction), m_learningRate(learningRate)
		{
			Attach(model);
		}



		void BackpropagationTrainer::Run(int timesToRun)
		{
			

			for (int trainingIteration = 0; trainingIteration < timesToRun; trainingIteration++)
			{
				m_model->SetInputVariables(m_trainingData[m_currentTrainingDataIndex]);

				std::vector<double> realModelOutput = m_model->Evaluate();
				std::vector<double> expectedModelOutput = m_trainingAnwsers[m_currentTrainingDataIndex];

				ResetErrors();	// Reset the errors of all the cells

				double modelCost = m_costFunction->operator()(realModelOutput, expectedModelOutput);	//	Cost of the entire model

				for (int i = 0; i < m_model->m_outputLayer.size(); i++)	// Set error for output cells
					m_model->m_outputLayer[i]->GetError() = m_costFunction->D_cost_realOutput(realModelOutput[i], expectedModelOutput[i]);

				for (int i = 0; i < m_modelCells.size(); i++)	// For every cell in the model
				{
					ML2::Bases::Cell * cell = m_modelCells[i];	// Instanciate the current cell as cell

					// Magic calculus bullshit

					double cellOutput = cell->GetOutput();
					double cellOutputInput = cell->GetOutputInput();


					double D_cellError_cellOutput = m_costFunction->D_cost_realOutput(cellOutput, m_costFunction->GetExpectedOutput(cell->GetError(), cellOutput));
					double D_cellOutput_cellOutputInput = cell->GetActivationFunction()->derivative(cellOutputInput);
					double D_cellOutputInput_cellBias = 1;

					double D_cellError_cellBias = D_cellError_cellOutput * D_cellOutput_cellOutputInput * D_cellOutputInput_cellBias;	// Error of this cells bias

					cell->GetBias() += -1 * m_learningRate * D_cellError_cellBias;
					// Change bias by negative bias error times learning rate

					for (int i = 0; i < cell->GetWeights().size(); i++)	// For every cell / weight leading into this cell
					{
						double D_cellOutputInput_cellWeightI = cell->GetInputCells()[i]->GetOutput();
						double D_cellOutputInput_cellOutputI = cell->GetWeights()[i];


						double D_cellError_cellWeightI = D_cellError_cellOutput * D_cellOutput_cellOutputInput * D_cellOutputInput_cellWeightI;	// Error of the weight
						double D_cellError_cellOutputI = D_cellError_cellOutput * D_cellOutput_cellOutputInput * D_cellOutputInput_cellOutputI;	// Error of the other cell
						
						cell->GetInputCells()[i]->GetError() += D_cellError_cellOutputI;	// add the inputting cells error to the right place


						cell->GetWeights()[i] += -1 * m_learningRate * D_cellError_cellWeightI;
						// Change the current weight by negative error of weight times learning rate
					}
				}
				





				m_currentTrainingDataIndex++;
			}
		}



		void BackpropagationTrainer::OrganizeCells()	// Organize and store pointers to cells of the model in the member m_modelCells
		{
			int modelLayerCount = 1 + m_model->m_hiddenLayers.size(); // Total amount of layers in the model (except input layer)

			int modelCellCount = 0;	// Total amount of cells in the model (excluding inputs)

			std::vector<int> layerCellCounts(modelLayerCount);	// Amount of cells in every layer

			for (int i = 0; i < modelLayerCount; i++)	// For every layer
			{
				modelCellCount +=	// Add to the complete cellcount
					i == modelLayerCount - 1 ?	// If were on the last loop (indicating output layer)
					m_model->m_outputLayer.size() :	// Add the size of the output layer
					m_model->m_hiddenLayers[i].size();	// Else: add the size of hiddenlayer "i"

				layerCellCounts.push_back(	// Push to layercellcounts
					i == modelLayerCount - 1 ?	// If were on the last loop (indicating output layer)
					m_model->m_outputLayer.size() :	// Push the size of the output layer
					m_model->m_hiddenLayers[i].size()	// Else: push the size of hiddenlayer "i"
				);
			}


			m_modelCells.reserve(modelCellCount);	// Reserve enough memory to store all the cells of the model locally
			for (int i = 0; i < modelLayerCount; i++)	// For every layer in the model (except inputs)
			{
				for (int j = 0; j < layerCellCounts[i]; j++)
				{
					m_modelCells.push_back(	// Push back cells
						i == modelLayerCount - 1 ?	// If were on the last loop (indicating output layer)
						m_model->m_outputLayer[j] :	// Push back cell j of output layer
						m_model->m_hiddenLayers[i][j]	// Push back cell j of hidden layer i
					);
				}
			}

			m_cellsAreOrganized = true;
		}



		void BackpropagationTrainer::ResetErrors()
		{
			if (!m_cellsAreOrganized)
				OrganizeCells();

			for (int i = 0; i < m_modelCells.size(); i++)
				m_modelCells[i]->GetError() = 0;
		}
	}
}