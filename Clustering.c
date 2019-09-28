#include<stdio.h>

#define MAX 100  
 
#define initial 1
#define waiting 2
#define visited 3
int state[MAX];
int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();
int Closeness(int a[8][8],int n,int l);
void Cluster(int a[8][8],int centrality[8],int v,int n);
int count=0;

int main()
{
	int a[8][8],n,i,j,c,l,v;
	
    

	printf("Enter the size of matrix:");
	scanf("%d",&n);
	int centrality[n+1];
	printf("Enter the adjacency matrix\n:");
	
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
	
            for(v=0; v<n; v++) 
        state[v] = initial;
	for(i=0;i<n;i++)
	{
		centrality[i+1] = Closeness(a,n,i+1);
        
	}	
	
	printf("\n***********************************************\n");
	printf("\nCentrality of nodes is as follows :\n");
	for(i=0;i<n;i++)
	{
		printf("\nNode (%d) : %d \n",i,centrality[i+1]);
	}
	
	
	printf("\n***********************************************\n");
	printf("\nClusters are as follows:\n");
	for(i=0;i<n;i++)
	{
		if(state[i]!=visited)
			Cluster(a,centrality,i,n);
	
	}
	

	
	return 0;
}


void insert_queue(int vertex)
{
    if(rear == MAX-1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1) 
            front = 0;
        rear = rear+1;
        queue[rear] = vertex ;
    }
}
 
int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}
 
int delete_queue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    
    delete_item = queue[front];
    front = front+1;
    return delete_item;
}
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
void Cluster(int adj[8][8],int centrality[8],int v,int n)
{
    int i;
    int cen=centrality[v+1];
    count++;
    insert_queue(v);
    state[v] = waiting;
    printf("\nCluster (%d)  :",count);
    while(!isEmpty_queue())
    {
        v = delete_queue( );
        printf("%d ",v);
        state[v] = visited;
        
        for(i=0; i<n; i++)
        {
            
            
            if(adj[v][i] >= 1 && state[i] == initial && centrality[i+1]==cen) 
            {
            	
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}

