#include "IGraph.h"
#include "LGraph.h"
#include "MGraph.h"

//������� ������������� ����� �������� ���������
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

//������� ���������� ������� ���������, ���� ���������� ������ ������� �� ��������
void MatrixGraph::AddEdge(int from, int to)
{
	size_t numberOfVertices = VerticesCount();

	//���������� ������� ���������� ������
	if (numberOfVertices < from || numberOfVertices < to)
		numberOfVertices = (from >= to ? from : to);

	std::vector<int> tmp(numberOfVertices);

	//�������� ������ �� �������� ���������� ������ 
	while (g.size() < numberOfVertices)
		g.push_back(tmp);

	//��������� ���������� ������ "0-��" �� �������� ���������� ������
	for (size_t j{}; j < g.size() - 1; ++j)
		while (g[j].size() < numberOfVertices)
			g[j].push_back(0);

	//���� ������� �����������
	if (to == 0) return;

	g[from - 1][to - 1] = 1;
}

//���� ������� �� ����� ����� - �������
void MatrixGraph::isLoop(std::vector<int>& vertices, int vertex) const
{
	if (!g[vertex - 1][vertex - 1])
	{
		std::swap(vertices.front(), vertices.back());
		vertices.pop_back();
	}
}

//��� �������, � ������� ����� ����� �� ��������
void MatrixGraph::GetNextVertices(int vertex, std::vector<int>& nextVertices) const
{
	nextVertices.clear();
	
	//����������� ����������� �������� (����� �� ������ � ����� �����)
	std::function<void(int)> dfs = [&](int vertex)
	{
		nextVertices.push_back(vertex);

		for (size_t i{}; i < VerticesCount(); ++i)
			//���� ������� �� �������� - ������� � ��������� �������
			if (g[vertex - 1][i] && std::find(nextVertices.begin(), nextVertices.end(), i + 1) == nextVertices.end())
				dfs(i + 1);
	};

	dfs(vertex);

	//���� ������� �� ����� ����� - �������
	isLoop(nextVertices, vertex);

	std::sort(nextVertices.begin(), nextVertices.end());
}

//��� �������, �� ������� ����� ����� � ��������
void MatrixGraph::GetPrevVertices(int vertex, std::vector<int>& prevVertices) const
{
	prevVertices.clear();
	
	//����������� ����������� �������� (����� �� ����� � ������ �����)
	std::function<void(int)> dfs = [&](int vertex)
	{
		prevVertices.push_back(vertex);

		for (size_t i{}; i < VerticesCount(); ++i)
			//���� ������� �� �������� - ������� � ��������� �������
			if (g[i][vertex - 1] && std::find(prevVertices.begin(), prevVertices.end(), i + 1) == prevVertices.end())
				dfs(i + 1);
	};

	dfs(vertex);

	//���� ������� �� ����� ����� - �������
	isLoop(prevVertices, vertex);

	std::sort(prevVertices.begin(), prevVertices.end());
}

//����� �����
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