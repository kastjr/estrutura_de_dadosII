#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Grafo {
    int V;
    list<int>* adj;

public:
    Grafo(int V);
    void adicionarAresta(int v, int w);
    void dfs(int v, vector<bool>& visitado, stack<int>& pilha);
    void topologicalSort(vector<string>& disciplinas);
};

Grafo::Grafo(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Grafo::adicionarAresta(int v, int w) {
    adj[v].push_back(w);
}

void Grafo::dfs(int v, vector<bool>& visitado, stack<int>& pilha) {
    visitado[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visitado[*i])
            dfs(*i, visitado, pilha);

    pilha.push(v);
}

void Grafo::topologicalSort(vector<string>& disciplinas) {
    stack<int> pilha;
    vector<bool> visitado(V, false);

    for (int i = 0; i < V; i++)
        if (visitado[i] == false)
            dfs(i, visitado, pilha);

    while (!pilha.empty()) {
        cout << disciplinas[pilha.top()] << " ";
        pilha.pop();
    }
}

int main() {
    int numVertices = 6;
    Grafo g(numVertices);

    vector<string> disciplinas = {
        "Arquitetura de Computadores",
        "Matemática Discreta",
        "Algoritmos",
        "Cálculo 1",
        "Linguagem de Programação",
        "Cálculo 2",
        "Programação Orientada a Objetos",
        "Estrutura de Dados",
        "Cálculo Numérico Computacional",
        "Banco de Dados"
    };

    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 3);
    g.adicionarAresta(1, 2);
    g.adicionarAresta(2, 3);
    g.adicionarAresta(2, 4);
    g.adicionarAresta(3, 4);
    g.adicionarAresta(4, 5);
    g.adicionarAresta(5, 6);
    g.adicionarAresta(6, 7);
    g.adicionarAresta(7, 8);

    cout << "Ordem das disciplinas que podem ser feitas no mesmo semestre:" << endl;
    g.topologicalSort(disciplinas);

    return 0;
}
