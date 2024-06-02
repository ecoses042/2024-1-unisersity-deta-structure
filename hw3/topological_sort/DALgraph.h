#pragma once

#include "ALgraph.h"

class DALgraph :public ALgraph
{
    public:
        DALgraph(int size) : ALgraph(size){}
        virtual void addEdge(int fromv, int tov);
};

void DALgraph::addEdge(int fromv, int tov)
{
    //verify if fromv and tov are ligit
    assert(fromv >= 0 && fromv < n && tov < n && tov >=0); 
    vertexlist[fromv].insert(tov);
    m++; //increase edge count
}