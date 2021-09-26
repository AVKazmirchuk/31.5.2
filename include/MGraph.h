#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>



class MatrixGraph : public IGraph
{
private:

    //Матрица смежности
    std::vector<std::vector<int>> g;

    //Функция инициализации графа списками смежности
    void init(const IGraph& lg);
public:
    MatrixGraph() {}

    MatrixGraph(const MatrixGraph& mg) : IGraph(mg)
    {
        g = mg.g;
    }

    MatrixGraph(MatrixGraph* mg) : IGraph(mg)
    {
        g = mg->g;
    }

    MatrixGraph& operator=(const MatrixGraph& mg)
    {
        if (this == &mg) return *this;

        g = mg.g;

        return *this;
    }

    MatrixGraph& operator=(const MatrixGraph* mg)
    {
        if (this == mg) return *this;

        g = mg->g;

        return *this;
    }

    MatrixGraph(IGraph* lg)
    {
        init(*lg);
    }

    MatrixGraph(IGraph& lg)
    {
        init(lg);
    }

    MatrixGraph& operator=(const IGraph& lg)
    {
        init(lg);

        return *this;
    }

    MatrixGraph& operator=(const IGraph* lg)
    {
        init(*lg);

        return *this;
    }

    virtual ~MatrixGraph() {}

    //Получение матрицы смежности
    const std::vector<std::vector<int>>& getG() const override
    {
        return g;
    }

    //Получение матрицы смежности
    std::vector<std::vector<int>>& getG() override
    {
        return g;
    }

    //Получение количества вершин
    const size_t VerticesCount() const override
    {
        return g.size();
    }

    //Функция построения матрицы смежности, если количество вершин заранее не известно
    void AddEdge(int from, int to) override;
private:

    //Если вершина не имеет петли - удалить
    void isLoop(std::vector<int>& visited, int vertex) const;
public:

    //Все вершины, в которые можно дойти из заданной
    void GetNextVertices(int vertex, std::vector<int>& nextVertices) const override;

    //Все вершины, из которых можно дойти в заданную
    void GetPrevVertices(int vertex, std::vector<int>& prevVertices) const override;

    //Вывод графа
    void output() const override;
};