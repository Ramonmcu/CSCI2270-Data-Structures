#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "MovieTree.hpp"

using namespace std;

MovieTree::MovieTree()
{

}

MovieTree::~MovieTree()
{
	DeleteAll(root);
}

void MovieTree::printMovieInventory()
{
	printMovieInventory(root);
}

int MovieTree::countMovieNodes()
{	
	int counter=0;
	countMovieNodes(root,&counter);	
}

void MovieTree::deleteMovieNode(std::string title)
{
	MovieNodeBST* movienode=searchBST(root,title);
	//find node where movie would occur 
	MovieNodeLL* LLlocation=searchLL(movienode->head,title);
	//looks to see if movie is in LL
	if(LLlocation == nullptr)
	//movie is not in LL
	{
		cout<<"Movie not found."<<endl;
	}
	else //case when movie is in LL
	{
		if((LLlocation==movienode->head) && (LLlocation->next == nullptr) )
		//node is only memeber of ll 
		{
			if((movienode->leftChild == nullptr) && (movienode->rightChild == nullptr))
			//node we want to delete has no children 
			{	
				delete movienode;
			}
			else if( (movienode ->leftChild != nullptr)  && (movienode->rightChild==nullptr))
			//node has 1 child 
			{

			}
			else if( (movienode ->leftChild == nullptr)  && (movienode->rightChild!=nullptr))
			//node has 1 child 
			{

			}
			else
			//node has 2 children 
			{

			}
		}
		else
		{
			
		}
	}
}
void addnodeLL()
{
	curparent=BST_node;
		if(title[0]==BST_node->letter)//node of character already exists 
		{
			MovieNodeLL* currentnode= BST_node->head;
			if(title<BST_node->head->title)
			{
				MovieNodeLL* newnode=new MovieNodeLL(ranking,title,releaseYear,quantity);
				newnode->next=BST_node->head;
				BST_node->head=newnode;
			}
			else
			{
				while(currentnode->next != nullptr)
				{

					if(title < currentnode->next->title)
					{
						MovieNodeLL* newnode=new MovieNodeLL(ranking,title,releaseYear,quantity);
						newnode->next=currentnode->next;
						currentnode->next=newnode;
                        break;
					}
					currentnode=currentnode->next;
				}
				if(title < currentnode->title)
				{
					MovieNodeLL* newnode=new MovieNodeLL(ranking,title,releaseYear,quantity);
					currentnode->next =newnode;
				}

			}
		}
}
void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{
	MovieNodeBST* newnode = new MovieNodeBST(title[0]);
	MovieNodeLL* newLL = new MovieNodeLL(ranking,title,releaseYear, quantity);
	if(root == nullptr)
	//if tree is empty adds to root
	{
		root=newnode;
		root->head= new MovieNodeLL(ranking,title,releaseYear,quantity)
	}
	else
	{
		MovieNodeBST* currentnode=root;
		while(currentnode != nullptr)
		{
			if(title[0]<currentnode->letter)
			{
				if(currentnode->leftChild==nullptr)
				{
					currentnode->leftChild=newnode;
					currentnode->leftChild->parent=currentnode;
					currentnode->leftChild->head=newLL;
					return;
				}
				else
				{
					currentnode=currentnode->leftChild;
				}
			}
			if(title[0]>currentnode->letter)
			{
				if(currentnode->rightChild==nullptr)
				{
					currentnode->rightChild=newnode;
					currentnode->rightChild->parent=currentnode;
					currentnode->rightChild->head=newLL;
					return;
				}
				else
				{
					currentnode=currentnode->rightChild;
				}
			}
			if(currentnode->letter== title[0])
			{
				MovieNodeLL* currentLL=currentnode->head;
				MovieNodeLL* previousLL=nullptr;
				while(currentLL != nullptr)
				{
					if(title < currentLL->title)
					{
						if(currentLL==currentnode->head)
						{
							newLL->next=currentnode->head;
							currentnode->head=newLL;
							return;
						}
						else
						{
							previousLL->next =newLL;
							previousLL->next->next=currentLL;
							return;
						}
					}
					else if(title > currentLL->title)
					{
						if(currentLL->next==nullptr)
						{
							currentLL->next=newLL;
							return;
						}
						else
						{
							previousLL=currentLL;
							currentLL=currentLL->next;
						}
					}
					else
					{
						currentLL->quantity+= quantity;
						return;
					}
				}
			}
		}

	}
}


