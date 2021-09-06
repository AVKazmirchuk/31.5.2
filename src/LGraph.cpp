#include "../include/IGraph.h"
#include "../include/lGraph.h"

ListGraph::ListGraph(MatrixGraph* mg)
{
    numberOfVertices = mg->numberOfVertices;

    std::vector<int> tmp;
    for (int j{}; j < mg->numberOfVertices; ++j)
    {
        for (int i{}; i < mg->numberOfVertices; ++i)
        {
            if (mg->g[j][i] == 1) tmp.push_back(i + 1);
        }

        g.push_back(tmp);
        tmp.clear();
    }
}