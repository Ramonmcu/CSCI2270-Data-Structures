#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void resize(int* oldarray, int*capacity)
{
	int newCapacity=*capacity*2;
	int* newArray= new int[newCapacity];
	for (int i = 0; i <*capacity;i++)
	{
		newArray[i]=oldarray[i];
	}
	delete [] oldarray;
	oldarray=newArray;
	*capacity=newCapacity;

}
int main(int argc, char const *argv[])
{
	string string_temp;
	if(argc !=2)
	{
		return -1;
	}
	string filename = argv[1];
	ifstream inFile;
	inFile.open(filename);

	int capacity=10;
	int* a=new int[capacity];
	int numOfElement=0;

	if(inFile.is_open())
	{
		while(getline(inFile,string_temp))
		{
			int number=stoi(string_temp);
			if(numOfElement == capacity)
			{
				resize(a,&capacity);
			}
			a[numOfElement]=number;
			cout<< a[numOfElement] << endl;
			numOfElement++;
		}

	}
	cout<< "size of: " << sizeof(a)<<endl;
	delete [] a;
	return 0;
}