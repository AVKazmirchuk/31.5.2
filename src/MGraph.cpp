#include "../include/IGraph.h"
#include "../include/lGraph.h"
#include "../include/MGraph.h"

MatrixGraph::MatrixGraph(ListGraph* lg)
{
    numberOfVertices = lg->numberOfVertices;

    std::vector<int> tmp(lg->numberOfVertices);

    for (int i{}; i < lg->numberOfVertices; ++i)
        g.push_back(tmp);

    for (int j{}; j < lg->numberOfVertices; ++j)
    {
        for (int i{}; i < lg->g[j].size(); ++i)
        {
            g[j][lg->g[j][i]] = 1;
        }
    }
}