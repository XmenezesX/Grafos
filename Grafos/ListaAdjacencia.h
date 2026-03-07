#ifndef LISTA_ADJACENCIA_H
#define LISTA_ADJACENCIA_H

#include <vector>
#include <string>
using namespace std;

class ListaAdjacencia
{
public:
	ListaAdjacencia(int numeroVertices);
	string EhDirecionado();
	void InserirElementos();
	void ImprimirGrafo();
private:
	int _numeroVertice;
	vector<vector<int>> _grafo;
	vector<vector<int>> GeraMatrizAdjacente();
};

#endif