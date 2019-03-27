#include "FeedForwardModel.h"
#include "InputCell.h"
#include "HiddenCell.h"
#include "OutputCell.h"

namespace ML2
{
	namespace Models
	{
		ML2::Models::FeedForwardModel::FeedForwardModel(std::vector<double *> inputVariables, std::vector<int> modelShape, std::vector<double(*)(double)> activationFunctions)
		{
			Initialize(inputVariables, modelShape, activationFunctions);
		}

		void ML2::Models::FeedForwardModel::Initialize(std::vector<double *> inputVariables, std::vector<int> modelShape, std::vector<double(*)(double)> activationFunctions)
		{
			// Populate input layer
			m_inputLayer.reserve(modelShape[0]);	// Reserve enough memory in input layer for all the cells
			for (int i = 0; i < modelShape[0]; i++)
				m_inputLayer.push_back(new ML2::Cells::InputCell(	// Add new cells to input layer
					inputVariables[i]	// Bind input variable address to corresponding array position in input variable vector
				));

			// Populate hidden layers
			m_hiddenLayers.reserve(modelShape.size() - 2);	// Reserve enough memory in the hidden layers for all the layers

			for (int i = 0; i < modelShape.size() - 2; i++)
				m_hiddenLayers.push_back(std::vector<ML2::Bases::Cell *>());

			m_hiddenLayers[0].reserve(modelShape[1]);
			for (int i = 0; i < modelShape[1]; i++)
				m_hiddenLayers[0].push_back(new ML2::Cells::HiddenCell(	// Add hidden cells to first hidden layer
					m_inputLayer,	// Bind input cells to the input layer
					std::vector<double>(m_inputLayer.size(), 1.0),	// Set all weights to 1.0
					activationFunctions[0]	// Set activation function to activation function of the layer
				));	// Create first hidden layer

			for (int i = 1; i < modelShape.size() - 2; i++)	// For every hidden layer in the hidden layers (except for the first)
			{
				m_hiddenLayers[i].reserve(modelShape[i]);	// Reserve enough memory for all the cells in the layer
				for (int j = 0; j < modelShape[i]; j++)	// For every cell in the layer
					m_hiddenLayers[i].push_back(new ML2::Cells::HiddenCell(	// Add hidden cells to hidden layers (except for the first layer)
						m_hiddenLayers[i - 1],	// Bind input cells to previous layer
						std::vector<double>(m_hiddenLayers[i - 1].size(), 1.0),	// Set all weights to 1.0
						activationFunctions[i]	// Set activation function to activation function of the layer
					));
			}

			// Populate output layer
			m_outputLayer.reserve(modelShape[modelShape.size() - 1]);

			for (int i = 0; i < modelShape[modelShape.size() - 1]; i++)
				m_outputLayer.push_back(new ML2::Cells::OutputCell(	// Add output cells to the output layer
					m_hiddenLayers.back(),	// Bind input cells to last layer in hidden layers
					std::vector<double>(m_hiddenLayers.back().size(), 1.0),	// Set all weights to 1.0
					activationFunctions.back()	// Set activation function to last of activation functions
				));

		}
	}
}