#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool TS(vector<vector<int>>& adj, vector<int>& inDegree) {
    int V = adj.size();
    queue<int> fila;

    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            fila.push(i);
        }
    }

    int count = 0;
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                fila.push(v);
            }
        }

        count++;
    }

    return count != V;
}

int main() {
    int V = 9;
    vector<vector<int>> adj(V);
    vector<int> inDegree(V, 0);

    adj[0] = { 1, 3 };
    adj[1] = { 2 };
    adj[2] = { 3, 4 };
    adj[3] = { 4 };
    adj[4] = { 5 };
    adj[5] = { 6 };
    adj[6] = { 7 };
    adj[7] = { 8 };

    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    cout << "Ordem topológica: ";
    if (TS(adj, inDegree)) {
        cout << "\nO grafo contém um ciclo!" << endl;
    }

    return 0;
}
