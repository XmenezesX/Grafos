#include "MatrizAdjacente.h"
#include <iostream>
#include <algorithm>

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
	ResetaGrafo();
	int aresta;
	for (int i = 0; i < _numeroVertices; i++)
	{
		for (int j = 0; j < _numeroVertices; j++)
		{
			cout << "Digite o valor para a posicao [" << i << "][" << j << "] (0 ou 1): ";
			cin >> aresta; 
			
			while (aresta != 0 && aresta != 1)
			{
				cout << "Entrada invalida! Digite 0 ou 1: ";
				cin >> aresta;
			}

			_grafo[i][j] = aresta;
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


bool MatrizAdjacente::VerificarCondicoesIsomorfismo(MatrizAdjacente& outro) {

    if (_numeroVertices != outro.GetNumeroVertices()) {
        cout << "Falha: Numero de vertices diferente." << endl;
        return false;
    }

    vector<int> grausA(_numeroVertices, 0);
    vector<int> grausB(_numeroVertices, 0);
    int totalArestasA = 0;
    int totalArestasB = 0;

    for (int i = 0; i < _numeroVertices; i++) {
        for (int j = 0; j < _numeroVertices; j++) {
            if (_grafo[i][j] == 1) {
                grausA[i]++;
                totalArestasA++;
            }
        }
    }

    for (int i = 0; i < _numeroVertices; i++) {
        for (int j = 0; j < _numeroVertices; j++) {
            if (outro.GetGrafo()[i][j] == 1) {
                grausB[i]++;
                totalArestasB++;
            }
        }
    }

	int arestasA = totalArestasA / 2;
	int arestasB = totalArestasB / 2;
    if (arestasA != arestasB) {
        cout << "Falha: Numero de arestas diferente (" << arestasA << " vs " << arestasB << ")." << endl;
        return false;
    }

    sort(grausA.begin(), grausA.end());
    sort(grausB.begin(), grausB.end());

    for (int i = 0; i < _numeroVertices; i++) {
        if (grausA[i] != grausB[i]) {
            cout << "Falha: As sequencias de graus dos vertices nao coincidem." << endl;
            return false;
        }
    }

    cout << "Sucesso: Os grafos passam nos testes basicos de isomorfismo!" << endl;
    return true;
}
