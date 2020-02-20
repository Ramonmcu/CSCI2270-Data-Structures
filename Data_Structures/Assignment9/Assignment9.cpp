#include<vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "Graph.h"

using namespace std;
int  menu()
{
	string choice;
	cout<<"======Main Menu======"<<endl;
	cout<<"1. Print vertices"<<endl;
	cout<<"2. Find districts"<<endl;
	cout<<"3. Find shortest path"<<endl;
	cout<<"4. Find shortest weighted path"<<endl;
	cout<<"5. Quit"<<endl;
	getline(cin,choice);
	return stoi(choice);
}
int main(int argc, char const *argv[])
{
	Graph g;

	ifstream inFile;

	string string_temp;

	inFile.open(argv[1]);

	if(inFile.fail())
	{

	}
	else
	{
		vector< vector<string>> matrix; //create 2d vector

		while(getline(inFile,string_temp))
		{
			stringstream ss(string_temp);
			vector<string> temp;

			string current_string;

			while(getline(ss,current_string,','))
			{
				temp.push_back(current_string); //creates vector that parses string
			}
			matrix.push_back(temp);//puts vector of strings into matrix vector
		}

		for (int i = 1; i < 16; i++)
		{
			g.addVertex(matrix[i][0]);
		}
		for (int i = 1; i < 16; i++)
		{
		    if(stoi(matrix[1][i]) != -1)
		    {
			g.addEdge(matrix[1][0], matrix[0][i], stoi(matrix[1][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
		    if(stoi(matrix[2][i]) != -1)
		    {
			g.addEdge(matrix[2][0], matrix[0][i], stoi(matrix[2][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
		    if(stoi(matrix[3][i]) != -1)
		    {
			g.addEdge(matrix[3][0], matrix[0][i], stoi(matrix[3][i]));
			}
		}
		for (int i = 1 ;i < 16; i++)
		{
            if(stoi(matrix[4][i]) != -1)
		    {
			g.addEdge(matrix[4][0], matrix[0][i], stoi(matrix[4][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
		    if(stoi(matrix[5][i]) != -1)
		    {
			g.addEdge(matrix[5][0], matrix[0][i], stoi(matrix[5][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
		    if(stoi(matrix[6][i]) != -1)
		    {
			g.addEdge(matrix[6][0], matrix[0][i], stoi(matrix[6][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
            if(stoi(matrix[7][i]) != -1)
		    {
			g.addEdge(matrix[7][0], matrix[0][i], stoi(matrix[7][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
	        if(stoi(matrix[8][i]) != -1)
		    {
			g.addEdge(matrix[8][0], matrix[0][i], stoi(matrix[8][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
            if(stoi(matrix[9][i]) != -1)
		    {
			g.addEdge(matrix[9][0], matrix[0][i], stoi(matrix[9][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
		    if(stoi(matrix[10][i]) != -1)
		    {
			g.addEdge(matrix[10][0], matrix[0][i], stoi(matrix[10][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
		    if(stoi(matrix[11][i]) != -1)
		    {
			g.addEdge(matrix[11][0], matrix[0][i], stoi(matrix[11][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
		    if(stoi(matrix[12][i]) != -1)
		    {
			g.addEdge(matrix[12][0], matrix[0][i], stoi(matrix[12][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
		    if(stoi(matrix[13][i]) != -1)
		    {
			g.addEdge(matrix[13][0], matrix[0][i], stoi(matrix[13][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
		    if(stoi(matrix[14][i]) != -1)
		    {
			g.addEdge(matrix[14][0], matrix[0][i], stoi(matrix[14][i]));
			}
		}
		for (int i = 1; i < 16; i++)
		{
		    if(stoi(matrix[15][i]) != -1)
		    {
			g.addEdge(matrix[15][0], matrix[0][i], stoi(matrix[15][i]));
			}
		}
	}
	int userchoice=0;
	userchoice=menu();
	while(userchoice != 5)
	{
		if(userchoice == 1)
		{
			g.displayEdges();
			userchoice=menu();
		}
		else if (userchoice == 2)
		{
			g.assignDistricts();
			userchoice=menu();
		}
		else if(userchoice == 3)
		{
			string startingcity;
			string endingcity;

			cout<< "Enter a starting city:"<<endl;
			getline(cin, startingcity);
			cout<< "Enter an ending city:"<<endl;
			getline(cin,endingcity);

			g.shortestPath(startingcity, endingcity);

			userchoice=menu();

		}
		else if(userchoice == 4)
		{
			string startingcity;
			string endingcity;

			cout<< "Enter a starting city:"<<endl;
			getline(cin, startingcity);
			cout<< "Enter an ending city:"<<endl;
			getline(cin,endingcity);

			g.shortestWeightedPath(startingcity, endingcity);

			userchoice=menu();

		}

	}
	cout<<"Goodbye!"<<endl;
		return 0;
}