#include "graph.h"
#include "AMgraph.h"
#include "dAMgraph.h"
#include "uAMgraph.h"
#include <fstream>

//goal is to connect all the related vertives directly.
int main()
{
    const char *infilename = "graph.txt";
    ifstream ifs(infilename);
    assert(ifs);
    int n;
    ifs >> n;
    uAMgraph G(n);
    cout << "Created graph; n = " << G.vertexsize() << endl;
    int u, v;
    while ( ifs >> u ) 
    {
        ifs >> v;
        G.addEdge(u,v);
    }
    cout << "Edges in graph: m = " << G.edgesize() << endl;
    int step;
    for (step = 0; step<n; step++)
    {
        for (u = 0; u < n; u++)
        {
            for (v = 0; v < n; v++)
            {
                if (G.edgemember(u,step) && G.edgemember(step, v))
                    G.addEdge(u,v);
            }
        }
    }
    for (u=0; u < n; u++) 
    {
        cout << u << "\t: ";
        for (v = 0; v < n; v++)
            cout << (G.edgemember(u,v)? "T " : "F ");
        cout << endl;
    }
return 0;
}