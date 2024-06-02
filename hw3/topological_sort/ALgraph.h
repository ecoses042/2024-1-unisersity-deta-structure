#pragma once

#include "graph.h"
#include "list.h"
typedef list <int> intlist;
typedef listiter <int> intlistiter;
class ALgraph:public graph
{
    public:
        //calles graph class to get the size of n(the number of vertices)
	    //creates a graph in adjacency list format
        ALgraph(int size) : graph(size)
        {
            vertexlist = new intlist[n]; assert(vertexlist);
        }
        //class that returns the next edge connecting the vertex
        friend class neighboriter;
    protected:
        intlist* vertexlist;
    private:
};

//inherit from intlistiter class
//
class neighboriter:public intlistiter
{
    public:
        neighboriter(const ALgraph& G, int startvertex):
        //G.n is the endflag
        //G.vertexlist[startvertex] is the starting vertex
        //goal is to return edges connected by startvertex one by one
        intlistiter(G.vertexlist[startvertex], G.n)
            {assert(startvertex<G.n);}
};