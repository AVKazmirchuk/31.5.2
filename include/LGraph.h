#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>



class ListGraph : public IGraph
{
private:
	
	//������ ���������
	std::vector<std::vector<int>> g;

	//������� ������������� ����� �������� ���������
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

	//��������� ������� ���������
	const std::vector<std::vector<int>>& getG() const override
	{
		return g;
	}

	//��������� ������� ���������
	std::vector<std::vector<int>>& getG() override
	{
		return g;
	}

	//��������� ���������� ������
	const size_t VerticesCount() const override
	{
		return g.size();
	}

	//������� ���������� ������� ���������, ���� ���������� ������ ������� �� ��������
	void AddEdge(int from, int to) override;
private:
	
	//���� ������� �� ����� ����� - �������
	void isLoop(std::vector<int>& visited, int vertex) const;
public:
	
	//��� �������, � ������� ����� ����� �� ��������
	void GetNextVertices(int vertex, std::vector<int>& nextVertices) const override;

	//��� �������, �� ������� ����� ����� � ��������
	void GetPrevVertices(int vertex, std::vector<int>& prevVertices) const override;

	//����� �����
	void output() const override;
};