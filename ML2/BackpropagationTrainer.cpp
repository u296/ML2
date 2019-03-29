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
			int networkLayerCount = 1 + m_model->m_hiddenLayers.size(); // Total amount of layers in the network

			std::vector<int> layerCellCounts(networkLayerCount);	// Amount of cells in every layer

			for (int i = 0; i < networkLayerCount; i++)
			{
				if (i == networkLayerCount - 1)
					layerCellCounts[i] += m_model->m_outputLayer.size();
				else
					layerCellCounts[i] += m_model->m_hiddenLayers[i].size();
			}


			std::vector<std::vector<ML2::Bases::Cell *>> networkCells(networkLayerCount);	// All the cells in all the layers in the model

			for (int i = 0; i < networkLayerCount; i++)
			{
				networkCells.emplace_back();

				networkCells[i].reserve(layerCellCounts[i]);
				for (int j = 0; j < layerCellCounts[i]; j++)
				{
					if (i == networkLayerCount - 1)
						networkCells[i].push_back(m_model->m_outputLayer[j]);
					else
						networkCells[i].push_back(m_model->m_hiddenLayers[i][j]);
				}
			}

			for (int trainingIteration = 0; trainingIteration < timesToRun; trainingIteration++)
			{
				m_model->SetInputVariables(m_trainingData[m_currentTrainingDataIndex]);

				std::vector<double> realOutput = m_model->Evaluate();
				std::vector<double> expectedOutput = m_trainingAnwsers[m_currentTrainingDataIndex];

				double networkCost = ML2::CostFunctions::MeanSquaredError(realOutput, expectedOutput);	//	Cost of the entire network

				for (int i = 0; i < m_model->m_outputLayer.size(); i++)	// Set error for output cells
					m_model->m_outputLayer[i]->GetError() = ML2::CostFunctions::MeanSquaredError(realOutput[i], expectedOutput[i]);


				for (int layerCounter = 0; layerCounter < networkLayerCount; layerCounter++)
				{
					for (int cellCounter = 0; cellCounter < layerCellCounts[layerCounter]; cellCounter++)
					{
						ML2::Bases::Cell * cell = networkCells[layerCounter][cellCounter];

						for (int i = 0; i < cell->GetInputCells().size(); i++)	// Set error for inputs to current cell
						{
							ML2::Bases::Cell * inputCell = cell->GetInputCells()[i];

							double weightSum = ML2::HelperUtilities::Sum(cell->GetWeights());

							inputCell->GetError() += cell->GetError() * (cell->GetWeights()[i] / weightSum);
						}
					}
				}





				m_currentTrainingDataIndex++;
			}
		}
	}
}