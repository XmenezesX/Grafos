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

bool ehClique(vector<vector<int>>& grafo, vector<int>& conjuntoAtual) {
    int n = conjuntoAtual.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int u = conjuntoAtual[i];
            int v = conjuntoAtual[j];
           
            if (grafo[u][v] == 0)
                return false;
        }
    }
    return true;
}
 

bool possuiClique(vector<vector<int>>& grafo, int tamanhoMinimo = 3) {
    int n = grafo.size();
    if (n < tamanhoMinimo || tamanhoMinimo < 3) 
        return false;
    
    stack<pair<vector<int>, int>> pilha;
 
    pilha.push({{}, 0});
 
    while (!pilha.empty()) {
        pair<vector<int>, int> estado = pilha.top();
        vector<int> conjuntoAtual = estado.first;
        int proximo = estado.second;
        
        pilha.pop();
 
        if (conjuntoAtual.size() >= tamanhoMinimo && ehClique(grafo, conjuntoAtual))
            return true;
 
        for (int v = proximo; v < n; v++) {
            vector<int> novoSubconjunto = conjuntoAtual;
            novoSubconjunto.push_back(v);
 
            bool conectado = true;
            for (int u : conjuntoAtual) {
                if (grafo[u][v] == 0) {
                    conectado = false;
                    break;
                }
            }
 
            if (conectado) {
                pilha.push({novoSubconjunto, v + 1});
            }
        }
    }
 
    return false;
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

    if (possuiClique(grafo))
        cout << "O grafo possui clique" << endl;
    else
        cout << "O grafo nao possui clique" << endl;
    
    return 0;
}