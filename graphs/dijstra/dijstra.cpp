#include <cstdio>
#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <map>


using namespace std;

int const MAX_N = 100;

template<class T1>
class Pair {
public:
    T1 id;
    T1 weight;

    Pair(T1 id, T1 weight) : id(id), weight(weight) {}
};

class PairCompare {
    public:
        bool operator() (const Pair<int> &t1, const Pair<int> &t2) const {
            return t1.weight > t2.weight;
        }
};


list<Pair<int>> E[MAX_N];
int state[MAX_N];

int main() {
    priority_queue<Pair<int>, vector<Pair<int>>, PairCompare> pq;

	pq.push(Pair<int>(1, 6));
    pq.push(Pair<int>(2, 5));
    pq.push(Pair<int>(3, 4));

    int n, m, u, v, s, t, w, w_max = 0;
    int dist[MAX_N];

    freopen("dijstra.in", "r", stdin);

    cin >> n >> m;
    cin >> s >> t;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        E[u].push_back(Pair<int>(v, w));
        E[v].push_back(Pair<int>(u, w));
        w_max = max(w, w_max);
    }

    for (int i = 0; i < MAX_N; ++i) {
        dist[i] = w_max;
    }

    dist[s] = 0;
	pq.push(Pair<int>(s, 0));
    while(!pq.empty()) {
        Pair<int> current = pq.top();
		pq.pop();
        cout << "Current: " << current.id << endl;
        cout << "Checking kids..." << endl;
        for (auto it = E[current.id].begin(); it != E[current.id].end(); ++it) {
            Pair<int> node = *it;
            cout << "Node: " << node.id << ", state: " << state[node.id] << endl;
            if (state[node.id] == 0) {
                if (dist[node.id] > dist[current.id] + node.weight) {
                    cout << "dist[node]: " << dist[node.id] << ", dist[current]: " << dist[current.id] << ", weight: " << node.weight << endl;
                    dist[node.id] = dist[current.id] + node.weight;
                    cout << "dist[" << node.id << "]  = dist[" << current.id << "] + " << node.weight << " = " << dist[node.id] << endl;
                    pq.push(node);
                }
            }
        }
        if (current.id == t) {
            cout << "-------- Target found ---------" << endl;
            cout << "It's shortest path is: " << dist[current.id] << endl;
            break;
        }
        state[current.id] = 1;
        cout << "Done with current: " << current.id << endl;
        cout << "Set current's state to permanent (1)" << endl;
    }
    return 0;
}
