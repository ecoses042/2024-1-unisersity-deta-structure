#include <iostream>
#include <fstream>
#include <cassert>
#include "Queue.h"
#include "DALGraph.h"
#include "stack.h"
using namespace std;

int main()
{
	cout << "20211530 Minsoo Song\n" << "\n";

	//this part reads the file and make it directional adjcency list graph
	const char *infilename = "graph.txt";
	ifstream ifs(infilename);
	assert(ifs);
	int n;
	ifs >> n;
	DALgraph G(n);
	cout << "created graph; n = " << G.vertexsize() << "\n";
	int u,v;
	while (ifs >> u){
		ifs >> v;
		G.addEdge(u,v);
	}
	cout << "edges in graph m = " << G.vertexsize() << "\n";

	//this part append number of edges starting from given vertex(index of vertices)
	int *vertices(new int[n]);
	assert (vertices);
	for (u = 0; u < n; u++)
	{
		vertices[u] = 0;
	}
	for (u = 0; u < n; u++)
	{
		neighboriter ni(G,u);
		while ((v = ++ni) != n)
			vertices[v]++;
	}
	cout << "edges in graph with list form: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << vertices[i] << "\t";
	}
	//push the vertices with no edges connected to given vertex
	stack <int> s;
	for (u = 0; u < n; u++)
	{
		if (vertices[u] == 0)
			s.push(u);
	}
	if (s.isEmpty())
	{
		cout << "graph has a cycle" << endl;\
		return 0;
	}

    //begin topological sort.
	int count = 0;
	queue <int> sortededges;
	while (!s.isEmpty())
	{
		count++;
		u = s.pop();
		sortededges.enqueue(u);
		neighboriter ni(G,u);
		while ((v = ++ni)!= n)
		{
			--vertices[v];
			if (vertices[v] == 0)
				s.push(v);
		}
	}
	if (count < n)
		cout << "couldn't complete top sort, cycle present"	<< endl;
	cout << "ordering for top sort:\n";
	while (!sortededges.isEmpty())
	{
		cout << sortededges.dequeue() << "\t";
	}
	cout << endl;
	return n;
}

