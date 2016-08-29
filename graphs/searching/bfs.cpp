#include <iostream>
#include <queue>
#include <list>

using namespace std;

const int MAX_N = 100;
int dist[MAX_N];

int main() {
    bool visited[MAX_N] = {false};
    int dist[MAX_N] = {0};
    list<int> E[MAX_N];
    queue<int> Q;
    int v, u, n, m, s, t;

    freopen("bfs.in", "r", stdin);

    cin >> n >> m;
    cin >> s >> t;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    bool done = false;
    Q.push(s);
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        if (t == node) {
            done = true;
            cout << "Distance: " << dist[node] << endl;
            break;
        }
        for (auto it = E[node].begin(); it != E[node].end(); ++it) {
            if (!visited[*it]) {
                if ((dist[*it] > dist[node] + 1) || dist[*it] == 0) {
                    dist[*it] = dist[node] + 1;
                }
                Q.push(*it);
            }
        }
        visited[node] = true;
    }

    if (done) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}
