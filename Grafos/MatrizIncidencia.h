#ifndef MATRIZ_INCIDENCIA_H
#define MATRIZ_INCIDENCIA_H

#include <vector>
using namespace std;

class MatrizIncidencia {
public:
	MatrizIncidencia(int numeroVertices, int numeroAresta);
	void InserirElementos();
	void ImprimeMatriz();
	void ImprimeGrau();
	vector<vector<int>> TranformaEmAdjacente();
private:
	bool VerificarGrafoDirecionado();
	vector<vector<int>> _grafo;
	int _numeroVertices;
	int _numeroArestas;
};

#endif