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
	cout << "Digite 4 para digitar 2 grafos e verificar isomorfismo\n";
	cout << "Digite 0 para sair\n";
	cout << "-----------------------------------------------\n";
	cout << "Opcao: ";
}


void VerificaIsomorfismo() {
	int numeroVertices;
	while (1) {
		cout << "Digite o numero de vertices dos grafos: ";
		cin >> numeroVertices;

		if (numeroVertices <= 0)
			cout << "Numero invalido! Digite novamente!\n";

		if (numeroVertices >= 1)
			break;
	}

	MatrizAdjacente grafoA(numeroVertices);
	MatrizAdjacente grafoB(numeroVertices);

	cout << "Inserindo elementos para o Grafo A:\n";
	grafoA.InserirElementos();
	while (!grafoA.VerificarSimetria()) {
		cout << "Grafo A nao eh simetrico. Digite os elementos novamente.\n";
		grafoA.InserirElementos();
	}

	cout << "Inserindo elementos para o Grafo B:\n";
	
	grafoB.InserirElementos();
	while (!grafoB.VerificarSimetria()) {
		cout << "Grafo B nao eh simetrico. Digite os elementos novamente.\n";
		grafoB.InserirElementos();
	}

	grafoA.ImprimeMatriz();
	grafoB.ImprimeMatriz();

	grafoA.ImprimeGrau();
	grafoB.ImprimeGrau();

	grafoA.VerificarCondicoesIsomorfismo(grafoB);
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
		if (opcao < 0 || opcao > 4 )
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

		if (opcao == 4)
		{
			
		}
		
	}
}
