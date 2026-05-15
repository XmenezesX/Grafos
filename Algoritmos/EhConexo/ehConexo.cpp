#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool QuantidadeDeArestasEhInvalida(int numVertices, int numArestas) {
    return numArestas > (numVertices * (numVertices - 1)) / 2;
}

vector<vector<int>> LerMatrizAdjacencia() {
    int numVertices, numArestas;
    cout << "Digite o numero de vertices e arestas do grafo: ";
    cin >> numVertices >> numArestas;

    while (numVertices <= 0 || numArestas < 0 || QuantidadeDeArestasEhInvalida(numVertices, numArestas))
    {
        if (numVertices <= 0)
            cout << "Numero de vertices deve ser positivo\n";

        if (numArestas < 0)
            cout << "Numero de arestas nao pode ser negativo\n";

        if (QuantidadeDeArestasEhInvalida(numVertices, numArestas))
            cout << "Numero de arestas excede o limite para o numero de vertices\n";

        cin >> numVertices >> numArestas;
    }

    vector<vector<int>> matriz(numVertices, vector<int>(numVertices, 0));

    for (int i = 0; i < numArestas; ++i) {
        int verticeOrigem, verticeDestino; 

        cout << "Digite os vertices de origem e destino da aresta (1 a " << numVertices  << "): ";
         
        cin >> verticeOrigem >> verticeDestino;
        verticeOrigem -= 1;
        verticeDestino -= 1;

        while (verticeOrigem < 0 || verticeOrigem >= numVertices || verticeDestino < 0 || verticeDestino >= numVertices)
        {
            cout << "Vertices invalidos. Por favor, insira novamente." << endl;
            cin >> verticeOrigem >> verticeDestino;
            verticeOrigem -= 1;
            verticeDestino -= 1;
        }

        matriz[verticeOrigem][verticeDestino] = 1;
        matriz[verticeDestino][verticeOrigem] = 1;
    }

    return matriz;
}

bool ehConexo(int N, vector<vector<int>>& matrizEntrada) {
    if (N == 1)
        return true;

    vector<vector<int>> somatoria = matrizEntrada;
    vector<vector<int>> potenciaAtual = matrizEntrada;

    for (int k = 1; k < N - 1; k++) {
        
        vector<vector<int>> armazenaMultiplicacao(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int m = 0; m < N; m++) {
                    armazenaMultiplicacao[i][j] += potenciaAtual[i][m] * matrizEntrada[m][j];
                }
            }
        }

        potenciaAtual = armazenaMultiplicacao;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                somatoria[i][j] += potenciaAtual[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                if (somatoria[i][j] == 0) {
                    return false; 
                }
            }
        }
    }

    return true;
}

int main(){
    vector<vector<int>> grafo = //LerMatrizAdjacencia();
    {
        {0,1,0,0,1,0},
        {1,0,1,1,1,1},
        {0,1,0,0,1,1},
        {0,1,0,0,0,1},
        {1,1,1,0,0,1},
        {0,1,1,1,1,0},
    };

    if (ehConexo(grafo.size(), grafo))
        cout << "O grafo eh conexo" << endl;
    else
        cout << "O grafo nao eh conexo" << endl;
    
    return 0;
}