void MovieTree::findMovie(std::string title)
{
	MovieNodeBST* BST_loc=searchBST(root,title);
	if(BST_loc !=nullptr)
	{
	    MovieNodeLL* LL_loc=searchLL(BST_loc->head,title);
	    cout<<"Movie Info:"<<endl;
		cout<<"==========="<<endl;
		cout<<"Ranking:"<<LL_loc->ranking<<endl;
		cout<<"Title:"<<LL_loc->title<<endl;
		cout<<"Year:"<<LL_loc->year<<endl;
		cout<<"Quantity:"<<LL_loc->quantity<<endl;
	}
	else if(BST_loc==nullptr)
	{
		cout<<"Movie not found."<<endl;
	}
}

void MovieTree::rentMovie(std::string title)
{
	MovieNodeBST* BST_loc=searchBST(root,title);
	MovieNodeLL* LL_loc=searchLL(BST_loc->head,title);
	if(LL_loc==nullptr)
	{
		cout<<"Movie not found"<<endl;
	}
	else
	{

		LL_loc->quantity=LL_loc->quantity-1;
		if (LL_loc->quantity==0)
		{
			deleteMovieNode(title);
		}
		else
		{
			cout<<"Movie Info:"<<endl;
			cout<<"==========="<<endl;
			cout<<"Ranking:"<<LL_loc->ranking<<endl;
			cout<<"Title:"<<LL_loc->title<<endl;
			cout<<"Year:"<<LL_loc->year<<endl;
			cout<<"Quantity:"<<LL_loc->quantity<<endl;
		}
	}
}

void MovieTree::DeleteAll(MovieNodeBST * node)
{
	if(node->leftChild != nullptr)
	{
		DeleteAll(node->leftChild);
	}
	if(node-> rightChild != nullptr)
	{
		DeleteAll(node->rightChild);
	}
	cout << "Deleting: "<<node->letter<<endl;
	delete node;
}	

void MovieTree::printMovieInventory(MovieNodeBST * node)
{
	if(node->leftChild != nullptr)
	{
		printMovieInventory(node->leftChild);
	}
	MovieNodeLL* currentnode= node->head;
	while(currentnode != nullptr)
	{

		cout<<"Movie:"<< currentnode->title<<" "<<currentnode->quantity<<endl;
		currentnode=currentnode->next;
	}
	
	if(node-> rightChild != nullptr)
	{
		printMovieInventory(node->rightChild);
	}
}

void MovieTree::countMovieNodes(MovieNodeBST *node, int *c)
{
	
	if(node == nullptr && node == root)
	{
		*c=0;
	}
	else if(node->leftChild != nullptr || node->rightChild != nullptr) 
	{
		MovieNodeLL* currentnode=node->head;
		while(currentnode != nullptr)
		{
			*c++;
			currentnode=currentnode ->next;
		}	
		countMovieNodes(node->leftChild,c);
		countMovieNodes(node->rightChild,c);
	}	
}

MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, std::string title)
{
	if(node != nullptr)
	{
		if(title[0] < node->letter && node->leftChild != nullptr)
		{
			return searchBST(node->leftChild, title);
		}
		else if(title[0] > node->letter && node->rightChild != nullptr)
		{
			return searchBST(node->rightChild,title);
		}
		else if(title[0] == node->letter)
		{
			return node;
		}
	}
	else
	{
		return nullptr;
	}
}

MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, std::string title)
{
	bool moviefound=false;
	MovieNodeLL* currentnode=head;
	while(currentnode != nullptr)
	{
		if(currentnode->title == title)
		{
			moviefound=true;
			return currentnode;
		}
		else
		{
			currentnode=currentnode->next;
		}
	}
	if (moviefound==false)
	{
		return nullptr;
	}
}

MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node)
{
	while(node->leftChild != nullptr)
	{
		node=node->leftChild;
	}
	return node;
}

