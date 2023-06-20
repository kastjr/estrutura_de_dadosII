#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Graph {
private:
    int numVertices;             // Número de vértices no grafo
    list<int>* adjList;          // Vetor de listas ligadas para representar as arestas

public:
    // Construtor
    Graph(int V) {
        numVertices = V;
        adjList = new list<int>[V];
    }

    // Adiciona uma aresta entre os vértices v1 e v2
    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    // Executa a busca em profundidade a partir do vértice de origem
    void dfs(int source) {
        vector<bool> visited(numVertices, false);        // Vetor para controlar os vértices visitados

        stack<int> s;
        s.push(source);
        visited[source] = true;

        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();

            cout << currentVertex << " ";

            for (auto it = adjList[currentVertex].begin(); it != adjList[currentVertex].end(); ++it) {
                int adjacentVertex = *it;
                if (!visited[adjacentVertex]) {
                    s.push(adjacentVertex);
                    visited[adjacentVertex] = true;
                }
            }
        }
    }
};

int main() {
    // Criação do grafo com 6 vértices
    Graph g(6);

    // Adição das arestas
    g.addEdge(0, 2);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // Executando a busca em profundidade a partir do vértice 0
    cout << "Busca em Profundidade (DFS): ";
    g.dfs(0);
    cout << endl;

    return 0;
}
