#pragma once

#include <assert.h>
#include <iostream>

using namespace std;
class graph{
    public:
        graph(int size);
        virtual int vertexsize(); //return n
        virtual int edgesize(); //return m
        virtual void addEdge(int fromv, int tov) = 0; //add edge to graph
    protected:
        int n; //number of vertices
        int m; //number of edges
};

graph::graph(int size)
{
    n = size;
    m = 0;
}

int graph::vertexsize()
{
    return n;
}

int graph::edgesize()
{
    return m;
}
