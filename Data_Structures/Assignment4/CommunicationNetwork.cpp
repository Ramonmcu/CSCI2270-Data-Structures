#include <fstream>
#include <sstream>
#include "CommunicationNetwork.h"

using namespace std;

CommunicationNetwork::CommunicationNetwork() //default costructor
{

}
CommunicationNetwork::~CommunicationNetwork() //deconstructor
{
	deleteNetwork();
	head=nullptr;
	tail=nullptr;
}

void CommunicationNetwork::addCity(string cityname, string cityprev)
{

	if(cityprev == "" && head != nullptr)
	{
		City* newcity=new City;
		newcity->cityName=cityname;
		newcity->next= nullptr;
		newcity->previous=tail;
		newcity->message=" ";
		tail->next = newcity;
		tail = newcity;

	}
	else if(head==nullptr )
	{
       	City* newcity=new City;
		newcity->cityName=cityname;
		newcity->next= nullptr;
		newcity->previous=nullptr;
		newcity->message=" ";
		head=newcity;
		tail=newcity;
	}
	else if(cityprev == "First")
	{
		City* newcity=new City;
		newcity->cityName=cityname;
		newcity->next= head;
		newcity->previous=nullptr;
		newcity->message=" ";
		head->previous=newcity;
		head=newcity;
	}
	else
	{
	    City* currentcity=head;
		while(currentcity->cityName != cityprev)
		{
			currentcity=currentcity->next;
		}

		City* newcity=new City;
		newcity->cityName=cityname;
		newcity->next= currentcity->next;
		newcity->previous=currentcity;
		newcity->message=" ";
		currentcity->next->previous=newcity;
		currentcity->next=newcity;
	}
}
void CommunicationNetwork::buildNetwork()
{
	City* head= nullptr;
	addCity("Los Angeles","");
	addCity("Phoenix", "");
	addCity("Denver", "");
	addCity("Dallas","");
	addCity("St. Louis","");
	addCity("Chicago","");
	addCity("Atlanta","");
	addCity("Washington, D.C.","");
	addCity("New York","");
	addCity("Boston","");

}
void CommunicationNetwork::transmitMsg(char * filename)
{
	string string_Temp;
	string w;
	ifstream infile;

	infile.open(filename);

	if(infile.is_open())
	{
		while(getline(infile,string_Temp))
		{
			int length=string_Temp.length();
			stringstream ss(string_Temp);
			for (int i = 0; i < length; i=i+w.length()+1)
			{
				getline(ss,w,' ');

				City* currentcity=head;
				while(currentcity->next != nullptr)
				{
					currentcity->message=w;
					cout<< currentcity->cityName<<" received "<<currentcity->message<<endl;
					currentcity->message="";
					currentcity=currentcity->next;
				}
				while(currentcity->previous != nullptr)
				{
					currentcity->message=w;
					cout<< currentcity->cityName<<" received "<<currentcity->message<<endl;
					currentcity->message="";
					currentcity=currentcity->previous;

				}
				currentcity->message=w;
				cout<< currentcity->cityName<<" received "<<currentcity->message<<endl;
				currentcity->message="";

			}
		}
	}
}
void CommunicationNetwork::printNetwork()
{
		City* currentcity=head;
		cout	<<	"===CURRENT PATH==="	<<	endl;	
		while(currentcity != tail)
		{
			cout<<currentcity->cityName	<<	" <-> ";
			currentcity=currentcity->next;	
		}
		cout<< tail->cityName<<"->";
		cout	<<	"NULL"	<<	endl;	
		cout	<<	"=================="	<<	endl;	
}
void CommunicationNetwork::deleteCity(string cityname)
{
	City* currentcity=head;
	bool city_found=false;
	while(currentcity !=nullptr)
	{
		if(currentcity->cityName==cityname)
		{
		    city_found=true;
				
			if(currentcity == head)
			{
				currentcity->next->previous=nullptr;
				head=currentcity->next;
				delete currentcity;
				
			}
			else if(currentcity	== tail)
			{
				currentcity->previous->next=nullptr;
				tail=currentcity->previous;
				delete currentcity;
			}
			else
			{
				currentcity->next->previous	= currentcity->previous;
				currentcity	->previous->next=currentcity->next;
				delete currentcity;
			}
		}
	    currentcity=currentcity->next;
	}
	if(city_found==false)
	{
	cout<< cityname << " not found"<<endl;
	}

}
void CommunicationNetwork::deleteNetwork()
{
	City* currentcity=head;
	City* tempcity= new City;
	while(currentcity->next != nullptr)
	{
	    cout<<"deleting "<<currentcity->cityName<<endl;
		tempcity=currentcity;
		currentcity=currentcity->next;
		currentcity->previous=nullptr;
		delete tempcity;
		head=currentcity;
	}
	if(currentcity->next == nullptr)
	{
	cout<<"deleting "<<currentcity->cityName<<endl;
	delete currentcity;
	head=nullptr;
	}
}

