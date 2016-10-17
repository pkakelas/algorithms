#include <iostream>

using namespace std;

int main() {
    int n, m, s, t, w, sum = 0;
    freopen("floydWarshall.in", "r", stdin);
    cin >> n >> m;
    cout << "Number of nodes: " << n << endl;
    cout << "Number of edges: " << m << endl;

    int** G = new int*[n];
    int** dist = new int*[n];
    for(int i = 0; i < n; ++i) {
        G[i] = new int[n];
        dist[i] = new int[n];
    }

    while (cin >> s >> t >> w) {
        G[s - 1][t - 1] = w;
        //Find the maximum weight of a path
        sum += w;
    }

    cout << "Matrix created from file:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else if (G[i][j] != 0) {
                dist[i][j] = G[i][j];
            }
            else {
                dist[i][j] = sum;
            }
        }
    }


    cout << "Distance maxtrix generated" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Floyd Warshall finished: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
