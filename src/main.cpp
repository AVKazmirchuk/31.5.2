#include <iostream>
#include <ctime>

#include "../include/IGraph.h"
#include "../include/LGraph.h"
#include "../include/MGraph.h"


int main()
{
    ListGraph lg;

    lg.input();
    lg.output();

    MatrixGraph mg(&lg);
    mg.output();

    //IGraph* ig;
}
