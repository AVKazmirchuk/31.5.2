#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>



class ListGraph : public IGraph
{
private:

    //Списки смежности
    std::vector<std::vector<int>> g;

    //Функция инициализации графа матрицей смежности
    void init(const IGraph& mg);
public:
    ListGraph() {}

    ListGraph(const ListGraph& lg) : IGraph(lg)
    {
        g = lg.g;
    }

    ListGraph(ListGraph* lg) : IGraph(lg)
    {
        g = lg->g;
    }

    ListGraph& operator=(const ListGraph& lg)
    {
        if (this == &lg) return *this;

        g = lg.g;

        return *this;
    }

    ListGraph& operator=(ListGraph* lg)
    {
        if (this == lg) return *this;

        g = lg->g;

        return *this;
    }

    ListGraph(IGraph* mg)
    {
        init(*mg);
    }

    ListGraph(IGraph& mg)
    {
        init(mg);
    }

    ListGraph& operator=(const IGraph& mg)
    {
        init(mg);

        return *this;
    }

    ListGraph& operator=(const IGraph* mg)
    {
        init(*mg);

        return *this;
    }

    virtual ~ListGraph() {}

    //Получение списков смежности
    const std::vector<std::vector<int>>& getG() const override
    {
        return g;
    }

    //Получение списков смежности
    std::vector<std::vector<int>>& getG() override
    {
        return g;
    }

    //Получение количества вершин
    const size_t VerticesCount() const override
    {
        return g.size();
    }

    //Функция построения списков смежности, если количество вершин заранее не известно
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