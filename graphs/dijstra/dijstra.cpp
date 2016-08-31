#include <cstdio>
#include <algorithm>
#include <iostream>
#include <list>
#include <queue>


using namespace std;

int const MAX_N = 100;

list<int> E[MAX_N];
int state[MAX_N];

class MinHeap {
    public:
        priority_queue<int> q;

        void push(int value) {
            q.push(-value);
        };

        int pop() {
            int top = -q.top();
            q.pop();
            return top;
        }

        bool empty() {
            return q.empty();
        }

};

int main() {
    int n, m, u, v, s, t, w, w_max = 0;
    int dist[MAX_N];
    MinHeap pq;

    freopen("dijstra.in", "r", stdin);

    cin >> n >> m;
    cin >> s >> t;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        E[u].push_back(v);
        E[u].push_back(w);
        E[v].push_back(u);
        E[v].push_back(w);
        w_max = max(w, w_max);
    }

    for (int i = 0; i < MAX_N; ++i) {
        dist[i] = w_max;
    }

    dist[s] = 0;
    pq.push(s);
    while(!pq.empty()) {
        int current = pq.pop();
        cout << "Current: " << current << endl;
        cout << "Checking kids..." << endl;
        for (auto it = E[current].begin(); it != E[current].end(); ++it) {
            int node = *it;
            int weight = *++it;
            cout << "Node: " << node << ", state: " << state[node] << endl;
            if (state[node] == 0) {
                if (dist[node] > dist[current] + weight) {
                    cout << "dist[node]: " << dist[node] << ", dist[current]: " << dist[current] << ", weight: " << weight << endl;
                    cout << "dist[" << node << "]  = dist[" << current << "] + " << weight << endl;
                    dist[node] = dist[current] + weight;
                    pq.push(node);
                }
            }
        }
        if (current == t) {
            cout << "-------- Target found ---------" << endl;
            cout << "It's shortest path is: " << dist[current] << endl;
            break;
        }
        state[current] = 1;
        cout << "Done with current: " << current << endl;
        cout << "Set current's state to permanent (1)" << endl;
    }

    return 0;
}
