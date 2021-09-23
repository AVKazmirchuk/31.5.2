#include "IGraph.h"
#include "LGraph.h"
#include "MGraph.h"

//Функция инициализации графа списками смежности
void MatrixGraph::init(const IGraph& lg)
{
	g.clear();

	std::vector<int> tmp(lg.VerticesCount());

	for (size_t i{}; i < lg.VerticesCount(); ++i)
		g.push_back(tmp);

	for (size_t j{}; j < lg.VerticesCount(); ++j)
	{
		for (size_t i{}; i < lg.getG()[j].size(); ++i)
		{
			g[j][lg.getG()[j][i] - 1] = 1;
		}
	}
}

//Функция построения матрицы смежности, если количество вершин заранее не известно
void MatrixGraph::AddEdge(int from, int to)
{
	size_t numberOfVertices = VerticesCount();

	//Определить текущее количество вершин
	if (numberOfVertices < from || numberOfVertices < to)
		numberOfVertices = (from >= to ? from : to);

	std::vector<int> tmp(numberOfVertices);

	//Добавить строки по текущему количеству вершин 
	while (g.size() < numberOfVertices)
		g.push_back(tmp);

	//Заполнить предыдущие строки "0-ми" до текущего количества вершин
	for (size_t j{}; j < g.size() - 1; ++j)
		while (g[j].size() < numberOfVertices)
			g[j].push_back(0);

	//Если вершина несвязанная
	if (to == 0) return;

	g[from - 1][to - 1] = 1;
}

//Если вершина не имеет петли - удалить
void MatrixGraph::isLoop(std::vector<int>& vertices, int vertex) const
{
	if (!g[vertex - 1][vertex - 1])
	{
		std::swap(vertices.front(), vertices.back());
		vertices.pop_back();
	}
}

//Все вершины, в которые можно дойти из заданной
void MatrixGraph::GetNextVertices(int vertex, std::vector<int>& nextVertices) const
{
	nextVertices.clear();
	
	//Стандартный рекурсивный алгоритм (обход из начала в конец ребра)
	std::function<void(int)> dfs = [&](int vertex)
	{
		nextVertices.push_back(vertex);

		for (size_t i{}; i < VerticesCount(); ++i)
			//Если вершину не посещали - переход к следующей вершине
			if (g[vertex - 1][i] && std::find(nextVertices.begin(), nextVertices.end(), i + 1) == nextVertices.end())
				dfs(i + 1);
	};

	dfs(vertex);

	//Если вершина не имеет петли - удалить
	isLoop(nextVertices, vertex);

	std::sort(nextVertices.begin(), nextVertices.end());
}

//Все вершины, из которых можно дойти в заданную
void MatrixGraph::GetPrevVertices(int vertex, std::vector<int>& prevVertices) const
{
	prevVertices.clear();
	
	//Стандартный рекурсивный алгоритм (обход из конца в начало ребра)
	std::function<void(int)> dfs = [&](int vertex)
	{
		prevVertices.push_back(vertex);

		for (size_t i{}; i < VerticesCount(); ++i)
			//Если вершину не посещали - переход к следующей вершине
			if (g[i][vertex - 1] && std::find(prevVertices.begin(), prevVertices.end(), i + 1) == prevVertices.end())
				dfs(i + 1);
	};

	dfs(vertex);

	//Если вершина не имеет петли - удалить
	isLoop(prevVertices, vertex);

	std::sort(prevVertices.begin(), prevVertices.end());
}

//Вывод графа
void MatrixGraph::output() const
{
	std::cout << "\nMatrix:\n";

	for (size_t j{}; j < VerticesCount(); ++j)
	{
		for (size_t i{}; i < VerticesCount(); ++i)
		{
			std::cout << g[j][i] << ' ';
		}

		std::cout << '\n';
	}
}