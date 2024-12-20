#include <iostream>
#include "Queues.cpp"

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
        AdjacencyMatrix[v][u] = weight; // bas yahan per jo bhi numerical value represent kerni hai wo yahan per typee kerni hai.....
        AdjacencyMatrix[u][v] = weight; // ager undirected graph hai
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
            cout << "And the weight value is..." << AdjacencyMatrix[v][u];
        }
        else
        {
            cout << "There does not exist an edge between " << v << " and " << u << endl;
        }
    }

    void search_vertex_with_value(string value)
    {
        for (int i = 0; i < Vertices; i++)
        {
            if (VertexValues[i] == value)
            {
                cout << "The vertex is found with position... " << i << "\n"
                     << endl;
                return;
            }
        }
        cout << "Vertex not found..." << endl;
        return;
    }

    void search_vertex_with_index_value(int Vertex)
    {
        if (Vertex >= Vertices || Vertex < 0)
        {
            cout << "Invalid vertex typed..." << endl;
            return;
        }
        if (VertexValues[Vertex] == "")
        {
            cout << "The vertex is deleted or empty..." << endl;
            return;
        }
        else
        {
            cout << "Vertex found with value..." << VertexValues[Vertex] << endl;
        }
    }

    void delete_vertex_by_value(string value)
    {
        int vertex_index_value = -1;

        for (int i = 0; i < Vertices; i++)
        {
            if (VertexValues[i] == value)
            {
                cout << "The vertex is found with position... " << i << "\nNow deleting.." << endl;
                vertex_index_value = i;
            }
        }

        if (vertex_index_value == -1)
        {
            cout << "No vertex found with value.. " << value << endl;
            return;
        }

        for (int j = 0; j < Vertices; j++)
        {
            AdjacencyMatrix[vertex_index_value][j] = 0; // Reseting all the egde connections
            AdjacencyMatrix[j][vertex_index_value] = 0;
        }
        VertexValues[vertex_index_value] = "";
        cout << "Vertex deleted" << endl;
    }

    void delete_vertex_by_index(int index_value)
    {
        if (index_value >= Vertices || index_value < 0)
        {
            cout << "Invalid vertex typed..." << endl;
            return;
        }
        for (int i = 0; i < Vertices; i++)
        {
            AdjacencyMatrix[index_value][i] = 0;
            AdjacencyMatrix[i][index_value] = 0;
        }
        VertexValues[index_value] = "";
        cout << "The vertex is deleted." << endl;
    }

    void delete_edge(int v, int u)
    {
        if (v >= Vertices || u >= Vertices || v < 0 || u < 0)
        {
            cout << "Invalid vertices typed..." << endl;
            return;
        }
        AdjacencyMatrix[v][u] = 0;
        AdjacencyMatrix[u][v] = 0;
        cout << "The edge between the vertices has been deleted..." << endl;
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

        CircularQueue q(start);
        q.EnQueue(start);

        while (!q.isEmpty())
        {
            int current = q.Front();

            q.DeQueue();

            cout << VertexValues[current] << " ";

            for (int i = 0; i < Vertices; i++)
            {
                if (AdjacencyMatrix[current][i] != 0 && !visited[i])
                {
                    visited[i] = true;
                    q.EnQueue(i);
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

// int main()
// {
//     int vertices = 7; // Example: Graph with 7 vertices
//     graph g(vertices);

//     // Set values for the vertices
//     g.add_vertexValue(0, "A");
//     g.add_vertexValue(1, "B");
//     g.add_vertexValue(2, "C");
//     g.add_vertexValue(3, "D");
//     g.add_vertexValue(4, "E");
//     g.add_vertexValue(5, "F");
//     g.add_vertexValue(6, "G");

//     // The most important part.
//     g.addEdge(0, 1, 4);
//     g.addEdge(2, 3, 5);
//     g.addEdge(1, 3, 2);
//     g.addEdge(1, 4, 3);
//     g.addEdge(4, 5, 6);
//     g.addEdge(5, 6, 7);
//     g.addEdge(6, 2, 8);

//     g.display_Graph_2d_Matrix();
//     cout << endl;
//     g.Breadth_first_search(3);
//     g.DFS(3);

//     g.search_vertex_with_index_value(3);
//     g.search_edge(1, 2);

//     g.delete_edge(1, 2);
//     g.delete_vertex_by_index(4);
//     g.delete_vertex_by_value("A");

//     g.display_Graph_2d_Matrix();

//     g.Breadth_first_search(3);
//     g.DFS(3);

//     return 0;
// }