#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct wordItem
{
	string word="";
	int count=0;
};


void getStopWords(char *ignoreWordFileName, string ignoreWords[50])
{
//creates array of words that dont get counted from text file
	string string_temp;
	string word;

	int count=0;

	ifstream inFile;

	inFile.open(ignoreWordFileName);

	if(inFile.fail())
	{
		
	}
	else
	{
		//ensure file opens before rest of code is executed 
		while(getline(inFile,string_temp))
		{
			stringstream ss(string_temp);
			getline(ss,word);
  			ignoreWords[count]=word;
			count++;


		}
	}
}


bool isStopWord(string word, string ignoreWords[])
{
	//checks to make sure word in question is not one that needs to be ignored 
	bool ignore=false;
	for (int i = 0; i < 50; i++)
	{
		if (ignoreWords[i]==word)
		{
			ignore=true;
		}
	}

	return ignore;
}


int getTotalNumberNonStopWords(wordItem list[], int length)
{
	//finds total number of words stored in array 
	int number=0;
	for (int i = 0; i < length;i++)
	{
		number=number+list[i].count;
	}

	return number;
}


void arraySort(wordItem list[], int length)
{
	//sorts array from words with highest count to lowest count
	for (int i = 0; i < length; i++)
	{
		for (int j = i+1 ; j < length; j++)
		{
			if(list[i].count < list[j].count)
			{			
				wordItem temp;
				temp=list[i];
				list[i]=list[j];
				list[j]=temp;
			}
		}
	}
}


void printTopN(wordItem wordItemList[], int topN)
{
	//prints words that occure the most from 1 to n 
	for (int i = 0; i < topN;i++)
	{
		cout<< wordItemList[i].count << " - "<< wordItemList[i].word<<endl;
	}
}


void resize(wordItem* &oldarray, int*capacity)
{
	//changes size of array to account for more words
	int newCapacity=*capacity*2;
	wordItem* newArray= new wordItem[newCapacity];
	for (int i = 0; i <*capacity;i++)
	{
		newArray[i].word=oldarray[i].word;
		newArray[i].count=oldarray[i].count;
	}
	delete [] oldarray;
	oldarray=newArray;
	*capacity=newCapacity;

}


int main(int argc, char*argv[])
{

	int topN=stoi(argv[1]);
	string ignoreWords[50];
	string string_temp;

	int numberofwords=0;
	int arraydoubled=0;

	int sizeofwordarray=100;

	wordItem* words= new wordItem[sizeofwordarray];

  	getStopWords(argv[3],ignoreWords);

  	ifstream inFile;
  	inFile.open(argv[2]);

  	

  	if(inFile.fail())
	{
		return -1;
	}
	else
	{
		//ensure file opens before rest of code is executed 
		while(getline(inFile,string_temp))
		{
			int length=string_temp.length();
			bool ignore=false;
			stringstream ss(string_temp);
			for (int i = 0; i < length; i++)
			{
				bool newword=true;
				string w;
				getline(ss,w,' ');
				//cout<<w<<endl;
				if( w.compare("\n")&&w.compare("\r")&&w.compare("\0"))
				{
					for (int i = 0; i < 50; ++i)
					{
						//checks to makse sure word in question does not need to be ignored
						ignore=isStopWord(w,ignoreWords);
					}
					if(!ignore)
					{
		
					//	cout<<numberofwords<<endl;
						//only runs if word should be kept 
						if(numberofwords==0)//runs when array of words is empty 
						{
					//		cout<<"here"<<endl;
							words[0].count=1;
							words[0].word=w;
							numberofwords++;
						}
						else//when array of words is not empty 
						{
				
							for (int i = 0; i < numberofwords; i++)//checks word in question and sees if it is already in word array 
							{
								if(w == words[i].word)
								{
								//if word is already in array just added to count for number of times word has shown up.
									int number=words[i].count;
									words[i].count=number+1;
									newword=false;
								}
							}
							if(newword==true)
							{
								numberofwords++;
								if(numberofwords==sizeofwordarray)
								{
									//changes size of array if new word cant be added to array
									resize(words,&sizeofwordarray);
									arraydoubled++;
								}
									//adds word to words array
									words[numberofwords-1].word=w;
									words[numberofwords-1].count=1;
							}

						}
					}

				}
			}
			
		}
		arraySort(words,numberofwords);
		printTopN(words,topN);
		int totalwords=getTotalNumberNonStopWords(words,numberofwords);
		cout<<"#"<<endl;
		cout<<"Array doubled: "<< arraydoubled<<endl;
		cout<<"#"<<endl;
		cout<<"Unique non-common words: "<< numberofwords<<endl;
		cout<<"#"<<endl;
		cout<<"Total non-common words: "<<totalwords<<endl;

	}
 delete [] words;

	return 0;
}