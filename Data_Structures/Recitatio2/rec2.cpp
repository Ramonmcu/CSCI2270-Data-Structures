#include <iostream>
#include <fstream>
//#include <string>
#include <sstream>

using namespace std;

struct CarData
{
	string model; 
	string make;
	string year;

};

int main(int argc, char const *argv[])
{

	ifstream inFile; 

	string data;

	inFile.open(argv[1]);

	if(inFile.is_open())
	{

		cout<<"opened successfully" << endl;

		CarData cararray[stoi(argv[2])];

		string make;
		string year;
		string model;
	
		for (int i = 0; i < 10; i++)
		{
			getline(inFile,data);
			stringstream ss(data);

			getline(ss, model, ' ');
			cararray[i].model=model;

			getline(ss, make, ' ');
			cararray[i].make=make;

			getline(ss, year, ' ');
			cararray[i].year=year;
		}
		inFile.close();

		ofstream outfile; 
		outfile.open(argv[3]);
		for (int i = 0; i < 10; i++)
		{
			outfile<<cararray[i].make<<"\t";
			outfile<<cararray[i].model<<"\t";
			outfile<<cararray[i].year<<"\n";
		}

		outfile.close();
	}
	else
	{
		cout<<"File unsuccessfully opened"<<endl;
	}
	return 0;
}