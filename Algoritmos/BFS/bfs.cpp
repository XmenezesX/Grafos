#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool QuantidadeDeArestasEhInvalida(int numVertices, int numArestas, bool direcionado) {
    if (direcionado)
        return numArestas > numVertices * (numVertices - 1);
    
    return numArestas > (numVertices * (numVertices - 1)) / 2;
}

vector<vector<int>> LerListaAdjacencia(bool direcionado = false) {

    if(direcionado)
        cout << "Grafo direcionado:\n";
    else
        cout << "Grafo nao direcionado:\n";
    
    int numVertices, numArestas;
    cout << "Digite o numero de vertices e arestas do grafo: ";
    cin >> numVertices >> numArestas;

    while (numVertices <= 0 || numArestas < 0 || QuantidadeDeArestasEhInvalida(numVertices, numArestas, direcionado))
    {
        if (numVertices <= 0)
            cout << "Numero de vertices deve ser positivo\n";

        if (numArestas < 0)
            cout << "Numero de arestas nao pode ser negativo\n";

        if (QuantidadeDeArestasEhInvalida(numVertices, numArestas, direcionado))
            cout << "Numero de arestas excede o limite para o numero de vertices\n";

        cin >> numVertices >> numArestas;
    }

    vector<vector<int>> grafo(numVertices);
    for (int i = 0; i < numArestas; ++i) {
        int verticeOrigem, verticeDestino; 

        cout << "Digite os vertices de origem e destino da aresta (1 a " << numVertices  << "): ";
         
        cin >> verticeOrigem >> verticeDestino;
        verticeOrigem -=1;
        verticeDestino -=1;

        while (verticeOrigem < 0 || verticeOrigem >= numVertices || verticeDestino < 0 || verticeDestino >= numVertices)
        {
            cout << "Vertices invalidos. Por favor, insira novamente." << endl;
            cin >> verticeOrigem >> verticeDestino;
        }

        grafo[verticeOrigem].push_back(verticeDestino);
    
        if (!direcionado)
            grafo[verticeDestino].push_back(verticeOrigem);
    }

    return grafo;
}

vector<int> BFS(int noInicial, vector<vector<int>>& grafo) {
    vector<int> distancia(grafo.size(), -1);
    queue<int> fila;

    fila.push(noInicial);
    distancia[noInicial] = 0;

    while (!fila.empty()) {
        int noAtual = fila.front();
        fila.pop();
        
        cout << noAtual + 1 << " "; 
        for (int vizinho : grafo[noAtual]) {
            if (distancia[vizinho] == -1) {
                fila.push(vizinho);
                distancia[vizinho] = distancia[noAtual] + 1;
            }
        }
    }

    cout << endl;
    return distancia;
}


int main (){
    vector<vector<int>> grafo = {  // LerListaAdjacencia();
        {1,2,3,5},
        {0,2,3},
        {0,1,3},
        {0,1,2,4,5},
        {3,5},
        {0,3,4}   
    };
   
    int noInicial;
    
    cout << "Digite o vertice inicial para a busca em largura: ";
    cin >> noInicial;
    
    noInicial -= 1;
    
    vector<int> distancia = BFS(noInicial, grafo);

    cout << "\n\nDistancias a partir do vertice " << noInicial + 1 << ":" << endl;
    for (int i = 0; i < distancia.size(); i++) {
        cout << "Para o vertice " << i + 1 << " -> " << distancia[i] << " aresta(s)" << endl;
    }
    
    return 0;
}