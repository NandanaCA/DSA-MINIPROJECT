#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define MAX 1000
#define inf 1e9

int graph[MAX][MAX];
int output1[MAX];
int output2[MAX][MAX];

void input_graph(int n, FILE* fp)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            graph[i][j]=inf;
            if(i==j)
            graph[i][j]=0;
        }
    }
    while(1)
    {
        int i,j,w;
        fscanf(fp,"%d%d%d",&i,&j,&w);
        if (i<0 || j<0 || i>=n || j>=n)
        break;
        graph[i][j]=w;
    }
}

void display(int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(graph[i][j]==inf)
            printf("INF\t");
            else
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void display_output1(int n,int f)
{
    if (f==1)
    printf("Dijkstra\n");
    else if (f==2)
    printf("Bellman-Ford\n");
    else
    printf("BFS\n");
    printf("Shortest distance from source node are:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",output1[i]);
    }
    printf("\n");
}

void display_output2(int n)
{
    printf("Floyd-Warsahll\n");
    printf("Shortest distances between every pair of vertices\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
         {
            if (output2[i][j] == inf)
            {
                printf("INF\t");
            } 
            else 
            {
                printf("%d\t", output2[i][j]);
            }
        }
        printf("\n");
    }
}

int mindist(bool* used,int* distance,int n)
{
    int m=inf;
    int ret=-1;
    for(int i=0;i<n;i++)
    {
        if(distance[i]<m && used[i]==0)
        ret=i;
    }
    return ret;
}


void dijkstra(int n,int start)
{
int distance[MAX];
    int visited[MAX]={0};

    for(int i=0;i<n;i++)
    {
        distance[i]=inf;
    }
    distance[start]=0;
    bool used[MAX]={0};

    while(1)
    {
        int curr=-1;
        curr=mindist(used,distance,n);
        if (curr==-1)
        break;
        used[curr]=1;
        for(int i=0;i<n;i++)
        {
            if(distance[curr]+graph[curr][i]<distance[i])
            distance[i]=distance[curr]+graph[curr][i];
        }
    }
    
    
    for(int i=0;i<n;i++)
    {
        output1[i]=distance[i];
    }
}

void floyd_warshall(int n) 
{
    int dist[n][n];
    int i, j, k;

   
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < n; k++)
     {  
        for (i = 0; i < n; i++) 
        { 
            for (j = 0; j < n; j++) 
            {
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    
    
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++)
        {    
        output2[i][j]=dist[i][j];     
        }
    }
}

void relax(int u, int v, int w, int dist[], int prev[]) {
	if (dist[v] > dist[u] + w) {
		dist[v] = dist[u] + w;
		prev[v] = u;
	}
}

void bellman_ford(int n,int src) {
	// Initialize the distance to the source vertex as 0

	int dist[MAX] = {0};
	for (int i = 0; i < n; i++) dist[i] = inf;
	int prev[MAX] = {0};
	dist[src] = 0;

	// Relax all the edges in the graph V-1 times
	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				if (graph[u][v] != inf) {
					relax(u, v, graph[u][v], dist, prev);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		output1[i]=dist[i];
	}
}

void bfs(int n,int v)
{
    int level[n];
    int visit[MAX]={0};
    int q[MAX],f=0,r=-1;
    visit[v]=1;
    level[v]=0;
    q[++r]=v;
    while(f<=r)
        {
            v=q[f++];
            for(int u=0;u<n;u++)
            {
                if(graph[v][u]==1 )
                {
                    if(visit[u]==0)
                    {
                        q[++r]=u;
                        visit[u]=1;
                        level[u]=level[v]+1;
                    }
                }
                
            }
        }
        for(int i=0;i<n;i++)
        {
           output1[i]=level[i];
        }
}



void timing_weighted_graph(int n,int src)
{
    float time[3];
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    dijkstra(n,src);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time[0]=cpu_time_used;

    start = clock();
    bellman_ford(n,src);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time[1]=cpu_time_used;

    start = clock();
    floyd_warshall(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time[2]=cpu_time_used;

    printf("\ndijkstra---> %0.10f",time[0]);
    printf("\nbellman-ford---> %0.10f",time[1]);
    printf("\nfloyd-warshall---> %0.10f",time[2]);

}

void timing_unweighted_graph(int n,int src)
{
    float time[4];
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    dijkstra(n,src);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time[0]=cpu_time_used;

    start = clock();
    bellman_ford(n,src);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time[1]=cpu_time_used;

    start = clock();
    floyd_warshall(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time[2]=cpu_time_used;

    start = clock();
    bfs(n,src);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time[3]=cpu_time_used;

    printf("\ndijkstra---> %0.10f",time[0]);
    printf("\nbellman-ford---> %0.10f",time[1]);
    printf("\nfloyd-warshall---> %0.10f",time[2]);
    printf("\nbfs---> %0.10f",time[3]);

}


int main()
{
    int choice,n,start;
    FILE* fp;
    char filename[10];
    printf("enter file name:\n");
    scanf("%s",&filename);
    fp = fopen(filename, "r+");

    fscanf(fp,"%d",&n);
    printf("%d\n", n);
    input_graph(n, fp);

    while(1)
    {
        fscanf(fp,"%d",&choice);
        switch(choice)
        {
            case 1:
            display(n);
            break;

            case 2:
            fscanf(fp,"%d",&start);
            dijkstra(n,start);
            display_output1(n,1);
            break;

            case 3:
            fscanf(fp,"%d",&start);
            bellman_ford(n,start);
            display_output1(n,2);
            break;

            case 4:
            floyd_warshall(n);
            display_output2(n);
            break;

            case 5:
            fscanf(fp,"%d",&start);
            bfs(n,start);
            display_output1(n,3);
            break;

            case 6:
            fscanf(fp,"%d",&start);
            timing_unweighted_graph(n,start);
            break;

            case 7:
            fscanf(fp,"%d",&start);
            timing_weighted_graph(n,start);
            break;
           
            default:
            exit(0);

        }
    }
    
}