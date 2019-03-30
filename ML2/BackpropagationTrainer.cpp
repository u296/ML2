#include "BackpropagationTrainer.h"
#include "CostFunctions.h"
#include "HelperUtilities.h"
#include "Cell.h"

namespace ML2
{
	namespace Trainers
	{
		BackpropagationTrainer::BackpropagationTrainer(ML2::Bases::Model * model)
		{
			Attach(model);
		}
		void BackpropagationTrainer::Run(int timesToRun)
		{
			

			for (int trainingIteration = 0; trainingIteration < timesToRun; trainingIteration++)
			{
				m_model->SetInputVariables(m_trainingData[m_currentTrainingDataIndex]);

				std::vector<double> realOutput = m_model->Evaluate();
				std::vector<double> expectedOutput = m_trainingAnwsers[m_currentTrainingDataIndex];

				double modelCost = ML2::CostFunctions::MeanSquaredError(realOutput, expectedOutput);	//	Cost of the entire model

				for (int i = 0; i < m_model->m_outputLayer.size(); i++)	// Set error for output cells
					m_model->m_outputLayer[i]->GetError() = ML2::CostFunctions::MeanSquaredError(realOutput[i], expectedOutput[i]);


				





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
						m_model->m_outputLayer[j] :	// Push back output layer cell j
						m_model->m_hiddenLayers[i][j]	// Push back hidden layer i cell j
					);
				}
			}
		}
		void BackpropagationTrainer::ResetErrors()
		{

		}
	}
}