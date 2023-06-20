#include <iostream>
#include <list>
#include <queue>
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

    // Executa a busca em largura a partir do vértice de origem e exibe todos os caminhos até o vértice de destino
    void bfs(int source, int destination) {
        vector<bool> visited(numVertices, false);        // Vetor para controlar os vértices visitados
        vector<int> parent(numVertices, -1);             // Vetor para armazenar o pai de cada vértice no caminho
        vector<vector<int>> paths;                       // Vetor para armazenar todos os caminhos

        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();

            if (currentVertex == destination) {
                // Encontrou um caminho até o destino
                vector<int> path;
                int vertex = currentVertex;
                while (vertex != -1) {
                    path.push_back(vertex);
                    vertex = parent[vertex];
                }
                paths.push_back(path);
            }

            for (auto it = adjList[currentVertex].begin(); it != adjList[currentVertex].end(); ++it) {
                int adjacentVertex = *it;
                if (!visited[adjacentVertex]) {
                    q.push(adjacentVertex);
                    visited[adjacentVertex] = true;
                    parent[adjacentVertex] = currentVertex;
                }
            }
        }

        // Exibindo os caminhos encontrados
        cout << "Caminhos do vértice " << source << " ao vértice " << destination << ":" << endl;
        for (const auto& path : paths) {
            for (int i = path.size() - 1; i >= 0; --i) {
                cout << path[i];
                if (i != 0) {
                    cout << " -> ";
                }
            }
            cout << endl;
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

    // Executando a busca em largura e exibindo os caminhos do vértice 0 ao vértice 5
    g.bfs(0, 5);

    return 0;
}
