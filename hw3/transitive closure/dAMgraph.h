#pragma once

#include "AMgraph.h"

class dAMgraph : public dAMgraph
{
    public:
        dAMgraph(int size, int initialvalue = 0) : AMgraph(size){}
        virtual void addEdge(int fromv, int tov);
    protected:
    private:
};

void dAMgraph::addEdge(int fromv, int tov)
{
    assert(fromv >= 0 && tov >= 0 && fromv < n && tov < n);
    if (!edgemember(fromv,tov))
    {
        m++;
        am[fromv][tov] = 1;
    }
}