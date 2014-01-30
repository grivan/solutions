//LinkedList implementatoin of Trees and common functions

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}	tree;

typedef struct node2{
	int data;	
	struct node2 *next;
} LL;

typedef struct node3{
	tree *leaf;
	struct node3 *next;
}	treeLL;

tree *insert(tree *top, int key)
{
	if(top==NULL)
	{
		tree *newnode=malloc(sizeof(tree));
		newnode->right=NULL;
		newnode->left=NULL;
		newnode->data=key;
		return(newnode);
	}
	else if(key<=top->data) top->left=insert(top->left,key);
	else if(key>top->data) top->right=insert(top->right,key);
	return(top);
}

void printinorder(tree *top)
{
	if(top==NULL) return;
	printinorder(top->left);
	printf("%d ",top->data);
	printinorder(top->right);
}

int depth(tree *top)
{
	if(top==NULL) return(0);
	int h1=0,h2=0;
	if(top->left) h1=depth(top->left);
	if(top->right) h2=depth(top->right);
	return(h1>=h2?h1+1:h2+1);
}

int size(tree *top)
{
	if(top==NULL) return(0);
	return(size(top->left)+size(top->right)+1);
}

void delete(tree *top)
{
	if(top==NULL) return;
	delete(top->left);
	delete(top->right);
	free(top);
}

tree *copy(tree *top)
{
	if(top==NULL) return(NULL);
	tree *top2=malloc(sizeof(tree));
	top2->data=top->data;
	top2->left=copy(top->left); top2->right=copy(top->right);
	return(top2);
}

int identical(tree *top,tree *top2)
{
	if(top==NULL && top2==NULL) return(1);
	else if(top!=NULL && top2!=NULL)
	return(top->data == top2->data && identical(top->left,top->left) && identical(top->right,top2->right));
	else return(0);
}

tree *ptrNthInOdr(tree *top,int n)
{
//TODO	
}

void InOdrLL(tree *top,LL **start)
{
	if(top==NULL) return;
	InOdrLL(top->left,start);
	LL *temp=*start;
	while(temp->next!=NULL) temp=temp->next;
	temp->next=malloc(sizeof(LL));
	temp->data=top->data;
	InOdrLL(top->right,start);
}

void EnQtreeLL(treeLL **start,tree *top)
{
	treeLL *temp=malloc(sizeof(treeLL));
	temp->leaf=top;
	temp->next=(*start);
	(*start)=temp;
	printf("\nEnQed: %d",top->data);
}

tree *DeQtreeLL(treeLL **start)
{
	if((*start)==NULL) return;
	treeLL temp=*start;
	while(temp->next!=NULL) temp=temp->next;
	tree *temp2=temp->data;
	printf("\nDeQed: %d",temp2->data);
	return(temp);
}

void LevOdr(tree *top,treeLL **start)
{
	treeLL *temp=NULL;
	EnQtreeLL(&temp,top);
	while(temp!=NULL)
	{
		top=DeQtreeLL(&temp);
		printf("\nVisited: %d",(top->data));
		if(top->left) EnQtreeLL(&temp,top->left);
		if(top->right) EnQtreeLL(&temp,top->right);
	}	
}

void printLL(LL *list)
{
	if(list==NULL) return;
	printf("%d ",list->data);
	printLL(list->next);
}

void main()
{
	tree *top=NULL;
  top=insert(top,8);
	top=insert(top,3);
	top=insert(top,1);
	top=insert(top,6);
	top=insert(top,4);
	top=insert(top,7);
	top=insert(top,10);
	top=insert(top,14);
	top=insert(top,13);
	//printinorder(top);
	//printf("\nThe Depth is : %d\n",depth(top));
	//printf("The size is: %d\n",size(top));
	//delete(top);	
	//tree *top2=NULL;
	//top2=copy(top);
	//printinorder(top2);
	//printf("\n%d\n",identical(top,top2));
	//printf("\n%d\n",ptrNthInOdr(top,4)->data);
	//LL *myLL=malloc(sizeof(LL));
	//InOdrLL(top,&myLL);
	//printf("\n");
	//printLL(myLL);
	//printf("\n");
	treeLL *myLL2=malloc(sizeof(treeLL));
	printf("\n");
	LevOdr(top,&myLL2);
	printf("\n");
}
