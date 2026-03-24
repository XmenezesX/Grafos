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


void MatrizAdjacente::ClassificarGrafo() {
    
    vector<int> graus(_numeroVertices, 0);
    int totalArestas = 0;

    for (int i = 0; i < _numeroVertices; i++) {
        for (int j = 0; j < _numeroVertices; j++) {
            if (_grafo[i][j] == 1) {
                graus[i]++;
                totalArestas++;
            }
        }
    }
    
    // Como a matriz é simétrica, cada aresta foi contada duas vezes
    totalArestas = totalArestas / 2;

    bool ehCompleto = true;
    bool ehCiclo = true;
    int verticesGrau3 = 0;
    int centroRoda = -1;

    // 1. Verificação de Grafo Completo (Kn)
    // Todos os vértices devem ter grau n-1
    for (int g : graus) {
        
		if (g != _numeroVertices - 1) {
			ehCompleto = false;
		}

        if (g == 2){
            continue;
		}
		else{
			ehCiclo = false;
		}
    }

    if (ehCompleto) {
        cout << "O grafo e COMPLETO (K" << _numeroVertices << ")." << endl;
        return; 
    }

	// verifica ciclo
    if (ehCiclo && totalArestas == _numeroVertices) {
        cout << "O grafo e um CICLO (C" << _numeroVertices << ")." << endl;
        return;
    }

    // verifica roda
    // Um vértice (centro) tem grau n-1, e todos os outros (n-1 vértices) têm grau 3
    if (_numeroVertices >= 3) {
        int contaCentro = 0;
        int contaPeriferia = 0;
        for (int g : graus) {
            if (g == _numeroVertices - 1) contaCentro++;
            else if (g == 3) contaPeriferia++;
        }
        
        if (contaCentro == 1 && contaPeriferia == _numeroVertices - 1) {
            cout << "O grafo e uma RODA (W" << _numeroVertices << ")." << endl;
            return;
        }
    }

    cout << "O grafo nao se encaixa puramente em Completo, Ciclo ou Roda." << endl;
}