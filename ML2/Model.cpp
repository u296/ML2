#include "Model.h"
#include "InputCell.h"
#include "HiddenCell.h"
#include "OutputCell.h"

namespace ML2
{
	namespace Bases
	{
		Model::Model()
		{

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

		void Model::Initialize(std::vector<double *> inputVariables, std::vector<int> modelShape, std::vector<double(*)(double)> activationFunctions)
		{

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
}