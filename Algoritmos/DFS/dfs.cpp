#include <iostream>
#include <vector>
#include <stack>

using namespace std;

enum Estado { NoNaoVisitado, NoNaPilha, NoSaiudaPilha };

bool QuantidadeDeArestasEhInvalida(int numVertices, int numArestas, bool direcionado) {
    if (direcionado)
        return numArestas > numVertices * (numVertices - 1);
    
    return numArestas > (numVertices * (numVertices - 1)) / 2;
}

void DFS(int noInicial, vector<vector<int>>& grafo) {
    
    vector<bool> nosVisitados(grafo.size(), false);
    stack<int> pilha;
    pilha.push(noInicial);

    while (!pilha.empty()) {
        int noAtual = pilha.top();
        pilha.pop();

        if (!nosVisitados[noAtual]) {
            nosVisitados[noAtual] = true;
            cout << noAtual + 1 << " ";

            for (int vizinho : grafo[noAtual]) {
                if (!nosVisitados[vizinho]) {
                    pilha.push(vizinho);
                }
            }
        }
    }
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

bool VerificaSeHaUmCiclo(vector<vector<int>>& grafo, int noInicial) {
    vector<bool> nosVisitados(grafo.size(), false);
    stack<pair<int, int>> pilha;
    
    pilha.push({noInicial, -1});

    while (!pilha.empty()) {
        int noAtual = pilha.top().first;
        int noPai = pilha.top().second;

        pilha.pop();

        if (!nosVisitados[noAtual]) {
            nosVisitados[noAtual] = true;

            for (int vizinho : grafo[noAtual]) {
                if (!nosVisitados[vizinho]) {
                    pilha.push({vizinho, noAtual});
                } else if (vizinho != noPai) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool VerificaSeHaUmCicloDirecionado(vector<vector<int>>& grafo, int noInicial) {
    stack<int> pilha;
    pilha.push(noInicial);
    vector<Estado> estado(grafo.size(), NoNaoVisitado);

    while (!pilha.empty()) {
        int noAtual = pilha.top();

        if (estado[noAtual] == NoNaoVisitado) {
            estado[noAtual] = NoNaPilha; 
            
            for (int vizinho : grafo[noAtual]) {
                
                if (estado[vizinho] == NoNaoVisitado) {
                    pilha.push(vizinho);
                }

                if (estado[vizinho] == NoNaPilha) {
                    return true; 
                }

            }

        } else {
            
            estado[noAtual] = NoSaiudaPilha;
            pilha.pop();
        }
    }

    return false;
}

int main() {
    
    vector<vector<int>> grafoNaoDirecionado = LerListaAdjacencia();
    
    DFS(0, grafoNaoDirecionado);
    
    bool temCiclo = VerificaSeHaUmCiclo(grafoNaoDirecionado, 0);
    if (temCiclo)
        cout << "\nO grafo nao direcionado tem um ciclo." << endl;
    else
        cout << "\nO grafo nao tem um ciclo." << endl;
    
    vector<vector<int>> grafoDirecionado = LerListaAdjacencia(true);
    DFS(0, grafoDirecionado);
    
    bool temCiclo = VerificaSeHaUmCicloDirecionado(grafoDirecionado, 0);
    
    if (temCiclo)
        cout << "\nO grafo direcionado tem um ciclo." << endl;
    else
        cout << "\nO grafo direcionado nao tem um ciclo." << endl;
    return 0;
}