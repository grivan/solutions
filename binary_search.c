//A simple binary search implementaion in C

#include<stdio.h>

int binarySearchRecur(int key,int* list, int low, int high)
{
	if(high<low)
		return(-1);
	int mid=low+(high-low)/2;
	if(list[mid]>key)
		binarySearchRecur(key,list,low,mid-1);
	else if(list[mid]<key)
		binarySearchRecur(key,list,mid+1,high);
	else
		return(1);
}
int binarySearch(int key,int* list,int len)
{
	int low=0,high=len-1,flag=0;
	flag=binarySearchRecur(key,list,low,high);
	return(flag);
}
int main()
{
	int list[12]={1,2,3,4,5,6,7,8,9,10,11,12};
	int flag=0;
	flag = binarySearch(8,list,12);
	printf("%d \n",flag);
}
	
