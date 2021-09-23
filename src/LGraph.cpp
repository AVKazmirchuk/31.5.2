#include "IGraph.h"
#include "LGraph.h"
#include "MGraph.h"

//������� ������������� ����� �������� ���������
void ListGraph::init(const IGraph& mg)
{
	g.clear();

	std::vector<int> tmp;

	for (size_t j{}; j < mg.VerticesCount(); ++j)
	{
		for (size_t i{}; i < mg.VerticesCount(); ++i)
		{
			if (mg.getG()[j][i]) tmp.push_back(i + 1);
		}

		g.push_back(tmp);
		tmp.clear();
	}
}

//������� ���������� ������� ���������, ���� ���������� ������ ������� �� ��������
void ListGraph::AddEdge(int from, int to)
{
	size_t numberOfVertices = VerticesCount();

	//���������� ������� ���������� ������
	if (numberOfVertices < from || numberOfVertices < to)
		numberOfVertices = (from >= to ? from : to);

	std::vector<int> tmp;

	//�������� ������ �� �������� ���������� ������ 
	while (g.size() < numberOfVertices)
		g.push_back(tmp);

	//���� ������� ���������
	if (to != 0) g[from - 1].push_back(to);
}

//���� ������� �� ����� ����� - �������
void ListGraph::isLoop(std::vector<int>& vertices, int vertex) const
{
	auto pos = std::find(g[vertex - 1].begin(), g[vertex - 1].end(), vertex);

	if (pos == g[vertex - 1].end())
	{
		std::swap(vertices.front(), vertices.back());
		vertices.pop_back();
	}
}

//��� �������, � ������� ����� ����� �� ��������
void ListGraph::GetNextVertices(int vertex, std::vector<int>& nextVertices) const
{
	nextVertices.clear();
	
	//����������� ����������� �������� (����� �� ������ � ����� �����)
	std::function<void(int)> dfs = [&](int vertex)
	{
		nextVertices.push_back(vertex);

		for (auto nextVertex : g[vertex - 1])
			//���� ������� �� �������� - ������� � ��������� �������
			if (std::find(nextVertices.begin(), nextVertices.end(), nextVertex) == nextVertices.end())
				dfs(nextVertex);
	};

	dfs(vertex);

	//���� ������� �� ����� ����� - �������
	isLoop(nextVertices, vertex);

	std::sort(nextVertices.begin(), nextVertices.end());
}

//��� �������, �� ������� ����� ����� � ��������
void ListGraph::GetPrevVertices(int vertex, std::vector<int>& prevVertices) const
{
	prevVertices.clear();
	
	//����������� ����������� �������� (����� �� ����� � ������ �����)
	std::function<void(int)> dfs = [&](int vertex)
	{
		prevVertices.push_back(vertex);

		for (size_t i{}; i < VerticesCount(); ++i)
			for (auto nextVertex : g[i])
				if (nextVertex == vertex)
					//���� ������� �� �������� - ������� � ��������� �������
					if (std::find(prevVertices.begin(), prevVertices.end(), i + 1) == prevVertices.end())
						dfs(i + 1);
	};

	dfs(vertex);

	//���� ������� �� ����� ����� - �������
	isLoop(prevVertices, vertex);

	std::sort(prevVertices.begin(), prevVertices.end());
}

//����� �����
void ListGraph::output() const
{
	std::cout << "\nList:\n";

	for (size_t j{}; j < VerticesCount(); ++j)
	{
		std::cout << "g[" << j + 1 << "]: ";

		for (size_t i{}; i < g[j].size(); ++i)
		{
			std::cout << g[j][i] << ' ';
		}

		std::cout << '\n';
	}
}