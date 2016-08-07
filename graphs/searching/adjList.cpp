#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct AdjList {
    struct AdjListNode *head;
};

struct AdjListNode {
    int value;
    struct AdjListNode* next;
};

class Graph {
    private:
        int V;
        struct AdjList* array;

    public:
        Graph(int V) {
            this->V = V;
            array = new AdjList[V];
            for (int i = 0; i < V; ++i) {
                array[i].head = NULL;
			}
        }

        AdjListNode* newAdjListNode(int value) {
            AdjListNode* newNode = new AdjListNode;
            newNode->value = value;
            newNode->next = NULL;
            return newNode;
        }

        void addEdge(int v1, int v2) {
            AdjListNode* newNode = newAdjListNode(v2);
            newNode->next = array[v1].head;
            array[v1].head = newNode;

			//In case that the graph is undirected
            newNode = newAdjListNode(v1);
            newNode->next = array[v2].head;
            array[v2].head = newNode;
        }

        void printGraph() {
            int v;
            for (v = 0; v < V; ++v) {
                AdjListNode* list = array[v].head;
                cout << "\n Adjacency list of vertex " << v << "\n head";
                while (list) {
                    cout << " -> " << list->value;
                    list = list->next;
                }

                cout<<endl;
            }
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
                    AdjListNode* list = array[node].head;
                    while (list) {
                        stack.push(list->value);
                        list = list->next;
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
                if (visited[node] == false) {
                    visited[node] = true;
                    AdjListNode* list = array[node].head;
                    while (list) {
                        queue.push(list->value);
                        list = list->next;
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
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);

    gh.printGraph();

    gh.dfs(0);

    return 0;
}
