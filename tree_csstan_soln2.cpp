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
struct node* insert(struct node* node,int key)
{
	if(node==NULL) return(newNode(key));
	else if(key<=node->key) node->left=insert(node->left,key);
	else if(key>node->key) node->right=insert(node->right,key);
	return(node);
}
int size(struct node* node)
{
	if(node==NULL)
		return(0);
	else return(size(node->left)+1+size(node->right));
}
int maxDepth(struct node* node)
{
	int ldepth,rdepth;
	if(node==NULL)
		return(0);
	else
	{
		ldepth=maxDepth(node->left);
		rdepth=maxDepth(node->right);
	}
	if(ldepth>rdepth)
		return(ldepth+1);
	else
		return(rdepth+1);	
}

int minValue(struct node* node)
{
	struct node* current=node;
	while(current->left!=NULL)
		current=current->left;
	return(current->key);
}
void printTree(struct node* node)
{
	if(node==NULL) return;
	printTree(node->left);
	cout<<node->key<<endl;
	printTree(node->right);
}
void printPost(struct node* node)
{
	if(node==NULL) return;
	printPost(node->left);
	printPost(node->right);
	cout<<node->key<<endl;
}
bool hasPathSum(struct node* node,int sum)
{	
	if(node==NULL)
		return(sum==0);
	else
	{
		int subsum=sum-node->key;
		return(hasPathSum(node->left,subsum) or hasPathSum(node->right,subsum));
	}	
}
void printPathArray(int path[],int pathLen)
{
	for(int i=0;i<=pathLen;i++) cout<<path[i];
	cout<<endl;
}
void printPathRecur(struct node* node,int path[], int pathLen)
{
	if(node==NULL) return;
	
	path[pathLen]=node->key;
	pathLen++;
	
	if((node->left==NULL) and (node->right==NULL))
	printPathArray(path,pathLen);
	else
	{
		printPathRecur(node->left,path,pathLen);
		printPathRecur(node->right,path,pathLen);
	}
}
void printPaths(struct node* node)
{
	int path[1000];
	printPathRecur(node, path, 0);
}
void mirror(struct node* node)
{
	if(node==NULL) return;
	else
	{
		mirror(node->left);
		mirror(node->right);		
		struct node* temp=NULL;
		temp=node->left;
		node->left=node->right;
		node->right=temp;
	}
}	
void doubleTree(struct node* node)
{
	if(node==NULL) return;
	else
	{
		doubleTree(node->left);
		doubleTree(node->right);
		struct node* temp=NULL;
		temp=newNode(node->key);
		temp->left=node->left;
		node->left=temp;
	}
}
bool sameTree(struct node* node1, struct node* node2)
{
	if(node1==NULL and node2==NULL)	return(true);
	if(node1!=NULL and node2!=NULL) 
	return(node1->key==node2->key and sameTree(node1->left,node2->left) and sameTree(node1->right,node2->right));
	else return(0);
}
int main()
{
	struct node* tree=NULL;
	tree=insert(tree,4);
	tree=insert(tree,2);
	tree=insert(tree,5);
	tree=insert(tree,1);
	tree=insert(tree,3);
	struct node* tree1=NULL;
	tree1=insert(tree,4);
	tree1=insert(tree,2);
	tree1=insert(tree,5);
	tree1=insert(tree,1);
	tree1=insert(tree,3);
	cout<<sameTree(tree,tree1)<<endl<<endl<<endl;
	int sizetree,maxdepth,minvalue;
	sizetree = size(tree);
	maxdepth = maxDepth(tree);
	minvalue = minValue(tree);
	cout<<sizetree<<endl<<maxdepth<<endl<<minvalue<<endl<<endl;
	printTree(tree);
	cout<<endl;
	printPost(tree);
	bool hassum=hasPathSum(tree,45);
	cout<<endl<<hassum<<endl<<endl;
	printPaths(tree);
	cout<<endl;
	mirror(tree);
	printTree(tree);
	cout<<endl;
	doubleTree(tree);
	printTree(tree);
}
