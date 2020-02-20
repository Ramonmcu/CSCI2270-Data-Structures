#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "CommunicationNetwork.h"


using namespace std;

int printmenu()
{
	string choice;
	cout	<<	"======Main Menu======"	<<	endl;					
	cout	<<	"1. Build Network"	<<	endl;					
	cout	<<	"2. Print Network Path"	<<	endl;						
	cout	<<	"3. Transmit Message Coast-To-Coast-To-Coast"	<<	endl;					
	cout	<<	"4. Add City"	<<	endl;	
	cout	<<	"5. Delete City"	<<	endl;
	cout 	<<	"6. Clear Network"<<endl;
	cout 	<< 	"7. Quit"<<endl; 
	getline(cin,choice);
	return stoi(choice);
}

int main(int argc, char *argv[])
{
	CommunicationNetwork net;
	int userchoice;
	userchoice=printmenu();
	while(userchoice !=7)
	{
		if (userchoice == 1)
		{
			net.buildNetwork();
			net.printNetwork();
			userchoice=printmenu();
		}
		else if (userchoice == 2)
		{
			net.printNetwork();
			userchoice=printmenu();
		}
		else if (userchoice == 3)
		{
			net.transmitMsg(argv[1]);
			userchoice=printmenu();
		}
		else if (userchoice == 4)
		{
			string cityNewName;
			string cityPreviousName;
			cout<<"Enter a city name: "<<endl;
			getline(cin,cityNewName);
			cout<<"Enter a previous city name: "<<endl;
			getline(cin,cityPreviousName);
			net.addCity(cityNewName,cityPreviousName);
			userchoice=printmenu();
		}
		else if(userchoice == 5)
		{
			string cityname;
			cout<<"Enter a city name:"<<endl;
			getline(cin,cityname);
			net.deleteCity(cityname);
			userchoice=printmenu();
		}
		else if(userchoice == 6)
		{
			net.~CommunicationNetwork();
			userchoice=printmenu();
		}
	}
	cout<<"Goodbye!"<<endl;

	return 0;
}


