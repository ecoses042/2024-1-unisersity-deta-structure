#pragma once

#include "AMgraph.h"

class uAMgraph: public AMgraph
{
    public:
        uAMgraph(int size, int initialvalue = 0):
        AMgraph(size){}
        virtual void addEdge(int fromv, int tov);
    protected:
    private:
};

void uAMgraph::addEdge(int fromv, int tov)
{
    assert(fromv >= 0 && tov >= 0 && fromv < n && tov < n);
    if (!edgemember(fromv, tov))
    {
        m++;
        am[fromv][tov] = 1;
        am[tov][fromv] = 1;
    }
}