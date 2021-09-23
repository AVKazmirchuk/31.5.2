#pragma once

#include <iostream>
#include <vector>



class IGraph
{
public:

	IGraph() {}

	IGraph(const IGraph* _oth) {}

	IGraph(const IGraph& _oth) {}

	virtual ~IGraph() {}

	virtual const std::vector<std::vector<int>>& getG() const = 0;

	virtual std::vector<std::vector<int>>& getG() = 0;

	virtual void AddEdge(int from, int to) = 0;

	virtual const size_t VerticesCount() const = 0;

	virtual void GetNextVertices(int vertex, std::vector<int>& nextVertices) const = 0;

	virtual void GetPrevVertices(int vertex, std::vector<int>& prevVertices) const = 0;

	virtual void output() const = 0;
};