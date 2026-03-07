#include "ListaAdjacencia.h"
#include <iostream>
#include <string>

ListaAdjacencia::ListaAdjacencia(int numeroVertices)
{
	_numeroVertice = numeroVertices;
	_grafo.resize(numeroVertices);
}

void ListaAdjacencia::InserirElementos()
{
	cout << "Digite as arestas no formato \"u v\" (vertices de 1 a " << _numeroVertice << "):" << endl;
	cout << "Caso tenha concluido a insercao digite -1" << endl;

	while(1) {
		int u, v;
		cin >> u;
		if (u == -1)
			break;

		cin >> v;
		u -= 1;
		v -= 1;

		while (u < 0 || u >= _numeroVertice || v < 0 || v >= _numeroVertice) {
			cout << "Aresta invalida, digite novamente." << endl;
			cin >> u >> v;
		}

		_grafo[u].push_back(v);
	}
}

string ListaAdjacencia::EhDirecionado()
{
	for (int u = 0; u < _numeroVertice; ++u) {
		for (int v : _grafo[u]) {
			vector<int> vizinhosDeV = _grafo[v];
			if (find(vizinhosDeV.begin(), vizinhosDeV.end(), u) == vizinhosDeV.end()) {
				return "Eh direcionado!";
			}
		}
	}
	return "Nao eh direcionado!";
}

void ListaAdjacencia::ImprimirGrafo()
{
	cout << "Impressao da Lista\n";
	for (int i = 0; i < _numeroVertice; ++i) {
		cout << "Vertice " << i + 1<< ":";
		for (int verticeAdjacente : _grafo[i]) {
			cout << " -> " << verticeAdjacente + 1;
		}
		cout << endl;
	}
	vector<vector<int>> matrizAdjacente = GeraMatrizAdjacente();
	cout << "Impressao da Matriz de Adjacencia\n";
	for (int i = 0; i < _numeroVertice; ++i) {
		for (int verticeAdjacente : matrizAdjacente[i]) {
			cout << verticeAdjacente << " ";
		}
		cout << endl;
	}

}

vector<vector<int>> ListaAdjacencia::GeraMatrizAdjacente()
{
	vector<vector<int>> matrizAdjacente(_numeroVertice, vector<int>(_numeroVertice, 0));
	for (int i = 0; i < _numeroVertice; ++i) {
		for (int verticeAdjacente : _grafo[i]) {
			matrizAdjacente[i][verticeAdjacente] = 1;
		}
	}
	return matrizAdjacente;
}
