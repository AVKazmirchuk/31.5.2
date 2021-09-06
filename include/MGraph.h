#pragma once

#include <iostream>
#include <vector>
#include "../include/LGraph.h"

class MatrixGraph : public IGraph
{
private:
    void initial(const MatrixGraph& mg)
    {
        numberOfVertices = mg.numberOfVertices;
        g = mg.g;
    }
public:
    MatrixGraph() {}

    MatrixGraph(const MatrixGraph& mg)
    {
        initial(mg);
    }

    MatrixGraph& operator=(const MatrixGraph& mg)
    {
        if (this == &mg) return *this;
        initial(mg);
        return *this;
    }

    MatrixGraph(MatrixGraph* mg)
    {
        numberOfVertices = mg->numberOfVertices;
        g = mg->g;
    }

    MatrixGraph(ListGraph* lg);

    void input() override
    {
        while (true)
        {
            std::cout << "Enter the number of vertices: ";
            std::cin >> numberOfVertices;
            if (cinNoFail()) break;
            std::cout << "Invalid data!\n";
        }

        std::cout << "\nEnter the numbers of vertices connected by edges. To finish entering \n" <<
                  "enter a non-numeric character. Example:\n\n";

        std::cout << "1 2\n";
        std::cout << "2 4 2 5\n";
        std::cout << "3 1 3 4\n";
        std::cout << "4 1 4 3\n";
        std::cout << "q\n\n";

        int vertexNumber1, vertexNumber2;
        std::vector<int> tmp(numberOfVertices);

        for (int i{}; i < numberOfVertices; ++i)
            g.push_back(tmp);

        while (true)
        {
            std::cin >> vertexNumber1 >> vertexNumber2;
            if (!cinNoFail()) return;

            g[--vertexNumber1][--vertexNumber2] = 1;
        }
    }

    void output()
    {
        std::cout << "\nMatrix:\n";

        for (size_t j{}; j < g.size(); ++j)
        {
            for (size_t i{}; i < g[j].size(); ++i)
            {
                std::cout << g[j][i] << ' ';
            }

            std::cout << '\n';
        }
    }
};
