#ifndef GRAPHS_H
#define GRAPHS_H

#include <string>

class Graph
{
private:
    int **AdjacencyMatrix;
    int Vertices;
    std::string *VertexValues;

    void DFS_helper(int v, bool *visited);

public:
    Graph(int value);

    ~Graph();

    void add_vertexValue(int Vertex, std::string value);

    void addEdge(int v, int u, int weight);

    void display_Graph_2d_Matrix();

    void search_edge(int v, int u);

    void Breadth_first_search(int start);

    void DFS(int start);
};

#endif // GRAPHS_H
