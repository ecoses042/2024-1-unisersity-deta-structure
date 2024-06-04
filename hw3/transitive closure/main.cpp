#include "graph.h"
#include "AMgraph.h"
#include "dAMgraph.h"
#include "uAMgraph.h"
#include <fstream>

int main()
{
    cout << "20211530 Minsoo Song" << endl;
    const char *infilename = "graph.txt";
    ifstream ifs(infilename);
    assert(ifs);
    int n;
    ifs >> n;
    uAMgraph G(n);
    cout << "Created graph; n = " << G.vertexSize() << endl;
    int u, v;
    while ( ifs >> u ) 
    {
        ifs >> v;
        G.addEdge(u,v);
    }
    cout << "Edges in graph: m = " << G.edgeSize() << endl;
    

}