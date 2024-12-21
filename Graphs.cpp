#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include <queue>

using namespace std;

class Graph
{
private:
    int **AdjacencyMatrix;
    int Vertices;
    string *VertexValues;

public:
    Graph(int value) : Vertices(value)
    {
        AdjacencyMatrix = new int *[Vertices];

        for (int i = 0; i < Vertices; i++)
        {
            AdjacencyMatrix[i] = new int[Vertices];
            for (int j = 0; j < Vertices; j++)
            {
                AdjacencyMatrix[i][j] = 0;
            }
        }

        VertexValues = new string[Vertices];
    }

    ~Graph()
    {
        for (int i = 0; i < Vertices; i++)
        {
            delete[] AdjacencyMatrix[i];
        }
        delete[] AdjacencyMatrix;
        delete[] VertexValues;
    }

    void add_vertexValue(int Vertex, string value)
    {
        if (Vertex < 0 || Vertex >= Vertices)
        {
            cout << "Invalid vertex entered..." << endl;
            return;
        }
        VertexValues[Vertex] = value;
    }

    void addEdge(int v, int u, int weight)
    {
        if (v >= Vertices || u >= Vertices || v < 0 || u < 0)
        {
            cout << "Invalid vertices typed..." << endl;
            return;
        }
        AdjacencyMatrix[v][u] = weight;
        AdjacencyMatrix[u][v] = weight; // Assuming undirected graph
    }

    void display_Graph_2d_Matrix()
    {
        for (int i = 0; i < Vertices; i++)
        {
            for (int j = 0; j < Vertices; j++)
            {
                cout << AdjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void search_edge(int v, int u)
    {
        if (v >= Vertices || u >= Vertices || v < 0 || u < 0)
        {
            cout << "Invalid vertices typed..." << endl;
            return;
        }
        if (AdjacencyMatrix[v][u] != 0)
        {
            cout << "There exists an edge between " << v << " and " << u << endl;
            cout << "And the weight value is..." << AdjacencyMatrix[v][u] << endl;
        }
        else
        {
            cout << "There does not exist an edge between " << v << " and " << u << endl;
        }
    }

    void Breadth_first_search(int start)
    {
        if (start < 0 || start >= Vertices)
        {
            cout << "Invalid start vertex" << endl;
            return;
        }
        bool *visited = new bool[Vertices]();

        cout << "BFS:" << endl;
        visited[start] = true;

        queue<int> q;
        q.push(start);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << VertexValues[current] << " ";

            for (int i = 0; i < Vertices; i++)
            {
                if (AdjacencyMatrix[current][i] != 0 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
        delete[] visited;
    }

    void DFS_helper(int v, bool *visited)
    {
        visited[v] = true;
        cout << VertexValues[v] << " ";
        for (int i = 0; i < Vertices; i++)
        {
            if (AdjacencyMatrix[v][i] != 0 && !visited[i])
            {
                DFS_helper(i, visited);
            }
        }
    }

    void DFS(int start)
    {
        if (start < 0 || start >= Vertices)
        {
            cout << "Invalid start vertex" << endl;
            return;
        }
        bool *visited = new bool[Vertices]();
        cout << "DFS:" << endl;
        DFS_helper(start, visited);
        cout << endl;
        delete[] visited;
    }
};

#endif