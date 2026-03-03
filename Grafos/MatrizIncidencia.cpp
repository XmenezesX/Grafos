#include "MatrizAdjacente.h"
#include "MatrizIncidencia.h"
#include <iostream>
using namespace std;

MatrizIncidencia::MatrizIncidencia(int numeroVertices, int numeroAresta)
{
	if (numeroVertices < 1)
		throw invalid_argument("Numero de vertices deve ser >= 1.");

	if (numeroAresta < 0)
		throw invalid_argument("Numero de arestas nao pode ser negativo.");

	_grafo.assign(numeroVertices, vector<int>(numeroAresta, 0));
	_numeroVertices = numeroVertices;
	_numeroArestas = numeroAresta;
}

void MatrizIncidencia::InserirElementos()
{
	for (int i = 0; i < _numeroArestas; i++)
	{

		int verticeOrigem, verticeDestino;
		cout << "Digite o vertice de origem da aresta " << i + 1 << ": ";
		cin >> verticeOrigem;
		cout << "Digite o vertice de destino da aresta " << i + 1 << ": ";
		cin >> verticeDestino;
		verticeDestino -= 1;
		verticeOrigem -= 1;
		while (verticeOrigem < 0 || verticeOrigem >= _numeroVertices || verticeDestino < 0 || verticeDestino >= _numeroVertices || verticeOrigem == verticeDestino)
		{
			cout << "Vertices invalidos.\n";
			cout << "Digite o vertice de origem da aresta " << i + 1 << ": ";
			cin >> verticeOrigem;
			cout << "Digite o vertice de destino da aresta " << i + 1 << ": ";
			cin >> verticeDestino;
		}
		_grafo[verticeOrigem][i] = 1;
		_grafo[verticeDestino][i] = -1;
	}

	if (!VerificarGrafoDirecionado())
	{
		cout << "Grafo invalido!\n Digite novamente os vertices de origem e destino!";
		return InserirElementos();
	}
}

bool MatrizIncidencia::VerificarGrafoDirecionado()
{
	int qntd1 = 0, qntdMenos1 = 0;
	for (int i = 0; i < _numeroArestas; i++)
	{
		for (int j = 0; j < _numeroVertices; j++)
		{
			if (_grafo[j][i] == 1)
				qntd1++;
			if (_grafo[j][i] == -1)
				qntdMenos1++;
		}

		if (qntd1 != 1 || qntdMenos1 != 1)
			return false;

		qntd1 = qntdMenos1 = 0;
	}
	return true;
}

void MatrizIncidencia::ImprimeMatriz()
{
	for (int i = 0; i < _numeroVertices; i++)
	{
		cout << "\n";
		for (int j = 0; j < _numeroArestas; j++)
			cout << _grafo[i][j] << " ";
	}
	cout << "\n";
}

void MatrizIncidencia::ImprimeGrau()
{
    for (int i = 0; i < _numeroVertices; i++)
    {
        int grauEntrada = 0;
        int grauSaida = 0;
        for (int j = 0; j < _numeroArestas; j++)
        {
            if (_grafo[i][j] == 1) grauSaida++;
            if (_grafo[i][j] == -1) grauEntrada++;
        }
        cout << "Vertice " << i + 1 << " -> Saida: " << grauSaida << " | Entrada: " << grauEntrada << endl;
    }
}

vector<vector<int>> MatrizIncidencia::TranformaEmAdjacente()
{
	vector<vector<int>> adjacente(_numeroVertices, vector<int>(_numeroVertices, 0));

	for (int j = 0; j < _numeroArestas; j++)
	{
		int origem = -1, destino = -1;
		for (int i = 0; i < _numeroVertices; i++)
		{
			if (_grafo[i][j] == 1) origem = i;
			if (_grafo[i][j] == -1) destino = i;
		}

		if (origem != -1 && destino != -1)
			adjacente[origem][destino] = 1;
	}

	cout << "Matriz de adjacencia:\n";

	for (int i = 0; i < _numeroVertices; i++)
	{
		cout << "\n";
		for (int j = 0; j < _numeroVertices; j++)                         
			cout << adjacente[i][j] << " ";
	}
	cout << "\n";

	return adjacente;
}
