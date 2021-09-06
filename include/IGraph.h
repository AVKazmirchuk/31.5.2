#pragma once

#include <iostream>
#include <vector>

class IGraph
{
public:
    int numberOfVertices;
    std::vector<std::vector<int>> g;

    virtual void input() = 0;

    virtual void output() = 0;
};

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


