#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "Graph.cpp"

using namespace std;

int main()
{
	Graph g;

	string string_temp;

	ifstream inFile;

	inFile.open("mat.txt");

	vector< vector<string>> matrix; //create 2d vector

	while(getline(inFile,string_temp))
	{
		stringstream ss(string_temp);
		vector<string> temp;

		string current_string;

		while(ss>>current_string)
		{
			temp.push_back(current_string); //creates vector that parses string 
		}
		matrix.push_back(temp);//puts vector of strings into matrix vector
	}
	
	for (int i = 1; i < 5; i++)
	{
		g.addVertex(matrix[i][0]);
	}
	for (int i = 1; i < 5; i++)
	{
		g.addEdge(matrix[1][0], matrix[0][i], stoi(matrix[1][i]));
	}
	for (int i =1; i < 5; i++)
	{
		g.addEdge(matrix[2][0], matrix[0][i], stoi(matrix[2][i]));
	}
	for (int i = 1; i < 5; i++)
	{
		g.addEdge(matrix[3][0], matrix[0][i], stoi(matrix[3][i]));
	}
	for(int i=1;i<5;i++)
	{
		g.addEdge(matrix[4][0], matrix[0][i], stoi(matrix[4][i]));
	}
	g.displayEdges();
}