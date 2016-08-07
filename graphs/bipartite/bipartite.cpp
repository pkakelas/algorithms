#include <cstdio>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

const int MAX_N = 1000000;

list<int> E[MAX_N];
int dist[MAX_N];
queue<int> Q;
bool won = true;

int main() {
    int n, m, u, v, length;
    freopen("bipartite.in", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        dist[i] = -1;
    }

    Q.push(0);
    dist[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (dist[i] != -1) {
            continue;
        }
        while (!Q.empty()) {
            u = Q.front();
            Q.pop();
            int gender = (dist[u] + 1) % 2;
            for (auto adj : E[u]) {
                if (dist[adj] == -1) {
                    dist[adj] = gender;
                    Q.push(adj);
                }
                else if (dist[adj] != gender) {
                    won = false;
                    break;
                }
            }
        }
    }

    if (won) {
        cout << "Straight" << endl;
    }
    else {
        cout << "Gay" << endl;
    }

    return 0;
}
