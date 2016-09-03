#include <cstdio>
#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <map>


using namespace std;

int const MAX_N = 100;

list<pair<int, int>> E[MAX_N];
bool state[MAX_N];

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int n, m, u, v, s, t, w, w_max = 0;
    int dist[MAX_N];

    freopen("dijstra.in", "r", stdin);

    cin >> n >> m;
    cin >> s >> t;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        E[u].push_back(make_pair(w, v));
        E[v].push_back(make_pair(w, u));
        w_max = max(w, w_max);
    }

    w_max = w_max * n;

    for (int i = 0; i < MAX_N; ++i) {
        dist[i] = w_max;
    }

    dist[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();
        cout << "Current: " << current.second << endl;
        cout << "Checking kids..." << endl;
        for (auto it : E[current.second]) {
            pair<int, int> node = it;
            cout << "Node: " << node.second << ", state: " << state[node.second] << endl;
            if (!state[node.second]) {
                if (dist[node.second] > dist[current.second] + node.first) {
                    cout << "dist[node]: " << dist[node.second] << ", dist[current]: " << dist[current.second] << ", weight: " << node.first << endl;
                    dist[node.second] = dist[current.second] + node.first;
                    cout << "dist[" << node.second << "]  = dist[" << current.second << "] + " << node.first << " = " << dist[node.second] << endl;
                    pq.push(node);
                }
            }
        }
        if (current.second == t) {
            cout << "-------- Target found ---------" << endl;
            cout << "It's shortest path is: " << dist[current.second] << endl;
            break;
        }
        state[current.second] = true;
        cout << "Done with current: " << current.second << endl;
        cout << "Set current's state to permanent (1)" << endl;
    }
    return 0;
}
