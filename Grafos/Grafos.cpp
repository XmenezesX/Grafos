#include <iostream>
#include "MatrizAdjacente.h"
#include "MatrizIncidencia.h"
#include "ListaAdjacencia.h"
using namespace std;

void ImprimeMenu(){
	cout << "-----------------------------------------------\n";
	cout << "Digite 1 para algoritmo de Matriz de Adjacencia\n";
	cout << "Digite 2 para algoritmo de Matriz de Incidencia\n";
	cout << "Digite 3 para algoritmo de Lista\n";
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
	matriz.VerificarSimetria();
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

void AlgoritmoLista() {
	int numeroVertices;
	while (1) {
		cout << "Digite o numero de vertices da lista: ";
		cin >> numeroVertices;

		if (numeroVertices <= 0)
			cout << "Numero invalido! Digite novamente!\n";

		if (numeroVertices >= 1)
			break;
	}

	ListaAdjacencia listaAdjacente(numeroVertices);
	listaAdjacente.InserirElementos();
	listaAdjacente.ImprimirGrafo();

	cout << listaAdjacente.EhDirecionado();

}

int main()
{
	int opcao;

	while (1) {
		ImprimeMenu();
		cin >> opcao;
		if (opcao < 0 || opcao > 3 )
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

		if (opcao == 3) {
			AlgoritmoLista();
			cout << "Encerrando o programa.......\n";
			break;
		}
	}
}
