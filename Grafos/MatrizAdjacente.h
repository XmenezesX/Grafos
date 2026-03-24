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
	bool VerificarCondicoesIsomorfismo(MatrizAdjacente& outroGrafo);
	void ClassificarGrafo();
	int GetNumeroVertices() const { return _numeroVertices; }
	vector<vector<int>> GetGrafo() const { return _grafo; }
private:
	void ResetaGrafo(){{ _grafo.assign(_numeroVertices, vector<int>(_numeroVertices, 0)); }};
	
	vector<vector<int>> _grafo;
	int _numeroVertices;
};

#endif 
