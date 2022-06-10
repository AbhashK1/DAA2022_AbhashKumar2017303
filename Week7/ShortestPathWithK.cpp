#include<iostream>
#include<vector>
#include<climits>
#define INF INT_MAX
using namespace std;
vector<vector<int>> adjMatrix;
int minimum(int a, int b) 
{
   return (a<b)?a:b;
}
int shortestPath(int u,int v,int edge,int V)
{
    if(edge==0 && u==v)
        return 0;
    if(edge==1 && adjMatrix[u][v]!=INF)
        return adjMatrix[u][v];
    if(edge<=0)
        return INF;
    int shortPath=INF;

    for(int i=0;i<V;i++)
    {
        if(adjMatrix[u][i]!=INF && u!=i && v!=i)
        {
            int tempRes=shortestPath(i,v,edge-1,V);
            if(tempRes!=INF)
                shortPath=minimum(shortPath,adjMatrix[u][i]+tempRes);
        }
    }
    return shortPath;
}
int main()
{
    int V;
    cin>>V;
    adjMatrix = vector<vector<int>>(V,vector<int>(V,0));
    int E=0;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin>>adjMatrix[i][j];
            if(i!=j && adjMatrix[i][j]==0)
                adjMatrix[i][j]=INF;
            E++;
        }
    }

    int src,dest;
    cin>>src>>dest;
    int k;
    cin>>k;
    cout<<"Weight of Shortest Path: "<<shortestPath(src,dest,k,V);
}
/*Test
4
0 10 3 2
0 0 0 7
0 0 0 6
0 0 0 0
0 3
2*/
