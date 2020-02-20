#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct city{

	string cityName;
	string message;
	city* next;
	city(){};//default constructor
	city(string initName, city *initNext, string initMessage)
	{
		cityName=initName;
		next=initNext;
		message=initMessage;
	}

};
city* createcity(string cityName,string message, city* nextcity)
{
	city* newcity=new city;
	newcity->cityName=cityName;
	newcity->next= nextcity;
	newcity->message=message;
	return newcity;
}
city* insertcity(city* head,string message, string cityName)
{
	if(head==NULL)
	{
		city* newcity= createcity(cityName,message,NULL);
		head=newcity;
	}
	else
	{
		city* currentcity=head;
		while(currentcity->next != NULL)
		{
			currentcity=currentcity->next;	
		}
		city* newcity=createcity(cityName,message,NULL);
		currentcity->next=newcity;
	}
	return head;
}
city* buildNetwork()
{
	city* head= NULL;
	head=insertcity(head,"","Los Angeles");
	head=insertcity(head,"","Phoenix");
	head=insertcity(head,"","Denver");
	head=insertcity(head,"","Dallas");
	head=insertcity(head,"","St. Louis");
	head=insertcity(head,"","Chicago");
	head=insertcity(head,"","Atlanta");
	head=insertcity(head,"","Washington, D.C.");
	head=insertcity(head,"","New York");
	head=insertcity(head,"","Boston");
	return head;
}
city* addCity(city* head, city* previous, string cityName)
{
	if(head==NULL)
	{
		city* newcity= createcity(cityName,"",NULL);
		head=newcity;
	}
	else if(previous==NULL)
	{
		city* c=head;
		city* newcity=createcity(cityName,"",c);
		head=newcity;
	}
	else
	{
		city* newcity=createcity(cityName,"",previous->next);
		previous->next=newcity;
	}
	return head;

}
void transmitMsg(city *head)
{
	if(head==NULL)
	{
		cout<<"Empty list"<<endl;
	}
	else
	{
		string string_Temp;
		string w;
		ifstream infile;

		infile.open("messageIn.txt");

		if(infile.is_open())
		{
			while(getline(infile,string_Temp))
			{
				int length=string_Temp.length();
				stringstream ss(string_Temp);
				for (int i = 0; i < length; i=i+w.length()+1)
				{
					getline(ss,w,' ');

					city* currentcity=head;
					while(currentcity != NULL)
					{
						currentcity->message=w;
						cout<< currentcity->cityName<<" received "<<currentcity->message<<endl;
						currentcity->message="";
						currentcity=currentcity->next;
					}

				}
			}
		}
		else
		{
			cout<<"Error file not opened"<<endl;
		}
	}
}
void printPath(city *head)
{
	if(head==NULL)
	{
		cout<<"empty list"<<endl;
	}
	else
	{
		city* currentcity=head;
		cout	<<	"===CURRENT PATH==="	<<	endl;	
		while(currentcity != NULL)
		{
			cout<<currentcity->cityName	<<	" -> ";
			currentcity=currentcity->next;	
		}
		cout	<<	"NULL"	<<	endl;	
		cout	<<	"=================="	<<	endl;	
	}

}
int printmenu()
{
	string choice;
	cout	<<	"======Main Menu======"	<<	endl;					
	cout	<<	"1.	Build Network"	<<	endl;					
	cout	<<	"2.	Print Network	Path"	<<	endl;						
	cout	<<	"3.	Transmit Message	Coast-To-Coast"	<<	endl;					
	cout	<<	"4.	Add	City"	<<	endl;	
	cout	<<	"5.	Quit"	<<	endl;
	getline(cin,choice);
	return stoi(choice);
}

int main(int argc, char*argv[])
{
	int userchoice;
	city* head=NULL;
	userchoice=printmenu();
	while(userchoice !=5)
	{
		if (userchoice == 1)
		{
			head=buildNetwork();
			userchoice=printmenu();
		}
		else if (userchoice == 2)
		{
			printPath(head);
			userchoice=printmenu();

		}
		else if (userchoice == 3)
		{
			transmitMsg(head);
			userchoice=printmenu();
		}
		else if (userchoice == 4)
		{
			string cityNew;
			string cityPrevious;
			cout	<<	"Enter	a	city	name:	"	<<	endl;																	
			getline(cin,cityNew);																	
			cout	<<	"Enter	a	previous	city	name:	"	<<	endl;																	
			getline(cin,cityPrevious);
			city* currentcity=head;	
			while(currentcity->cityName != cityPrevious)
			{
				currentcity=currentcity->next;
			}

			addCity(head,currentcity,cityNew);
			userchoice=printmenu();
		}
	}
	cout<<"Goodbye!"<<endl;
}
