#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct items
{
	//creates a struct that contains that hold three variables,2 string variables and 1 integer variable.
	//the type variable is used to identify what the item in question is. the status variable is used to 
	//keep track of wether the item is being sold or wanted, and cost just lets us know the itmes cost or how much someone is 
	//willing to pay
	string type=""; 
	int cost=-10;
	string status=""; 
};


int deletearr(items A[],int index,int numele)
{
	//shifts array by deleting value at index and moving every entry below index up by one. 
	for (int i = index; i <= numele-2; i++)
	{
		A[i]=A[i+1];
	}
	return(numele-1);
}

void itemremaining(items A[],int numele)
{
	//outputs items that are left in the message board 
	cout<<"Items remaining in the message board after reading all lines in the file."<<endl;
	cout<<"#"<<endl;
	for (int i = 0; i < numele; i++)
	{
		cout <<A[i].type<<","<<A[i].status<<","<<" "<<A[i].cost<<"\n";
	}
}
int main()
{
	//int argc, char*argv[]
	int a = 10;
	int*p = &a;

	cout<<p<<endl;
	cout<<a<<endl;
	cout<<*p<<endl;

	
	/*string file=argv[1];//takes file name from command line 

	ifstream infile;

	//creates 2 struct array one that keeps track of items in the message board and another that keeps track of sold items 
	items itemsarray[stoi(argv[2])];
	items soldarray[stoi(argv[2])];


	infile.open(file);

	if(infile.fail())
	{
		cout<<"Error file did not open"<<"\n";
	}
	else
	{
		//ensure file opens before rest of code is executed 
		cout<<"File opened"<<"\n";

		string string_temp;

	int location=0;
	int number=0;
	int count=0;
	int count2=0;

	while(getline(infile,string_temp))
	{
		//
		stringstream itemstream(string_temp);
		string cost;
		string type;
		string status;
		//parses string into three strings
		getline(itemstream,type,',');
		getline(itemstream,status,',');
		getline(itemstream,cost);
		int numcost;
		//converts cost from string to integer 
		numcost=stoi(cost);
		number++;
		location++;
		bool add=true;//boolean expression used to determine if current item should be added to community board

		// the for loop is used to check whether the current item in question can be sold or if we need to add it to the array that has items that are for sale/wanted
		for (int i = 0; i < location; i++)
		{
			if(type==itemsarray[i].type)//makes sure item in question and item in the current spot of itemsarray are of the same type
			{
				if(status != itemsarray[i].status)//makes sure item in question and item in the current spot of itemsarray have a different status
				{
					if(status==" wanted")
					{
						if(numcost == itemsarray[i].cost || numcost > itemsarray[i].cost)
						{	//ensures the price of the item is less than or equal to the price the person is willing to pay
							//then adds the item sold and price to array that hold sold items 
							soldarray[count].type=type;
							soldarray[count].cost=itemsarray[i].cost;
							soldarray[count].status=status;

							int newlocation=deletearr(itemsarray,i,number);
							
							add=false;
							count++;
							count2=count2-1;

							break;
						}
					
					}
					else if(status==" for sale")
					{
						if(numcost <= itemsarray[i].cost)//check logic 
						{

							int newlocation=deletearr(itemsarray,i,number);
							add=false;
							soldarray[count].type=type;
							soldarray[count].cost=numcost;
							soldarray[count].status=status;
							count++;
							count2=count2-1;
							break;
						}
					}
				}
			}
		}
		if(add)
		{
		itemsarray[count2].type=type;
		itemsarray[count2].status=status;
		itemsarray[count2].cost=numcost;
		count2++;
	
	
	}

}
	//prints out items that remain after all macthes are found 
	cout<< "Items Sold."<<"\n";
	cout<<"#"<<endl;
	for (int i = 0; i < count; i++)
	{
		cout <<soldarray[i].type<<" "<< soldarray[i].cost<<"\n";
	}
	itemremaining(itemsarray,count2);//prints out sold items 
return 0;
}*/
}

	