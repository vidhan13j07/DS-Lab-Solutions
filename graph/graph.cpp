#include<bits/stdc++.h>
using namespace std;
void reach(int n,int **adj,int *vis,int k)
{
    if(vis[k])
    	return ;
    vis[k]=1;
    int i;
    for(i=0;i<n;i++)
        if(adj[k][i])
            reach(n,adj,vis,i);
}
int main()
{
    int n,e,q,a,b;
    printf("\nEnter the number of nodes\n");
    scanf("%d",&n);
    int vis[n];
    int **adj;
    adj=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    	adj[i]=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=0;
    printf("\nEnter the number of edges:\n");
    scanf("%d",&e);
    while(e--)
    {
        printf("\nEnter the nodes in which an edge exists\n");
        scanf("%d %d",&a,&b);
        a--;
        b--;
        adj[a][b]=1;
    }
    printf("\nEnter the number of queries\n");
    scanf("%d",&q);
    while(q--)
    {
        for(int i=0;i<n;i++)
            vis[i]=0;
        printf("\nEnter the starting node\n");
        scanf("%d",&a);
        printf("\nEnter the ending node\n");
        scanf("%d",&b);
        a--;
        b--;
        reach(n,adj,vis,a);
        if(vis[b])
            printf("\nThe path exists\n");
        else
            printf("\nThe path does not exist\n");
    }
    return 0;
}
