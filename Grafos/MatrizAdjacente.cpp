#include "MatrizAdjacente.h"
#include <iostream>
using namespace std;

MatrizAdjacente::MatrizAdjacente(int numeroVertices)
{
	if (numeroVertices <= 0)
		throw invalid_argument("O numero de vertices deve ser maior que zero");

	_numeroVertices = numeroVertices;
	_grafo.assign(numeroVertices, vector<int>(numeroVertices, 0));
}

void MatrizAdjacente::InserirElementos()
{
	int aresta;
	for (int i = 0; i < _numeroVertices; i++)
	{
		for (int j = i + 1; j < _numeroVertices; j++)
		{
			cout << "Vertice " << i + 1 << " e Vertice " << j + 1 << " possuem aresta? (1 para sim, 0 para nao): ";
			cin >> aresta;
			
			while (aresta != 0 && aresta != 1)
			{
				cout << "Entrada invalida! Digite 0 ou 1: ";
				cin >> aresta;
			}
			
			_grafo[i][j] = aresta;
			_grafo[j][i] = aresta;
		}
	}
}

void MatrizAdjacente::ImprimeMatriz() {
	for (int i = 0; i < _numeroVertices; i++)
	{
		cout << "\n";
		for (int j = 0; j < _numeroVertices; j++)
			cout << _grafo[i][j] << " ";
	}
	cout << "\n";
}

void MatrizAdjacente::ImprimeGrau()
{
	for (int i = 0; i < _numeroVertices; i++)
	{
		int grau = 0;
		for (int j = 0; j < _numeroVertices; j++)
			grau += _grafo[i][j];
		cout << "Grau do vertice " << i + 1 << ": " << grau << endl;
	}
}

bool MatrizAdjacente::VerificarSimetria()
{
	for (int i = 0; i < _numeroVertices; i++)
	{
		for (int j = 0; j < _numeroVertices; j++)
		{
			if (_grafo[i][j] != _grafo[j][i])
			{
				cout << "ERRO: Matriz nao eh simetrica! Posicoes [" << i << "][" << j << "] != [" << j << "][" << i << "]" << endl;
				return false;
			}
		}
	}
	cout << "Matriz validada: eh simetrica!" << endl;
	return true;
}


