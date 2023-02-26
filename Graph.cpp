#include <iostream>
#include <queue>
#include <stack>
#include <list>
using namespace std;
class graph
{
    int V = 0, E = 0;
    list<int> *adjancencyList = NULL;

public:
    graph() {}
    graph(int V, int E)
    {
        this->V = V;
        this->E = E;
        adjancencyList = new list<int>[V];
    }
    void addEdge(bool b = false)
    {
        int v1 = 0, v2 = 0, M[V][V] = {};
        for (int i = 0; i < E; i++)
        {
            cout << "Enter The Vertices Connected With Edge : " << endl;
            cin >> v1 >> v2;
            adjancencyList[v1].push_back(v2);
            adjancencyList[v2].push_back(v1);
            M[v1][v2] = 1;
            M[v2][v1] = 1;
        }
        if (b)
        {
            cout << endl
                 << "\t";
            for (int i = 0; i < V; i++)
                cout << i << " ";
            cout << endl
                 << endl;
            for (int i = 0; i < V; i++)
            {
                cout << i << "\t";
                for (int j = 0; j < V; j++)
                    cout << M[i][j] << " ";
                cout << endl;
            }
        }
        else
            return;
    }
    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "The Adjancency Vertices of Vertex " << i << " is :" << endl
                 << "Head(" << i << ")";
            for (auto x : adjancencyList[i])
                cout << " -> " << x;
            cout << endl;
        }
    }
    void BFS(int node = 0)
    {
        bool visit[V] = {};
        queue<int> *q = new queue<int>;
        q->push(node);
        visit[node] = true;
        cout << "BFS :";
        while (!q->empty())
        {
            node = q->front();

            cout << " -> " << node;
            q->pop();

            for (auto x : adjancencyList[node])
            {
                if (!visit[x])
                {
                    visit[x] = true;
                    q->push(x);
                }
            }
        }
        cout << endl;
    }
    void DFS(int node = 0)
    {
        bool visit[V] = {};
        stack<int> *s = new stack<int>;
        s->push(node);
        visit[node] = true;
        cout << "DFS :";
        for (int i = 0; i < V; i++)
        {
            node = s->top();
            s->pop();
            cout << " -> " << node;
            for (auto x : adjancencyList[node])
            {
                if (!visit[x])
                {
                    s->push(x);
                    visit[x] = true;
                }
            }
        }
        cout << endl;
    }
};
int transform(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    for (int i = a - b; i <= 200; i++)
    {
        cout << i << endl;
    }
}
int main(int argc, char const *argv[])
{
    // graph *g = new graph(5, 7);
    // g->addEdge();
    // g->BFS(4);
    // g->DFS(2);
    transform(98, 25);
    return 0;
}
