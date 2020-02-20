#include <iostream>
#include "BST.h"
using namespace std;
/**
Create a node with key as data
**/
node* BST:: createNode(int data,node* parent)
{
    node* nn = new node;
    nn->key = data;
    nn->left = nullptr;
    nn->right = nullptr;
    nn->parent = parent;
    return nn;
}

BST::BST()
{

}
/**
parameterized constructor. It will create the root and put the data in the root.
**/
BST::BST(int data)
{
    root = createNode(data,nullptr);
}
/**
Destructor
**/
 BST::~BST(){

     destroyNode(root);

 }
/**
This function will destroy the subtree rooted at curNode.
Think about in what order should you destroy.
**/
 void BST:: destroyNode(node *curNode){
     if(root)
     {
        // destroyNode(root->left);
        // destroyNode(root->right);
         delete root;
         root = nullptr;
     }
 }

/** This function will search the data in a tree rooted at root
    We will call this function from searchKey.
    NOTE: As root is a private member of BST class, main function can not access root.
    So we need this helper function.
**/
 bool BST::searchKeyHelper(node* root, int data)
 {
     //TODO: Implement your searching function here.
     // Function will return true if the data is there. Else it will return false.
    if(data<root->key && root->left != nullptr)
    {
        return searchKeyHelper(root->left,data);
    }
    else if(data>root->key && root->right != nullptr)
    {
        return searchKeyHelper(root->right, data);
    }
    else if(root ->key == data)
    {
        cout<<"found"<<endl;
        return true;
    }
    else
    {
        cout<<"not found"<<endl;
        return false; 
    }
 }
/**
This function will search the data in the tree
**/
bool BST::searchKey(int data){
    return searchKeyHelper(root, data);
}

/**
This function will add the data in the tree rooted at curNode.
We will call this function from insertNode.
NOTE: root is a private member of BST. As root is a private member of BST class, main function can not access root.
      So we need this helper function. Implement your code for inserting a node in this function.
**/
 node* BST:: insertNodeHelper(node* curNode, int data){
     //TODO: Implement the code for insert a node at the tree rooted at curNode.
    node* tmpNode=root;
    node* curParent=nullptr;
    while(tmpNode != nullptr)
    {
        curParent=tmpNode;
        if(data < tmpNode->key)
        {
            tmpNode=tmpNode->left;
        }
        else
        {
            tmpNode=tmpNode->right;
        }
        
    }
    if(curNode->key>data)
    {
        curParent->left=createNode(data,curParent);
        cout<<"item: "<<data<<" added to left of "<<curParent->key<<endl;
    }
    else
    {   
        curParent->right=createNode(data,curParent);
        cout<<"item: "<<data<<" added to right of "<<curParent->key<<endl;
    }

 }

/**
This function will insert the data in the tree. As this function can not access the root
it will call the insertNodeHelper function.
**/
void BST:: insertNode( int data){
    if(root == nullptr) 
    {
    // if the BST is empty create the root
        root = createNode(data,nullptr);
        cout<<"item: "<<data<<" is the root"<<endl;
    }
    else // insert the data in the tree rooted at root
        insertNodeHelper(root, data);
}

/** This function will traverse the tree in-order and print out the node elements.
printTree() function will call this function.
NOTE: As root is a private member of BST class, main function can not access root. So printTree will
call this helper function.
**/
 void BST:: printTreeHelper(node* curNode){
     if(curNode)
     {
            printTreeHelper( curNode->left);
            cout << " "<< curNode->key;
            printTreeHelper( curNode->right);
     }
 }

 void BST:: printTree(){
     printTreeHelper(root);
 }

int main()
{
    BST tree;
    tree.insertNode(5);
    tree.insertNode(6);
    tree.insertNode(4);
    tree.printTree();
    tree.searchKey(4);
}
 //pre-order root->left->right
 //in order left->root->right //arrange in incremental order 
 //post order left->right->root
