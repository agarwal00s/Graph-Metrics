#include<stdio.h>
int Closeness(int a[8][8] , int n , int l)
{
	int count = 0 , j , sum=0 , avg;
		
		for(j = 0 ;j < n ;j ++)
			{
			if((a[l-1][j] != 0) && (a[l-1][j] != 9999)) //here i considered 9999 as infinity(incase if we use directional graph)
			{
				sum = sum + a[l-1][j] ;
				count++;
			}
		}
		avg = sum / count;
return avg;	
}

void main()
{
	int a[8][8],n,i,j,c,l;
	printf("Enter the size of matrix");
	scanf("%d",&n);
	printf("Enter the graph");
	
	for(i=0;i<n;i++)
	{
		
		for(j=0 ;j < n;j++)
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
	

c = Closeness(a,n,l);
printf(" Closeness centrality of %dth node is %3d",l,c);
	
	
}
