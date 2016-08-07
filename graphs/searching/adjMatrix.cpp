#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
    private:
        int **matrix;
        int V;

    public:
        Graph(int V) {
            matrix = new int*[V];
            this->V = V;

            for (int i = 0; i < V; ++i) {
                matrix[i] = new int[4];
            }
        }

        void addEdge(int v1, int v2) {
            matrix[v1][v2] = 1;

            //If its bidirected
            //matrix[v2][v1] = 1;
        }

        void printGraph() {
            cout << "Adjacency matrix of vertex" << endl;
            for (int v1 = 0; v1 < V; ++v1) {
                for (int v2 = 0; v2 < V; ++v2) {
                    cout << " " << matrix[v1][v2] << " ";
                }
                cout<<endl;
            }
        }

        bool isConnected(int v1, int v2) {
            if (matrix[v1][v2] == 1) {
                return true;
            }
            return false;
        }

        void dfs(int s) {
            stack<int> stack;
            bool visited[V] = {false};
            stack.push(s);
            while (!stack.empty()) {
                int node = stack.top();
                stack.pop();
                if (visited[node] == false) {
                    visited[node] = true;
                    for (int i = 0; i < V; ++i) {
                        if (node != i && isConnected(node, i)) {
                            stack.push(i);
                        }
                    }
                }
            }

            for (int i = 0; i < V; ++i) {
                if (visited[i] == true) {
                    cout << i << endl;
                }
            }
        }

        void bfs(int s) {
            queue<int> queue;
            bool visited[V] = {false};
            queue.push(s);
            while (!queue.empty()) {
                int node = queue.front();
                queue.pop();
                //In case that the node isn't visited
                if (visited[node] == false) {
                    visited[node] = true;
                    for (int i = 0; i < V; ++i) {
                        if (node != i && isConnected(node, i)) {
                            queue.push(i);
                        }
                    }
                }
            }

            for (int i = 0; i < V; ++i) {
                if (visited[i] == true) {
                    cout << i << endl;
                }
            }
        }
};

int main() {
    Graph gh(5);

    gh.addEdge(0, 1);
    gh.addEdge(1, 4);
    gh.addEdge(1, 2);
    gh.addEdge(2, 3);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(4, 1);
    gh.addEdge(3, 4);

    gh.printGraph();

    gh.dfs(0);

    return 0;
}
