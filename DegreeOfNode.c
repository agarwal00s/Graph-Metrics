#include<stdio.h>
int Degree(int a[8][8] , int n , int l)
{
	int count = 0 ,j;
		for(j=0;j<n;j++)
	{
		if(a[l-1][j] != 0)
		count++;
	}
return count;	
}

void main()
{
	int a[8][8],n,i,j,c,l;
	printf("Enter the size of matrix");
	scanf("%d",&n);
	printf("Enter the graph");
	
	for(i=0;i<n;i++)
	{
		
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	
		for(i=0;i<n;i++)
	{
		
		for(j=0;j<n;j++)
		printf("\t%d",a[i][j]);
		printf("\n");
	}
	
	printf("Enter the node");
	scanf("%d",&l);
	

c=Degree(a,n,l);
printf("Degre of %dth node is %3d",l,c);
	
	
}
