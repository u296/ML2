#include "Model.h"
#include "ModelInputCell.h"
#include "HiddenCell.h"
#include "OutputCell.h"

namespace ML2
{
	Model::Model(std::vector<double *> inputVariables, std::vector<int> modelShape, std::vector<double(*)(std::vector<double>)> groupingFunctions, std::vector<double(*)(double)> activationFunctions)
	{
		int inputLayerCellCount = modelShape[0];
		{	// Populate input layer
			m_inputLayer.reserve(inputLayerCellCount);	// Reserve enough memory in input layer for all the cells
			for (int i = 0; i < inputLayerCellCount; i++)
				m_inputLayer.push_back(new ML2::Cells::ModelInputCell(	// Add new cells to input layer
					inputVariables[i],	// Bind input variable address to corresponding array position in input variable vector
					{ 1.0 },	// Set input weight to 1.0 
					1.0,	// Set output weight to 1.0
					groupingFunctions[0],	// Set grouping function to grouping function of the input layer
					activationFunctions[0]	// Set activation function to activation function of the input layer
				));
		}
		
		{	// Populate hidden layers
			m_hiddenLayers.reserve(modelShape.size() - 2);	// Reserve enough memory in the hidden layers for all the layers

			for (int i = 0; i < modelShape.size() - 2; i++)
				m_hiddenLayers.push_back(std::vector<ML2::Cells::Cell *>());

			m_hiddenLayers[0].reserve(modelShape[1]);
			for (int i = 0; i < modelShape[1]; i++)
				m_hiddenLayers[0].push_back(new ML2::Cells::HiddenCell(	// Add hidden cells to first hidden layer
					m_inputLayer,	// Bind input cells to the input layer
					std::vector<double>(m_inputLayer.size(), 1.0),	// Set input weights to vector of the same length as the input layer, filled with 1.0s
					1.0,	// Set output weight to 1.0
					groupingFunctions[1],	// Set grouping function to grouping function of the layer
					activationFunctions[1]	// Set activation function to activation function of the layer
				));	// Create first hidden layer

			for (int i = 1; i < modelShape.size() - 2; i++)	// For every hidden layer in the hidden layers (except for the first)
			{
				m_hiddenLayers[i].reserve(modelShape[i]);	// Reserve enough memory for all the cells in the layer
				for (int j = 0; j < modelShape[i]; j++)	// For every cell in the layer
					m_hiddenLayers[i].push_back(new ML2::Cells::HiddenCell(	// Add hidden cells to hidden layers (except for the first layer)
						m_hiddenLayers[i - 1],	// Bind input cells to previous layer
						std::vector<double>(m_hiddenLayers[i - 1].size(), 1.0),	// Set input weights to vector of the same length as the previous layer, filled with 1.0s
						1.0,	// Set output weight to 1.0
						groupingFunctions[i],	// Set grouping function to grouping function of the layer
						activationFunctions[i]	// Set activation function to activation function of the layer
						));
			}
		}

		{	// Populate output layer
			m_outputLayer.reserve(modelShape[modelShape.size() - 1]);

			for (int i = 0; i < modelShape[modelShape.size() - 1]; i++)
				m_outputLayer.push_back(new ML2::Cells::OutputCell(	// Add output cells to the output layer
					m_hiddenLayers.back(),	// Bind input cells to last layer in hidden layers
					std::vector<double>(m_hiddenLayers.back().size(), 1.0),	// Set input weights to vector of the same length as the previous layer, filled with 1.0s
					1.0,	// Set output weight to 1.0
					groupingFunctions.back(),	// Set grouping function to last of grouping functions
					activationFunctions.back()	// Set activation function to last of activation functions
				));
		}
	}

	Model::~Model()
	{
		//	Delete all output cells
		for (auto iterator = m_outputLayer.rbegin(); iterator != m_outputLayer.rend(); iterator++)
			delete *iterator;
		m_outputLayer.clear();

		//	Delete all hidden cells
		for (auto outerIterator = m_hiddenLayers.rbegin(); outerIterator != m_hiddenLayers.rend(); outerIterator++)	// Pointer to vector
		{
			for (auto innerIterator = outerIterator->rbegin(); innerIterator != outerIterator->rend(); innerIterator++)	// Pointer to cell pointer
			{
				delete *innerIterator;
			}
			outerIterator->clear();
		}
		m_hiddenLayers.clear();

		//	Delete all input cells
		for (auto iterator = m_inputLayer.rbegin(); iterator != m_inputLayer.rend(); iterator++)
			delete *iterator;
		m_inputLayer.clear();
	}
	std::vector<double> Model::Evaluate()
	{
		std::vector<double> evaluations;

		evaluations.reserve(m_outputLayer.size());
		for (auto & outputCell : m_outputLayer)
			evaluations.push_back(outputCell->GetValue());

		return evaluations;
	}
}