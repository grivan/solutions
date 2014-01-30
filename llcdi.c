//LinkedList implementation and common functions in C 

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}	LL;

LL *reverse(LL *current,LL *next)
{
	if (current==NULL)
		return NULL;
	
	LL *temp=NULL;
	if (current ->next !=NULL)
		temp = reverse(current->next,current);
	else
		temp=current;

	current->next = next;
	return temp;
}

LL *add(LL **node, int val)
{
	if (node==NULL)
		return NULL;

	LL *temp=malloc(sizeof(LL));
	if (temp==NULL)
		return NULL;

	temp->next=*node;
	*node=temp;
	temp->data=val;

	return *node;
}

LL *printlist(LL *node)
{
	if (node==NULL)
		{ printf("Empty\n"); return;}
	printf("\n");
	while(node!=NULL)
	{
		printf("%p %p %d \n",node,node->next,node->data);
		node=node->next;
	}
	printf("\n");
}

void delete(LL *node)
{
	node->data=node->next->data;
	node->next=node->next->next;
	free(node->next);
}

LL *checkloop(LL *head)
{
	LL *tortoise=head;
	LL *hare=head->next;
	
	while(tortoise!=NULL && hare!=NULL)
	{
		if(tortoise==hare)
			{
				printf("FOUND A LOOP\n");
				return tortoise;
			}
	tortoise=tortoise->next;
	hare=(hare->next)?(hare->next->next):hare->next;
	}
}

LL *onebynth(LL *head,int n)
{
		LL* nthll=NULL;
		int i;	
		for(i=1;head;head=head->next,i++)
		{
			if(i==1)
				nthll=head;
			else if (i%n==1)
				nthll=nthll->next;
		}
		
	printf("The 1/%d element is %d \n",n,nthll->data);
}

copy(LL *ori,LL **cop)
{
	if(ori!=NULL)
	{
		*cop=malloc(sizeof(LL));
		(*cop)->data=ori->data;
		(*cop)->next=NULL;
		copy(ori->next,&((*cop)->next));
	}
}

int compare(LL *head1,LL *head2)
{
	while(head1!=NULL && head2!=NULL)
	{
		if (head1->data!=head2->data)
			{
				printf("Not Equal\n");
				return(0);
			}
		head1=head1->next;
		head2=head2->next;
	}
	printf("Equal\n");
	return(0);
}

LLfree(LL **head)
{
	LL *temp;
	for(temp=*head;temp!=NULL;temp=temp->next,(*head)=(*head)->next)
	{
		(*head)->next=NULL;
	}	
}

nthfromend(LL *head,int n)
{
	LL *ptr1=head;
	LL *ptr2=head;
	int i;

	for(i=0;i<=n;i++)
		ptr1=ptr1->next;

	while(ptr1!=NULL)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	printf("The %dth element from end is %d\n",n,ptr2->data);
}
int main()
{
	LL *head = malloc(sizeof(LL));
	add(&head,1);
	add(&head,2);
	add(&head,3);
	add(&head,4);
	add(&head,5);
	add(&head,6);
	add(&head,7);
	printlist(head);
	//onebynth(head,2);
	//onebynth(head,3);
	//onebynth(head,4);
	//head->next->next->next=head;
	//delete(head->next->next->next);
	//head = reverse(head,(LL *)0);
	//checkloop(head);
	//LL *head2=malloc(sizeof(LL));
	//copy(head,&head2);
	//compare(head,head2);
	//LLfree(&head);
	//nthfromend(head,4);
	printlist(head);	
}
