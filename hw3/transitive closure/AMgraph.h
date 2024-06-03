#pragma once

#include "graph.h"

class AMgraph : public graph
{
    public:
        AMgraph(int size) : graph(size);
        virtual bool edgemember(int fromv, int tov);
    protected:
        int **am;
    private:
};

//stating graph matrix by given size and initialize it
AMgraph::AMgraph(int size) : graph(size)
{
    am = new int*[size];
    assert(am);
    for (int i = 0; i < size; i++)
    {
        am[i] = new int[size];
        assert(am[i]);
        for (int j = 0; j < size; j++)
        {
            am[i][j] = 0;
        }
    }
}

//finding if two vertices are connected
AMgraph::edgemember(int fromv, int tov)
{
    assert(fromv < n && tov < n && fromv >= 0 && tov >= 0);
    return bool(am[fromv][tov] != 0);
}