#include <vector>
#include <iostream>
#include "Graph.h"

using namespace std;



void Graph::addEdge(string v1, string v2, int distance )
{
	if(distance != -1)
	{
		for(int i = 0; i < vertices.size(); i++){
	        if(vertices[i].name == v1){
	            for(int j = 0; j < vertices.size(); j++){
	                if(vertices[j].name == v2 && i != j){
	                    adjVertex av;
	                    av.v = &vertices[j];
	                    av.weight = distance;
	                    vertices[i].adj.push_back(av);
	                    //another vertex for edge in other direction
	                    /*adjVertex av2;
	                    av2.v = &vertices[i];
	                    av2.weight = distance;
	                    vertices[j].adj.push_back(av2);*/
	                }
	            }
	        }
	    }
	}
}

void Graph::addVertex(string name)
{
	bool found=false;
	for (int i = 0; i < vertices.size(); i++)
	{
		if(vertices[i].name == name )//vertex is already in graph 
		{
			found = true;
			cout<<vertices[i].name<<" already in graph"<<endl;
			break; 	
		}
	}
	if(found ==false)//vertex is not in graph
	{
		vertex v;//creates new vertex
		v.name=name;
		vertices.push_back(v);//add ele to end of vector 
	}
}

int Graph::isAdjacent(string v1, string v2)
{
   bool adj=false;
	for (int i = 0; i < vertices.size(); i++)
	{
		if(vertices[i].name == v1 )//vertex is already in graph 
		{
			for (int j = 0; j < vertices[i].adj.size(); j++)
			{
				if(vertices[i].adj[j].v->name ==v2)
				{
					adj=true;
				}
			}
		}
	}
	if(adj==true)
	{
	    return 1;
	}
}

void Graph::displayEdges()
{
	for(int i = 0; i < vertices.size(); i++){
    cout<<vertices[i].name<<"-->";
   	for(int j = 0; j < vertices[i].adj.size(); j++){
        cout<<vertices[i].adj[j].v->name;
        if(j != vertices[i].adj.size()-1)
        {
        	cout<<"***";
        }
    }
   	cout<<endl;
    }
}