void MovieTree::deleteMovieNode(std::string title)
{
	MovieNodeBST* node=searchBST(root,title);
	MovieNodeLL* LL_loc=searchLL(node->head,title);
	if(LL_loc == nullptr)
	{
		cout<<"Movie not found."<<endl;
	}
	else
	{
		if(node != root)
		{
			if(LL_loc==node->head && LL_loc->next == nullptr)
			{
				if(node->leftChild == nullptr && node->rightChild == nullptr)
				{
				    if(node->letter < node->parent->letter)
				    {
				        node->parent->leftChild=nullptr;
				        delete LL_loc;
	                    delete node;
				        return;
				    }
				    else
				    {
				        node->parent->rightChild=nullptr;
				        delete LL_loc;
	                    delete node;
				        return;
				    }
				}
				else if(node->leftChild != nullptr && node->rightChild == nullptr)
				{
				    if(node->letter < node->parent->letter)
				    {
				        node->parent->leftChild=node->leftChild;
				        delete LL_loc;
	                    delete node;
				        return;
				    }
				    else
				    {
				        node->parent->rightChild=node->leftChild;
				        delete LL_loc;
	                    delete node;
				        return;
				    }
				}
				else if(node->leftChild == nullptr && node->rightChild != nullptr)
				{
				    if(node->letter < node->parent->letter)
				    {
				        node->parent->leftChild=node->rightChild;
				        delete LL_loc;
	                    delete node;
				        return;
				    }
				    else
				    {
				        node->parent->rightChild=node->rightChild;
				        delete LL_loc;
	                    delete node;
				        return;
				    }
				}
				else if(node->leftChild != nullptr && node->rightChild != nullptr)
				{

				       
				        MovieNodeBST* min=treeMinimum(node->rightChild);

				        if(min->letter < node->parent->letter)
				        {
				            node->parent->leftChild=min;
				        }
				        else if(min->letter > node->parent->letter)
				        {   
				            node->parent->rightChild=min;
				        }

				        if(min->parent == node)
				        {
				            min->leftChild=node->leftChild;
				            min->parent=node->parent;
				            delete LL_loc;
	                        delete node;
				            return;
				        }
				        else
				        {
				            min->parent=node->parent;
				            min->leftChild=node->leftChild;
				            node->leftChild->parent=min;
				            min->rightChild=node->rightChild;
				            node->rightChild->parent=min;
				            delete LL_loc;
	                        delete node;
				            return;
				        }
				}
		    }
		    else
		    {
		        if(LL_loc == node->head)
		        {
		           node->head=LL_loc->next;
		           delete LL_loc;
		        }
		        else
		        {
		            MovieNodeLL* currentNode=node->head;
		    
		            while(currentNode->next->title < title)
		            {
		                currentNode=currentNode->next;
		            }
		                currentNode->next=LL_loc->next;
		                delete LL_loc; 
		                return;
		        }
		    }
		}
		else
		{
			if(node->leftChild == nullptr && node->rightChild == nullptr)
			{
				root =nullptr;
				delete node;
				delete LL_loc;
			}
			else if(node->leftChild != nullptr && node->rightChild == nullptr)
			{
				root= node->leftChild;
				node->leftChild->parent=nullptr;
				delete node;
				delete LL_loc;
			}
			else if(node->leftChild == nullptr && node->rightChild != nullptr)
			{
				root= node->rightChild;
				node->rightChild->parent=nullptr;
				delete node;
				delete LL_loc;
			}
			else if(node->leftChild != nullptr && node->rightChild != nullptr)
			{
				MovieNodeBST* min=treeMinimum(node->rightChild);
				if(min->parent == node)
				{
					min->parent->leftChild=nullptr;
					min->parent=nullptr;
					min->leftChild=node->leftChild;
					min->leftChild->parent=min;
					root=min;
					delete node;
					delete LL_loc;
					return;
				}
				else
				{
					min->parent->leftChild=nullptr;
					min->parent=nullptr;
					min->leftChild=node->leftChild;
					min->rightChild=node->rightChild;
					node->rightChild->parent=min;
					root=min;
					delete node;
					delete LL_loc;
					return; 

				}
			}
			else
			{
				 if(LL_loc == node->head)
		        {
		           node->head=LL_loc->next;
		           delete LL_loc;
		        }
		        else
		        {
		            MovieNodeLL* currentNode=node->head;
		    
		            while(currentNode->next->title < title)
		            {
		                currentNode=currentNode->next;
		            }
		                currentNode->next=LL_loc->next;
		                delete LL_loc; 
		                return;
		        }
			}
		}
	}
}

MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node)
{
	while(node->leftChild != nullptr)
	{
		node=node->leftChild;
	}
	return node;
}