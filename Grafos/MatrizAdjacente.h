#ifndef MATRIZ_ADJACENTE_H
#define MATRIZ_ADJACENTE_H

#include <vector>
using namespace std;

class MatrizAdjacente {
public:
	MatrizAdjacente(int numeroVertices);
	void InserirElementos();
	void ImprimeMatriz();
	void ImprimeGrau();
	bool VerificarSimetria();
private:
	vector<vector<int>> _grafo;
	int _numeroVertices;
};

#endif 
