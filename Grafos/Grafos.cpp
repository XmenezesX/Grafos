#include <iostream>
#include "MatrizAdjacente.h"
#include "MatrizIncidencia.h"
using namespace std;

void ImprimeMenu(){
	cout << "-----------------------------------------------\n";
	cout << "Digite 1 para algoritmo de Matriz de Adjacencia\n";
	cout << "Digite 2 para algoritmo de Matriz de Incidencia\n";
	cout << "Digite 0 para sair\n";
	cout << "-----------------------------------------------\n";
	cout << "Opcao: ";
}

void AlgoritmoMatrizAdjacencia() {
	int numeroVertices;
	while(1){
		cout << "Digite o numero de vertices da matriz de adjacencia: ";
		cin >> numeroVertices;

		if (numeroVertices <= 0)
			cout << "Numero invalido! Digite novamente!\n";
		
		if (numeroVertices >= 1)
			break;
	}

	MatrizAdjacente matriz(numeroVertices);
	matriz.InserirElementos();
	if(!matriz.VerificarSimetria());
	{
		cout << "Encerrando o programa....\n";
		return;
	}
	matriz.ImprimeMatriz();
	matriz.ImprimeGrau();
}

void AlgoritmoMatrizIncidencia() {
	int numeroVertices, numeroArestas;
	while (1) {
		cout << "Digite o numero de vertices da matriz de incidencia: ";
		cin >> numeroVertices;

		if (numeroVertices <= 0)
			cout << "Numero invalido! Digite novamente!\n";

		if (numeroVertices >= 1)
			break;
	}

	while (1) {
		cout << "Digite o numero de aresta da matriz de adjacencia: ";
		cin >> numeroArestas;

		if (numeroArestas <= 0)
			cout << "Numero invalido! Digite novamente!\n";

		if (numeroArestas >= 1)
			break;
	}

	MatrizIncidencia matriz(numeroVertices, numeroArestas);
	matriz.InserirElementos();
	matriz.ImprimeMatriz();
	matriz.ImprimeGrau();
	matriz.TranformaEmAdjacente();
}

int main()
{
	int opcao;

	while (1) {
		ImprimeMenu();
		cin >> opcao;
		if (opcao < 0 || opcao > 2)
			cout << "Opcao invalida! Digite novamente\n";
		
		if(opcao == 0){
			cout << "Encerrando o programa.......\n";
			break;
		}

		if (opcao == 1){
			AlgoritmoMatrizAdjacencia();
			cout << "Encerrando o programa.......\n";
			break;
		}

		if (opcao == 2) {
			AlgoritmoMatrizIncidencia();
			cout << "Encerrando o programa.......\n";
			break;
		}
	}
}
