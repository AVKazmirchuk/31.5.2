#pragma once

#include <iostream>
#include <vector>
#include "../include/MGraph.h"


class ListGraph : public IGraph
{
private:
    void initial(const ListGraph& lg)
    {
        numberOfVertices = lg.numberOfVertices;
        g = lg.g;
    }
public:
    ListGraph() {}

    ListGraph(const ListGraph& lg)
    {
        initial(lg);
    }

    ListGraph& operator=(const ListGraph& lg)
    {
        if (this == &lg) return *this;
        initial(lg);
        return *this;
    }

    ListGraph(ListGraph* lg)
    {
        numberOfVertices = lg->numberOfVertices;
        g = lg->g;
    }

    ListGraph(MatrixGraph* mg);


    void input() override
    {
        std::cout << "\nEnter the vertex numbers of the graph. To finish entering \n" <<
                  "an array of lists, enter a non-numeric character. Example:\n\n";

        std::cout << "2\n";
        std::cout << "4 5\n";
        std::cout << "1 4\n";
        std::cout << "1 3\n";
        std::cout << "q\n\n";

        int number;
        std::vector<int> tmp;

        for (int j{}; ; ++j)
        {
            g.push_back(tmp);
            ++numberOfVertices;
            std::cout << "g[" << j + 1 << "]: ";

            char ch{};
            while (true)
            {
                do {
                    std::cin.get(ch);
                } while (ch == ' ' || ch == '\t');

                if (ch == '\n') break;

                std::cin.unget();

                std::cin >> number;
                if (!cinNoFail()) return;

                g[j].push_back(number);
            }

            tmp.clear();
        }
    }

    void output()
    {
        std::cout << "\nList:\n";

        for (size_t j{}; j < g.size(); ++j)
        {
            std::cout << "g[" << j + 1 << "]: ";

            for (size_t i{}; i < g[j].size(); ++i)
            {
                std::cout << g[j][i] << ' ';
            }

            std::cout << '\n';
        }
    }

};

