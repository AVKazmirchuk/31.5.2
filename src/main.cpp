#include <iostream>
#include <vector>

#include "../include/header.h"


#include "IGraph.h"
#include "MGraph.h"
#include "LGraph.h"

bool cinNoFail()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}

void input(IGraph* ig)
{
    std::cout << "\nEnter the numbers of vertices connected by edges (0 - the vertex is not connected).\n" <<
              "To finish entering, enter a non-numeric character. Example:\n\n";

    //Вершины 5 и 8 намеренно не вводятся, алгоритм вычислит
    std::cout << "1 5\n";
    std::cout << "2 3\n";
    std::cout << "3 6 3 8\n";
    std::cout << "4 2 4 6\n";
    std::cout << "6 2 6 4 6 6\n";
    std::cout << "7 7\n";
    std::cout << "9 0\n";
    std::cout << "q\n\n";

    int vertexNumber1, vertexNumber2;
    while (true)
    {
        std::cin >> vertexNumber1 >> vertexNumber2;
        if (!cinNoFail()) return;

        if (vertexNumber1 <= 0 || vertexNumber2 < 0)
        {
            std::cout << "\nInvalid data!\n";
            continue;
        }

        ig->AddEdge(vertexNumber1, vertexNumber2);
    }
}

void test(IGraph& ig)
{
    std::vector<int> nextVertices;

    for (size_t i{}; i < ig.VerticesCount(); ++i)
    {
        ig.GetNextVertices(i + 1, nextVertices);

        std::cout << "\n\nNext vertices for " << i + 1 << " vertex: ";

        for (auto vertex : nextVertices)
            std::cout << vertex << ' ';
    }

    std::vector<int> prevVertices;

    for (size_t i{}; i < ig.VerticesCount(); ++i)
    {
        ig.GetPrevVertices(i + 1, prevVertices);

        std::cout << "\n\nPrevious vertices for " << i + 1 << " vertex: ";

        for (auto vertex : prevVertices)
            std::cout << vertex << ' ';
    }
}

int main()
{
    {
        ListGraph lg;

        input(&lg);

        MatrixGraph mg(lg);

        lg.output();
        mg.output();

        test(lg);
        test(mg);
    }

    {
        MatrixGraph mg;

        input(&mg);

        ListGraph lg(mg);

        mg.output();
        lg.output();

        test(mg);
        test(lg);
    }

    //Ниже, два теста проверки конструкторов для разных представлений графов и
    //получения последующих и предыдущих вершин

    /*ListGraph lg;

    lg.getG() = { {5}, {3}, {6, 8}, {2, 6}, {}, {2, 4, 6}, {7}, {}, {} };

    lg.output();

    ListGraph lg2 = lg;
    lg2.output();

    ListGraph lg3 = &lg;
    lg3.output();

    ListGraph lg4, lg5, lg6;
    lg4 = lg5 = &lg;
    lg4.output();
    lg5.output();

    MatrixGraph mg(lg);
    lg6 = mg;
    lg6.output();

    ListGraph lg7(&mg);
    lg7.output();

    ListGraph lg8(mg);
    lg8.output();

    lg6 = &mg;
    lg6.output();

    mg.output();

    test(lg);*/

    //------------------------------

    /*MatrixGraph mg;

    mg.getG() = {
        {0,0,0,0,1,0,0,0,0},
        {0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,1,0},
        {0,1,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,1,0,0,0},
        {0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0} };

    mg.output();

    MatrixGraph mg2 = mg;
    mg2.output();

    MatrixGraph mg3 = &mg;
    mg3.output();

    MatrixGraph mg4, mg5, mg6;
    mg4 = mg5 = &mg;
    mg4.output();
    mg5.output();

    ListGraph lg(mg);
    mg6 = lg;
    mg6.output();

    MatrixGraph mg7(&lg);
    mg7.output();

    MatrixGraph mg8(lg);
    mg8.output();

    mg6 = &lg;
    mg6.output();

    lg.output();

    test(mg);*/
}