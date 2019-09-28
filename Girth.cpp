#include <stdio.h>
#include <limits.h>
#define V 9
int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
   return min_index;
}
int dijkstra(int graph[V][V], int src, int t)
{
     int dist[V];     
     bool sptSet[V];
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
     dist[src] = 0;
     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);
       sptSet[u] = true;
       for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
	return dist[t];
}
  
int main()
{
	int n,girth=INT_MAX,i,j,k,l;
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  for(i=0;i<V;i++)
	  for(j=i;j<V;j++)
	  {
		  if(graph[i][j]>0)
		  {
			  k=graph[i][j];
			  graph[i][j]=graph[j][i]=0;
			  l=dijkstra(graph,i,j);
			  if(l!=0)
			  {
				  if((l+1)<girth)
					  girth=l+1;
			  }
			  graph[i][j]=graph[j][i]=k;
		  }
	  }
  
  printf("The Girth of the Graph is: %d",girth);
    return 0;
}