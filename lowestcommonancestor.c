//lowest common ancestor in a binary tree

#include<stdio.h>
#include<stdlib.h>

typedef struct mynode {
  struct mynode* left;
  struct mynode* right;
  struct mynode* parent;
  int data;
} tn;

int getlength(tn* node) {
  if(node->parent==NULL) return 1;
  int height=1+getlength(node->parent);
  return(height);
}

tn* getancestor(tn* first,int lenfirst,tn* second,int lensecond) {
  //first jump up the difference on longer one
  //assuming the second to be longer, can be taken care while passing the param to this function
  //not checking if the ancestor does not exist, but then it should be the root node
  int diff=lensecond-lenfirst;
  int i=0;
  for(;i<diff;i++) 
  {
    second=second->parent;
  }
  while(first!=second)
  {
    first=first->parent;
    second=second->parent;
  }
  return(first);
}

int main() {
  //due to less time i did not create seperate init functions! sorry!
  //so all the tree construction goes here
  tn *head=malloc(sizeof(tn));
  head->parent=NULL;
  head->data=10;
  head->right=malloc(sizeof(tn));
  head->right->parent=head;
  head->right->data=9;
  head->right->left=malloc(sizeof(tn));
  head->right->left->parent=head->right;
  head->right->left->data=19;
  head->left=malloc(sizeof(tn));
  head->left->parent=head;
  head->left->data=8;
  head->right->right=malloc(sizeof(tn));
  head->right->right->parent=head->right;
  head->right->right->data=7;
  tn* temp=getancestor(head->left,getlength(head->left),head->right->right,getlength(head->right->right));
  printf("Data at Common Ancestor:%d\n",temp->data); //ans should be root = 10
  temp=getancestor(head->right->left,getlength(head->right->left),head->right->right,getlength(head->right->right));
  printf("Data at Common Ancestor:%d\n",temp->data); //ans should be head->right = 9
}
