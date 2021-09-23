#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>



class MatrixGraph : public IGraph
{
private:
	
	//������� ���������
	std::vector<std::vector<int>> g;

	//������� ������������� ����� �������� ���������
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