#include<iostream>

using namespace std;

struct node
{
	int key;
	node* left;
	node* right;
};

struct node* newNode(int key)
{
	struct node* node=new(struct node);
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	return(node);
}
struct node* build123a()
{
	struct node* root=newNode(2);
	struct node* rootl=newNode(1);
	struct node* rootr=newNode(3);
	
	root->left=rootl;
	root->right=rootr;	
	return(root);
}
struct node* build123b()
{
	struct node* root=newNode(2);
	root->left=newNode(1);
	root->right=newNode(3);
	return(root);
}
struct node* insert(struct node* node, int key)
{	
	if(node==NULL)
		return(newNode(5));
	else
	{
		if(key<=node->key) node->left=insert(node->left,key);
		else node->right=insert(node->right,key);
		return(node);
	}
}	
struct node* build123c()
{
	struct node* node;
	node=insert(node,2);
	node=insert(node,4);
	node=insert(node,1);
	return(node);
}
int lookup(struct node* node,int key)
{
	if(node==NULL)return(false);
	else if(key==node->key)return(true);
	else if(key<node->key) return(lookup(node->left,key));
	else if(key>node->key) return(lookup(node->right,key));
}
int main()
{
	struct node* tree;
	struct node* tree2;
	struct node* tree3;
	tree=build123a();
	tree2=build123b();
	tree3=build123c();
	cout<<lookup(tree,42)<<endl;
	cout<<lookup(tree2,62)<<endl;
	cout<<lookup(tree3,1)<<endl;
	return(0);
}
