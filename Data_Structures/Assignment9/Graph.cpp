#include <vector>
#include <iostream>
#include <queue>
#include <stack>

#include "Graph.hpp"

using namespace std;

Graph::Graph()
{
  for(int i=0; i<vertices.size();i++)
  {
      vertices[i].districtID=-1;
  }
}
Graph::~Graph()
{
  for(int i=0; i<vertices.size();i++)
  {
      vertices[i].districtID=-1;
  }
}
vertex* Graph::findVertex(std::string name)
{
	int i=0;
	while (i<vertices.size()) {
		if (vertices[i].name == name) {
			return &vertices[i];
		}
		i++;
	}
	return nullptr;
}


void Graph::addEdge(string v1, string v2, int distance )
{
	if(distance != -1)
	{
		for(int i = 0; i < vertices.size(); i++){
		    vertices[i].districtID=-1;
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
		v.districtID = -1; // defaaults district id to -1 
	}
}

void Graph::displayEdges()
{

	for(int i = 0; i < vertices.size(); i++){
	cout<<vertices[i].districtID<<":";
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

void Graph::assignDistricts()
{
    int district_id =1;
	for (int i = 0; i<vertices.size(); i++)
	{
		if (vertices[i].visited == false)
		{
			DFSLabel(vertices[i].name, district_id);
			district_id++;
		}
	}
}

void Graph::DFSLabel(string startingCity, int distID)
{
	vertex* startvert = findVertex(startingCity);
    stack<vertex* > vertexS;
    
    if(startvert)
    {
        vertexS.push(startvert);
        while( !vertexS.empty())
        {
            vertex* curV = vertexS.top();
            vertexS.pop();
            
            if( ! curV->visited)
            {
                curV->districtID=distID;
                curV->visited = true;
            }
            for(int i=0 ;i<curV->adj.size();i++)
            {
                if( !curV->adj[i].v->visited)
                {
                    vertexS.push(curV->adj[i].v);
                }
            }
        }
    }
	
}

void Graph::shortestPath(string startingCity, string endingCity)
{
	vertex* startvert = findVertex(startingCity);
	vertex* endvert = findVertex(endingCity);
    for(int i=0; i<vertices.size();i++)
    {
        vertices[i].visited = false;
        vertices[i].unweightedDistance =INT_MAX;
    }
	if(startvert == nullptr || endvert == nullptr)//one or more cities dont exist 
	{
		cout<<"One or more cities doesn't exist"<<endl;
	}
	else if(startvert->districtID != endvert->districtID)// cities in different districts 
	{
		cout<<"No safe path between cities"<<endl;

	}
	else if (startvert->districtID == -1 || endvert->districtID == -1)//districts not set yet 
	{
		cout<<"Please identify the districts before checking distance"<<endl;
	}
	else
	{
	    vertex* prevparent;
	    vertex* parent;
	    int dist =0;
	    queue<vertex* > vertexQ;
	    stack<vertex* > path;
	    startvert->visited = true;
	    startvert->parent=nullptr;
	    startvert->unweightedDistance = dist;
	    vertexQ.push(startvert);
	    
	    while( vertexQ.size() != 0)
	    {
	        vertex* curV = vertexQ.front();
	        vertexQ.pop();
	        
	        if(curV->parent == nullptr || curV->parent != prevparent)
	        {
	             
	            dist++;
	        }
	        
	         prevparent = curV->parent;
	        for(int i =0; i<curV->adj.size(); i++)
	        {
	            if (! curV->adj[i].v->visited)
	            {
	                curV->adj[i].v->parent = curV;
	                parent=curV;
	                curV->adj[i].v->unweightedDistance=dist;
	                curV->adj[i].v->visited = true;
	                vertexQ.push(curV->adj[i].v);
	                if(curV->adj[i].v == endvert)
	                {
	                    cout<< dist << ", ";
	                    while(parent != nullptr)
	                    {
	                        path.push(parent);
	                        parent = parent->parent;
	                    }
	                    while(path.size() !=0)
	                    {
	                        vertex* temp = path.top();
	                        path.pop();
	                        cout<<temp->name<<", ";
	                    }
	                    cout<<curV->adj[i].v->name<<endl;
	                }
	                
	            }
	        }
	    }
	 }
}
void Graph::shortestWeightedPath(string startingCity, string endingCity)
{
    vertex* startvert = findVertex(startingCity);
	vertex* endvert = findVertex(endingCity);
	
    for(int i=0; i<vertices.size();i++)
    {
        vertices[i].visited = false;
        vertices[i].weightedDistance =INT_MAX;
    }
	if(startvert == nullptr || endvert == nullptr)//one or more cities dont exist 
	{
		cout<<"One or more cities doesn't exist"<<endl;
	}
	else if(startvert->districtID != endvert->districtID)// cities in different districts 
	{
		cout<<"No safe path between cities"<<endl;

	}
	else if (startvert->districtID == -1 || endvert->districtID == -1)//districts not set yet 
	{
		cout<<"Please identify the districts before checking distances"<<endl;
	}
	else
	{
	    vertex* parent=nullptr;
	    bool endsolved = false;
	    string visited[vertices.size()];
	    int index=1;
	    int dist =0 ;
	    int min_distance=INT_MAX;
	    startvert->weightedDistance=0;
	    startvert->visited = true;
	    startvert->parent = nullptr;
	    queue<vertex* > solved;
	    queue<vertex* > path;
	    solved.push(startvert);
	    path.push(startvert);
	    visited[0] = startvert->name;
	    
	    while(!endsolved)
	    {
	        min_distance = INT_MAX;
	        vertex* solvedv = nullptr;
	        while(solved.size() !=0 )
	        {
	            min_distance = INT_MAX;
	            vertex* curV = solved.front();
	            solved.pop();
	            for(int j=0;j<curV->adj.size();j++)
	            {
	                if(!curV->adj[j].v->visited)
	                {
	                    dist = curV->weightedDistance+curV->adj[j].weight;
	                    if(dist < curV->adj[j].v->weightedDistance)
	                    {
	                        curV->adj[j].v->weightedDistance=dist;
	                        solvedv = curV->adj[j].v;
	                        min_distance =dist;
	                        parent = curV;
	                    }
	                    if(curV->adj[j].v == endvert)
	                    {
	                        break;
	                    }
	                    
	                }
	            }
	            if(solvedv == nullptr)
	            {
	                int min=INT_MAX;
	                int k=0;
	                vertex* temp = curV->parent;
	                while(k<temp->adj.size())
	                {
	                    if( !temp->adj[k].v->visited && temp->adj[k].v->weightedDistance < min )
	                    {
	                        solvedv=temp->adj[k].v;
	                        min=temp->adj[k].v->weightedDistance;
	                        min_distance = min;
	                    }
	                    k++;
	                }
	            }
	            if(solvedv == endvert)
	            {
	                 bool add = true;
	                for(int i=0; i< index+1;i++)
	                {
	                    if(parent->name == visited[i])
	                    {
	                        add=false;
	                    }
	                }
	                if(add && parent != nullptr)
	                {
	                path.push(parent);
	                visited[index] = parent->name;
	                index++;
	                }
	                cout<<solvedv->weightedDistance<<", ";
	                while(path.size() !=0)
	                {
	                    vertex* temp = path.front();
	                    path.pop();
	                    cout<<temp->name<<", ";
	                }
	                cout<<endvert->name<<endl;
	                endsolved=true;
	                break;
	            }
	            else
	            {
	                solvedv->weightedDistance = min_distance;
	                solvedv->parent = parent;
	                solvedv->visited = true;
	                solved.push(solvedv);
	                bool add = true;
	                for(int i=0; i< index+1;i++)
	                {
	                    if(parent->name == visited[i])
	                    {
	                        add=false;
	                    }
	                }
	                if(add && parent != nullptr)
	                {
	                path.push(parent);
	                visited[index] = parent->name;
	                index++;
	                }
	                solvedv = nullptr;
	            }
	        }
	    }
	}
}





